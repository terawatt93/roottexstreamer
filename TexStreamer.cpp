// @(#)root/postscript:$Id$
// Author: Olivier Couet

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifdef WIN32
#pragma optimize("",off)
#endif

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>

#include "TCanvas.h"
#include "TROOT.h"
#include "TColor.h"
#include "TVirtualPad.h"
#include "TPoints.h"
#include "TexStreamer.hh"
#include "TStyle.h"
#include "TMath.h"
#include "TString.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

ClassImp(TexStreamer);

/** \class TexStreamer
\ingroup PS

\brief Interface to TeX.

This class allow to generate <b>PGF/TikZ</b> vector graphics output
which can be included in TeX and LaTeX documents.

PGF is a TeX macro package for generating graphics. It is platform
and format-independent and works together with the most important TeX
backend drivers, including pdftex and dvips. It comes with a
user-friendly syntax layer called TikZ.

To generate a such file it is enough to do:
~~~ {.cpp}
   gStyle->SetPaperSize(10.,10.);
   hpx->Draw();
   gPad->Print("hpx.tex");
~~~

Then, the generated file (`hpx.tex`) can be included in a
LaTeX document (`simple.tex`) in the following way:
~~~ {.cpp}
\documentclass{article}
\usepackage{tikz}
\usetikzlibrary{patterns}
\usetikzlibrary{plotmarks}
\title{A simple LaTeX example}
\date{July 2013}
\begin{document}
\maketitle
The following image as been generated using the TexStreamer class:
\par
\input{hpx.tex}
\end{document}
~~~

Note the three directives needed at the top of the LaTeX file:
~~~ {.cpp}
\usepackage{tikz}
\usetikzlibrary{patterns}
\usetikzlibrary{plotmarks}
~~~

Then including the picture in the document is done with the
`\input` directive.

 The command `pdflatex simple.tex` will generate the
corresponding pdf file `simple.pdf`.
*/

////////////////////////////////////////////////////////////////////////////////
/// Default TeX constructor


void TexStreamer::PrintStrTex(const char *str)
{
	if (!str || !str[0])
		return;
	Int_t len = strlen(str);
	if(len>0)
	{
		if (str[0] == '@')
		{
			Buff<<string(str).substr(1,len-1)<<"\n";
		}
		else if (str[len-1] == '@')
		{
			Buff<<string(str).substr(0,len-1)<<"\n";
		}
		else
		{
			Buff<<string(str);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
/// Fast version of Print

void TexStreamer::PrintFastTex(Int_t len, const char *str)
{
	Buff<<string(str);
}


////////////////////////////////////////////////////////////////////////////////
/// Write one Integer to the file
///
/// n: Integer to be written in the file.
/// space: If TRUE, a space in written before the integer.

void TexStreamer::WriteIntegerTex(Int_t n, Bool_t space )
{
   char str[15];
   if (space) {
	  snprintf(str,15," %d", n);
   } else {
	  snprintf(str,15,"%d", n);
   }
   PrintStrTex(str);
}


////////////////////////////////////////////////////////////////////////////////
/// Write a Real number to the file

void TexStreamer::WriteRealTex(Float_t z, Bool_t space)
{
   char str[15];
   if (space) {
	  snprintf(str,15," %g", z);
   } else {
	  snprintf(str,15,"%g", z);
   }
   PrintStrTex(str);
}



TexStreamer::TexStreamer() : TVirtualPS()
{
   fStream       = nullptr;
   fType         = 0;
   gVirtualPS    = this;
   fBoundingBox  = kFALSE;
   fRange        = kFALSE;
   fXsize        = 0.;
   fYsize        = 0.;
   fCurrentRed   = -1.;
   fCurrentGreen = -1.;
   fCurrentBlue  = -1.;
   fCurrentAlpha = 1.;
   fLineScale    = 0.;
}

////////////////////////////////////////////////////////////////////////////////
/// Initialize the TeX interface
///
///  --fname : TeX file name
///  - wtype : TeX workstation type. Not used in the TeX driver. But as TexStreamer
///            inherits from TVirtualPS it should be kept. Anyway it is not
///            necessary to specify this parameter at creation time because it
///            has a default value (which is ignore in the TeX case).

TexStreamer::TexStreamer(const char *fname, Int_t wtype) : TVirtualPS(fname, wtype)
{
   fStream       = nullptr;
   fType         = 0;
   gVirtualPS    = this;
   fBoundingBox  = kFALSE;
   fRange        = kFALSE;
   fXsize        = 0.;
   fYsize        = 0.;
   fCurrentRed   = -1.;
   fCurrentGreen = -1.;
   fCurrentBlue  = -1.;
   fCurrentAlpha = 1.;
   fLineScale    = 0.;
	/*string NM(fname);
	if(NM.size()==0)
	{
		fStream=&Buff;
	}
	else
	{
		Open(fname, wtype);
	}*/
   
}

////////////////////////////////////////////////////////////////////////////////


void TexStreamer::InitPreamble(string preamble_type)
{
	string PathToTexStreamer=getenv("TEX_STREAMER");
	PathToTexStreamer+="/preambles.json";
	std::map<std::string, std::string> preambles;

	try
	{
		// Открываем файл
		std::ifstream file(PathToTexStreamer);
		if (!file.is_open())
		{
			std::cerr << "Ошибка: не удалось открыть файл preambles.json" << std::endl;
		}

		// Парсим JSON
		json j;
		file >> j;

		// Проверяем, что корневой элемент — объект
		if (!j.is_object())
		{
			std::cerr << "Ошибка: корневой элемент JSON не является объектом" << std::endl;
		}

		// Преобразуем JSON объект в map<string, string>
		// Способ 1: явный обход
		for (auto& [key, value] : j.items())
		{
			if (value.is_string())
			{
				preambles[key] = value.get<std::string>();
			}
			else
			{
				std::cerr << "Предупреждение: значение для ключа '" << key << "' не строка, пропускаем" << std::endl;
			}
		}

		// Альтернативный способ (одной строкой), но требует строгого соответствия типов:
		// preambles = j.get<std::map<std::string, std::string>>();

		// Вывод результата для проверки
		std::cout << "Загружено " << preambles.size() << " преамбул:\n";
		for (const auto& [name, content] : preambles)
		{
			std::cout << "[" << name << "]:\n" << content << "\n\n";
		}

	}
	catch (const json::parse_error& e)
	{
		std::cerr << "Ошибка парсинга JSON: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Общая ошибка: " << e.what() << std::endl;
	}
	if(preambles.find(preamble_type) != preambles.end())
	{
		Preamble=preambles[preamble_type];
		if(preamble_type.find("article")!=string::npos)
		{
			PreambleType="article";
		}
		else if(preamble_type.find("beamer")!=string::npos)
		{
			PreambleType="beamer";
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
/// Open a TeX file

void TexStreamer::Open(const char *fname, Int_t wtype)
{
   if (fStream) {
	  Warning("Open", "TeX file already open");
	  return;
   }
	TexStream.open(fname);
	TexStream<<Preamble;
   SetLineScale(gStyle->GetLineScalePS());
   fLenBuffer = 0;
   fType      = abs(wtype);

   gStyle->GetPaperSize(fXsize, fYsize);

   Float_t xrange, yrange;
   if (gPad) {
	  Double_t ww = gPad->GetWw();
	  Double_t wh = gPad->GetWh();
	  ww *= gPad->GetWNDC();
	  wh *= gPad->GetHNDC();
	  Double_t ratio = wh/ww;
	  xrange = fXsize;
	  yrange = fXsize*ratio;
	  if (yrange > fYsize) { yrange = fYsize; xrange = yrange/ratio;}
	  fXsize = xrange; fYsize = yrange;
   }

   // Open OS file
   /*if(NM.size()==0)
	{
		fStream=&Buff;
	}
	else
	{
		fStream   = new std::ofstream(fname,std::ios::out);
	}
   if (!fStream || !fStream->good()) {
	  printf("ERROR in TexStreamer::Open: Cannot open file:%s\n",fname);
	  if (!fStream) return;
   }*/

   gVirtualPS = this;

   for (Int_t i=0;i<fSizBuffer;i++) fBuffer[i] = ' ';

   fBoundingBox = kFALSE;
   fRange       = kFALSE;
   fStandalone  = kFALSE;

   // Set a default range
   Range(fXsize, fYsize);

   if (strstr(GetTitle(),"Standalone")) fStandalone = kTRUE;
   if (fStandalone) {
	  PrintStrTex("\\documentclass{standalone}@");
	  PrintStrTex("\\usepackage{tikz}@");
	  PrintStrTex("\\usetikzlibrary{patterns,plotmarks}@");
	  PrintStrTex("\\begin{document}@");
   } else {
	  PrintStrTex("%\\documentclass{standalone}@");
	  PrintStrTex("%\\usepackage{tikz}@");
	  PrintStrTex("%\\usetikzlibrary{patterns,plotmarks}@");
	  PrintStrTex("%\\begin{document}@");
   }

   NewPage();
}

void TexStreamer::PrintTEX()
{
	TexStream<<CanvasToTEX()<<"\n";
}
////////////////////////////////////////////////////////////////////////////////
/// Default TeX destructor

TexStreamer::~TexStreamer()
{
   Close();
}

////////////////////////////////////////////////////////////////////////////////
/// Close a TeX file


void TexStreamer::Close(Option_t *)
{
	TexStream<<"\\end{document}\n";
	TexStream.close();
   if (!gVirtualPS) return;
   //if (!fStream) return;
   if (gPad) gPad->Update();
   PrintStrTex("@");
   PrintStrTex("\\end{tikzpicture}@");
   if (fStandalone) {
	  PrintStrTex("\\end{document}@");
   } else {
	  PrintStrTex("%\\end{document}@");
   }

	
	
   // Close file stream
   if (fStream) { fStream->close(); delete fStream; fStream = nullptr;}

   gVirtualPS = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
/// Activate an already open TeX file

void TexStreamer::On()
{
   // fType is used to know if the TeX file is open. Unlike TPostScript, TexStreamer
   // has no "workstation type". In fact there is only one TeX type.

   if (!fType) {
	  Error("On", "no TeX file open");
	  Off();
	  return;
   }
   gVirtualPS = this;
}

////////////////////////////////////////////////////////////////////////////////
/// Deactivate an already open TeX file

void TexStreamer::Off()
{
   gVirtualPS = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
/// Draw a Box

void TexStreamer::DrawBox(Double_t x1, Double_t y1, Double_t x2, Double_t y2)
{
   Float_t x1c = XtoTeX(x1);
   Float_t y1c = YtoTeX(y1);
   Float_t x2c = XtoTeX(x2);
   Float_t y2c = YtoTeX(y2);

   Int_t fillis = fFillStyle/1000;
   Int_t fillsi = fFillStyle%1000;

   if (fillis==1) {
	  SetColor(fFillColor);
	  PrintStrTex("@");
	  PrintStrTex("\\draw [color=c, fill=c");
	  if (fCurrentAlpha != 1.) {
		 PrintStrTex(", fill opacity=");
		 WriteRealTex(fCurrentAlpha, kFALSE);
	  }
	  PrintStrTex("] (");
	  WriteRealTex(x1c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y1c, kFALSE);
	  PrintStrTex(") rectangle (");
	  WriteRealTex(x2c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y2c, kFALSE);
	  PrintStrTex(");");
   }
   if (fillis>1 && fillis<4) {
	  SetColor(fFillColor);
	  PrintStrTex("@");
	  PrintStrTex("\\draw [pattern=");
	  switch (fillsi) {
	  case 1 :
		 PrintStrTex("crosshatch dots");
		 break;
	  case 2 :
	  case 3 :
		 PrintStrTex("dots");
		 break;
	  case 4 :
		 PrintStrTex("north east lines");
		 break;
	  case 5 :
		 PrintStrTex("north west lines");
		 break;
	  case 6 :
		 PrintStrTex("vertical lines");
		 break;
	  case 7 :
		 PrintStrTex("horizontal lines");
		 break;
	  case 10 :
		  PrintStrTex("bricks");
		 break;
	  case 13 :
		 PrintStrTex("crosshatch");
		 break;
	  }
	  PrintStrTex(", draw=none, pattern color=c");
	  if (fCurrentAlpha != 1.) {
		 PrintStrTex(", fill opacity=");
		 WriteRealTex(fCurrentAlpha, kFALSE);
	  }
	  PrintStrTex("] (");
	  WriteRealTex(x1c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y1c, kFALSE);
	  PrintStrTex(") rectangle (");
	  WriteRealTex(x2c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y2c, kFALSE);
	  PrintStrTex(");");
   }
   if (fillis == 0) {
	  if (fLineWidth<=0) return;
	  SetColor(fLineColor);
	  PrintStrTex("@");
	  PrintStrTex("\\draw [c");
	  PrintStrTex(",line width=");
	  WriteRealTex(0.3*fLineScale*fLineWidth, kFALSE);
	  if (fCurrentAlpha != 1.) {
		 PrintStrTex(", opacity=");
		 WriteRealTex(fCurrentAlpha, kFALSE);
	  }
	  PrintStrTex("] (");
	  WriteRealTex(x1c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y1c, kFALSE);
	  PrintStrTex(") -- (");
	  WriteRealTex(x1c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y2c, kFALSE);
	  PrintStrTex(") -- (");
	  WriteRealTex(x2c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y2c, kFALSE);
	  PrintStrTex(") -- (");
	  WriteRealTex(x2c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y1c, kFALSE);
	  PrintStrTex(") -- (");
	  WriteRealTex(x1c, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y1c, kFALSE);
	  PrintStrTex(");");
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Draw a Frame around a box
///
/// mode = -1  the box looks as it is behind the screen
/// mode =  1  the box looks as it is in front of the screen
/// border is the border size in already pre-computed TeX units dark is the
/// color for the dark part of the frame light is the color for the light
/// part of the frame

void TexStreamer::DrawFrame(Double_t, Double_t, Double_t, Double_t,
						 Int_t, Int_t, Int_t, Int_t)
{
   Warning("DrawFrame", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// Draw a PolyLine
///
///  Draw a polyline through  the points  xy.
///  - If NN=1 moves only to point x,y.
///  - If NN=0 the x,y are  written in the TeX file
///       according to the current transformation.
///  - If NN>0 the line is clipped as a line.
///  - If NN<0 the line is clipped as a fill area.

/*void TexStreamer::DrawPolyLine(Int_t, TPoints *)
{
   Warning("DrawPolyLine", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// Draw a PolyLine in NDC space
///
///  Draw a polyline through  the points  xy.
///  - If NN=1 moves only to point x,y.
///  - If NN=0 the x,y are  written in the TeX file
///       according to the current transformation.
///  - If NN>0 the line is clipped as a line.
///  - If NN<0 the line is clipped as a fill area.

void TexStreamer::DrawPolyLineNDC(Int_t, TPoints *)
{
   Warning("DrawPolyLineNDC", "not yet implemented");
}*/

////////////////////////////////////////////////////////////////////////////////
/// Paint PolyMarker

void TexStreamer::DrawPolyMarker(Int_t, Float_t *, Float_t *)
{
   Warning("DrawPolyMarker", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// Paint PolyMarker

void TexStreamer::DrawPolyMarker(Int_t n, Double_t *xw, Double_t *yw)
{
   Float_t x, y;

   SetColor(fMarkerColor);

   PrintStrTex("@");
   PrintStrTex("\\foreach \\P in {");

   x = XtoTeX(xw[0]);
   y = YtoTeX(yw[0]);

   PrintStrTex("(");
   WriteRealTex(x, kFALSE);
   PrintFastTex(1,",");
   WriteRealTex(y, kFALSE);
   PrintStrTex(")");

   for (Int_t i=1;i<n;i++) {
	  x = XtoTeX(xw[i]);
	  y = YtoTeX(yw[i]);
	  PrintFastTex(3,", (");
	  WriteRealTex(x, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y, kFALSE);
	  PrintFastTex(1,")");
   }

   PrintStrTex("}{\\draw[mark options={color=c,fill=c");

   if (fCurrentAlpha != 1.) {
	  PrintStrTex(",opacity=");
	  WriteRealTex(fCurrentAlpha, kFALSE);
   }

   if (TAttMarker::GetMarkerStyleBase(fMarkerStyle) == 23 || TAttMarker::GetMarkerStyleBase(fMarkerStyle) == 32) PrintStrTex(",rotate=180");

   PrintStrTex(TString::Format("},mark size=%fpt", 8./3.33*(fMarkerSize - TMath::Floor(TAttMarker::GetMarkerLineWidth(fMarkerStyle)/2.)/4.)));
   PrintStrTex(TString::Format(", line width=%fpt", 4./3.33*TMath::Floor(TAttMarker::GetMarkerLineWidth(fMarkerStyle)/2.)));
   PrintStrTex(", mark=");
   switch (TAttMarker::GetMarkerStyleBase(fMarkerStyle)) {
   case 1 :
	  PrintStrTex("*");
	  PrintStrTex(",mark size=1pt");
	  break;
   case 2 :
	  PrintStrTex("+");
	  break;
   case 3 :
	  PrintStrTex("asterisk");
	  break;
   case 4 :
	  PrintStrTex("o");
	  break;
   case 5 :
	  PrintStrTex("x");
	  break;
   case 20 :
	  PrintStrTex("*");
	  break;
   case 21 :
	  PrintStrTex("square*");
	  break;
   case 22 :
	  PrintStrTex("triangle*");
	  break;
   case 23 :
	  PrintStrTex("triangle*");
	  break;
   case 24 :
	  PrintStrTex("o");
	  break;
   case 25 :
	  PrintStrTex("square");
	  break;
   case 26 :
	  PrintStrTex("triangle");
	  break;
   case 27 :
	  PrintStrTex("diamond");
	  break;
   case 28 :
	  PrintStrTex("cross");
	  break;
   case 29 :
	  PrintStrTex("newstar*");
	  break;
   case 30 :
	  PrintStrTex("newstar");
	  break;
   case 31 :
	  PrintStrTex("10-pointed star");
	  break;
   case 32 :
	  PrintStrTex("triangle");
	  break;
   case 33 :
	  PrintStrTex("diamond*");
	  break;
   case 34 :
	  PrintStrTex("cross*");
	  break;
   }
   PrintStrTex("] plot coordinates {\\P};}");
}

////////////////////////////////////////////////////////////////////////////////
/// This function defines a path with xw and yw and draw it according the
/// value of nn:
///
///  - If nn>0 a line is drawn.
///  - If nn<0 a closed polygon is drawn.

void TexStreamer::DrawPS(Int_t nn, Double_t *xw, Double_t *yw)
{
   Int_t  n = TMath::Abs(nn);;
   Float_t x, y;

   if( n <= 1) {
	  Error("DrawPS", "Two points are needed");
	  return;
   }

   x = XtoTeX(xw[0]);
   y = YtoTeX(yw[0]);

   Int_t fillis = fFillStyle/1000;
   Int_t fillsi = fFillStyle%1000;

   if (nn>0) {
	  if (fLineWidth<=0) return;
	  SetColor(fLineColor);
	  PrintStrTex("@");
	  PrintStrTex("\\draw [c");
	  TString spec = gStyle->GetLineStyleString(fLineStyle);
	  TString tikzSpec;
	  TString stripped = TString{spec.Strip(TString::kBoth)};
	  if (stripped.Length()) {
		 tikzSpec.Append(",dash pattern=");
		 Ssiz_t i{0}, j{0};
		 bool on{true}, iterate{true};

		 while (iterate){
			j = stripped.Index(" ", 1, i, TString::kExact);
			if (j == kNPOS){
			   iterate = false;
			   j = stripped.Length();
			}

			if (on) {
			   tikzSpec.Append("on ");
			   on = false;
			} else {
			   tikzSpec.Append("off ");
			   on = true;
			}
			int num = TString{stripped(i, j - i)}.Atoi();
			float pt = 0.2*num;
			tikzSpec.Append(TString::Format("%.2fpt ", pt));
			i = j + 1;
		 }
		 PrintStrTex(tikzSpec.Data());
	  }
	  PrintStrTex(",line width=");
	  WriteRealTex(0.3*fLineScale*fLineWidth, kFALSE);
	  if (fCurrentAlpha != 1.) {
		 PrintStrTex(",opacity=");
		 WriteRealTex(fCurrentAlpha, kFALSE);
	  }
   } else {
	  SetColor(fFillColor);
	  if (fillis==1) {
		 PrintStrTex("@");
		 PrintStrTex("\\draw [c, fill=c");
	  } else if (fillis==0) {
		 PrintStrTex("@");
		 PrintStrTex("\\draw [c");
	  } else {
		 PrintStrTex("\\draw [pattern=");
		 switch (fillsi) {
		 case 1 :
			PrintStrTex("crosshatch dots");
			break;
		 case 2 :
		 case 3 :
			PrintStrTex("dots");
			break;
		 case 4 :
			PrintStrTex("north east lines");
			break;
		 case 5 :
			PrintStrTex("north west lines");
			break;
		 case 6 :
			PrintStrTex("vertical lines");
			break;
		 case 7 :
			PrintStrTex("horizontal lines");
			break;
		 case 10 :
			 PrintStrTex("bricks");
			break;
		 case 13 :
			PrintStrTex("crosshatch");
			break;
		 }
		 PrintStrTex(", draw=none, pattern color=c");
	  }
	  if (fCurrentAlpha != 1.) {
		 PrintStrTex(", fill opacity=");
		 WriteRealTex(fCurrentAlpha, kFALSE);
	  }
   }
   PrintStrTex("] (");
   WriteRealTex(x, kFALSE);
   PrintFastTex(1,",");
   WriteRealTex(y, kFALSE);
   PrintStrTex(") -- ");

   for (Int_t i=1;i<n;i++) {
	  x = XtoTeX(xw[i]);
	  y = YtoTeX(yw[i]);
	  PrintFastTex(1,"(");
	  WriteRealTex(x, kFALSE);
	  PrintFastTex(1,",");
	  WriteRealTex(y, kFALSE);
	  PrintFastTex(1,")");
	  if (i<n-1) PrintStrTex(" -- ");
	  else PrintStrTex(";@");
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Start the TeX page. This function starts the tikzpicture environment

void TexStreamer::NewPage()
{
   // Compute pad conversion coefficients
   if (gPad) {
	  Double_t ww   = gPad->GetWw();
	  Double_t wh   = gPad->GetWh();
	  fYsize        = fXsize*wh/ww;
   } else {
	  fYsize = 27;
   }

   if(!fBoundingBox) {
	  PrintStrTex("\\begin{tikzpicture}@");
	  PrintStrTex("\\def\\CheckTikzLibraryLoaded#1{ \\ifcsname tikz@library@#1@loaded\\endcsname \\else \\PackageWarning{tikz}{usetikzlibrary{#1} is missing in the preamble.} \\fi }@");
	  PrintStrTex("\\CheckTikzLibraryLoaded{patterns}@");
	  PrintStrTex("\\CheckTikzLibraryLoaded{plotmarks}@");
	  DefineMarkers();
	  fBoundingBox = kTRUE;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Set the range for the paper in centimetres

void TexStreamer::Range(Float_t xsize, Float_t ysize)
{
   fXsize = xsize;
   fYsize = ysize;

   fRange = kTRUE;
}

////////////////////////////////////////////////////////////////////////////////
/// Set color index for fill areas

void TexStreamer::SetFillColor( Color_t cindex )
{
   fFillColor = cindex;
}

////////////////////////////////////////////////////////////////////////////////
/// Set color index for lines

void TexStreamer::SetLineColor( Color_t cindex )
{
   fLineColor = cindex;
}

////////////////////////////////////////////////////////////////////////////////
/// Change the line style
///
///  - linestyle = 2 dashed
///  - linestyle = 3 dotted
///  - linestyle = 4 dash-dotted
///  - linestyle = else solid (1 in is used most of the time)

void TexStreamer::SetLineStyle(Style_t linestyle)
{
   fLineStyle = linestyle;
}

////////////////////////////////////////////////////////////////////////////////
/// Set the lines width.

void TexStreamer::SetLineWidth(Width_t linewidth)
{
   fLineWidth = linewidth;
}

////////////////////////////////////////////////////////////////////////////////
/// Set size for markers.

void TexStreamer::SetMarkerSize( Size_t msize)
{
   fMarkerSize = msize;
}

////////////////////////////////////////////////////////////////////////////////
/// Set color index for markers.

void TexStreamer::SetMarkerColor( Color_t cindex)
{
   fMarkerColor = cindex;
}

////////////////////////////////////////////////////////////////////////////////
/// Set color with its color index

void TexStreamer::SetColor(Int_t color)
{
   if (color < 0) color = 0;
   TColor *col = gROOT->GetColor(color);

   if (col) {
	  SetColor(col->GetRed(), col->GetGreen(), col->GetBlue());
	  fCurrentAlpha = col->GetAlpha();
   } else {
	  SetColor(1., 1., 1.);
	  fCurrentAlpha = 1.;
   }
}

////////////////////////////////////////////////////////////////////////////////
/// Set color with its R G B components
///
///  - r: % of red in [0,1]
///  - g: % of green in [0,1]
///  - b: % of blue in [0,1]

void TexStreamer::SetColor(Float_t r, Float_t g, Float_t b)
{
   if (fCurrentRed == r && fCurrentGreen == g && fCurrentBlue == b) return;

   fCurrentRed   = r;
   fCurrentGreen = g;
   fCurrentBlue  = b;
   PrintStrTex("@");
   PrintStrTex("\\definecolor{c}{rgb}{");
   WriteRealTex(r, kFALSE);
   PrintFastTex(1,",");
   WriteRealTex(g, kFALSE);
   PrintFastTex(1,",");
   WriteRealTex(b, kFALSE);
   PrintFastTex(2,"};");
}

////////////////////////////////////////////////////////////////////////////////
/// Set color index for text

void TexStreamer::SetTextColor( Color_t cindex )
{
   fTextColor = cindex;
}

////////////////////////////////////////////////////////////////////////////////
/// Draw text
///
///  - xx: x position of the text
///  - yy: y position of the text
///  - chars: text to be drawn

void TexStreamer::Text(Double_t x, Double_t y, const char *chars)
{
   Double_t wh = (Double_t)gPad->XtoPixel(gPad->GetX2());
   Double_t hh = (Double_t)gPad->YtoPixel(gPad->GetY1());
   Float_t tsize, ftsize;
   if (wh < hh) {
	  tsize = fTextSize*wh;
	  Int_t sizeTTF = (Int_t)(tsize+0.5);
	  ftsize = (sizeTTF*fXsize*gPad->GetAbsWNDC())/wh;
   } else {
	  tsize = fTextSize*hh;
	  Int_t sizeTTF = (Int_t)(tsize+0.5);
	  ftsize = (sizeTTF*fYsize*gPad->GetAbsHNDC())/hh;
   }
   ftsize *= 2.22097;
   if (ftsize <= 0) return;

   TString t(chars);
   if (t.Index("\\")>=0 || t.Index("^{")>=0 || t.Index("_{")>=0) {
	  t.Prepend("$");
	  t.Append("$");
   } else {
	  t.ReplaceAll("<","$<$");
	  t.ReplaceAll(">","$>$");
	  t.ReplaceAll("_","\\_");
   }
   t.ReplaceAll("&","\\&");
   t.ReplaceAll("#","\\#");
   t.ReplaceAll("%","\\%");

   Int_t txalh = fTextAlign/10;
   if (txalh <1) txalh = 1; else if (txalh > 3) txalh = 3;
   Int_t txalv = fTextAlign%10;
   if (txalv <1) txalv = 1; else if (txalv > 3) txalv = 3;
   SetColor(fTextColor);
   PrintStrTex("@");
   PrintStrTex("\\draw");
   if (txalh!=2 || txalv!=2) {
	  PrintStrTex(" [anchor=");
	  if (txalv==1) PrintStrTex("base");
	  if (txalv==3) PrintStrTex("north");
	  if (txalh==1) PrintStrTex(" west");
	  if (txalh==3) PrintStrTex(" east");
	  PrintFastTex(1,"]");
   }
   PrintFastTex(2," (");
   WriteRealTex(XtoTeX(x), kFALSE);
   PrintFastTex(1,",");
   WriteRealTex(YtoTeX(y), kFALSE);
   PrintStrTex(") node[scale=");
   WriteRealTex(ftsize, kFALSE);
   PrintStrTex(", color=c");
   if (fCurrentAlpha != 1.) {
	  PrintStrTex(",opacity=");
	  WriteRealTex(fCurrentAlpha, kFALSE);
   }
   PrintStrTex(", rotate=");
   WriteRealTex(fTextAngle, kFALSE);
   PrintFastTex(2,"]{");
   PrintStrTex(t.Data());
   PrintFastTex(2,"};");
}

////////////////////////////////////////////////////////////////////////////////
/// Write a string of characters in NDC

void TexStreamer::TextNDC(Double_t u, Double_t v, const char *chars)
{
   Double_t x = gPad->GetX1() + u*(gPad->GetX2() - gPad->GetX1());
   Double_t y = gPad->GetY1() + v*(gPad->GetY2() - gPad->GetY1());
   Text(x, y, chars);
}

////////////////////////////////////////////////////////////////////////////////
/// Convert U from NDC coordinate to TeX

Float_t TexStreamer::UtoTeX(Double_t u)
{
   Double_t cm = fXsize*(gPad->GetAbsXlowNDC() + u*gPad->GetAbsWNDC());
   return cm;
}

////////////////////////////////////////////////////////////////////////////////
/// Convert V from NDC coordinate to TeX

Float_t TexStreamer::VtoTeX(Double_t v)
{
   Double_t cm = fYsize*(gPad->GetAbsYlowNDC() + v*gPad->GetAbsHNDC());
   return cm;
}

////////////////////////////////////////////////////////////////////////////////
/// Convert X from world coordinate to TeX

Float_t TexStreamer::XtoTeX(Double_t x)
{
   Double_t u = (x - gPad->GetX1())/(gPad->GetX2() - gPad->GetX1());
   return  UtoTeX(u);
}

////////////////////////////////////////////////////////////////////////////////
/// Convert Y from world coordinate to TeX

Float_t TexStreamer::YtoTeX(Double_t y)
{
   Double_t v = (y - gPad->GetY1())/(gPad->GetY2() - gPad->GetY1());
   return  VtoTeX(v);
}

////////////////////////////////////////////////////////////////////////////////
/// Begin the Cell Array painting

void TexStreamer::CellArrayBegin(Int_t, Int_t, Double_t, Double_t, Double_t,
						  Double_t)
{
   Warning("CellArrayBegin", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// Paint the Cell Array

void TexStreamer::CellArrayFill(Int_t, Int_t, Int_t)
{
   Warning("CellArrayFill", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// End the Cell Array painting

void TexStreamer::CellArrayEnd()
{
   Warning("CellArrayEnd", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// Not needed in TeX case

void TexStreamer::DrawPS(Int_t, Float_t *, Float_t *)
{
   Warning("DrawPS", "not yet implemented");
}

////////////////////////////////////////////////////////////////////////////////
/// add additional pgfplotmarks

void TexStreamer::DefineMarkers()
{
  // open cross
  PrintStrTex("\\pgfdeclareplotmark{cross} {@");
  PrintStrTex("\\pgfpathmoveto{\\pgfpoint{-0.3\\pgfplotmarksize}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+1\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+1\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{-1.\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{-1.\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-1.\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-1.\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathclose@");
  PrintStrTex("\\pgfusepathqstroke@");
  PrintStrTex("}@");

  // filled cross
  PrintStrTex("\\pgfdeclareplotmark{cross*} {@");
  PrintStrTex("\\pgfpathmoveto{\\pgfpoint{-0.3\\pgfplotmarksize}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+1\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+1\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{+0.3\\pgfplotmarksize}{-1.\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{-1.\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-1.\\pgfplotmarksize}{-0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-1.\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfpoint{-0.3\\pgfplotmarksize}{0.3\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathclose@");
  PrintStrTex("\\pgfusepathqfillstroke@");
  PrintStrTex("}@");

  // open star
  PrintStrTex("\\pgfdeclareplotmark{newstar} {@");
  PrintStrTex("\\pgfpathmoveto{\\pgfqpoint{0pt}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{44}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{18}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-20}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-54}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-90}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{234}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{198}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{162}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{134}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathclose@");
  PrintStrTex("\\pgfusepathqstroke@");
  PrintStrTex("}@");

  // filled star
  PrintStrTex("\\pgfdeclareplotmark{newstar*} {@");
  PrintStrTex("\\pgfpathmoveto{\\pgfqpoint{0pt}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{44}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{18}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-20}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-54}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{-90}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{234}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{198}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{162}{\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathlineto{\\pgfqpointpolar{134}{0.5\\pgfplotmarksize}}@");
  PrintStrTex("\\pgfpathclose@");
  PrintStrTex("\\pgfusepathqfillstroke@");
  PrintStrTex("}@");
}

string TexStreamer::CanvasToTEX(Int_t wtype)
{
	Buff.str("");
	Buff.clear();
	fStream       = nullptr;
	fType         = 0;
	gVirtualPS    = this;
	fBoundingBox  = kFALSE;
	fRange        = kFALSE;
	fXsize        = 0.;
	fYsize        = 0.;
	fCurrentRed   = -1.;
	fCurrentGreen = -1.;
	fCurrentBlue  = -1.;
	fCurrentAlpha = 1.;
	fLineScale    = 0.;
	
	SetLineScale(gStyle->GetLineScalePS());
	fLenBuffer = 0;
	fType      = abs(wtype);

	gStyle->GetPaperSize(fXsize, fYsize);

	Float_t xrange, yrange;
	if (gPad) 
	{
		Double_t ww = gPad->GetWw();
		Double_t wh = gPad->GetWh();
		ww *= gPad->GetWNDC();
		wh *= gPad->GetHNDC();
		Double_t ratio = wh/ww;
		xrange = fXsize;
		yrange = fXsize*ratio;
		if (yrange > fYsize) { yrange = fYsize; xrange = yrange/ratio;}
		fXsize = xrange; fYsize = yrange;
	}
	gVirtualPS = this;

	for (Int_t i=0;i<fSizBuffer;i++) fBuffer[i] = ' ';

	fBoundingBox = kFALSE;
	fRange       = kFALSE;
	fStandalone  = kFALSE;

	// Set a default range
	Range(fXsize, fYsize);
	NewPage();
	gPad->GetCanvas()->Draw();
	if (gPad) gPad->Update();
	PrintStrTex("@");
	PrintStrTex("\\end{tikzpicture}@");
	gVirtualPS = nullptr;
	return Buff.str();
}

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Вспомогательная функция для экранирования спецсимволов LaTeX
string escapeLatex(const string& s) {
    string result;
    for (char ch : s) {
        switch (ch) {
            case '#': result += "\\#"; break;
            case '$': result += "\\$"; break;
            case '%': result += "\\%"; break;
            case '&': result += "\\&"; break;
            case '_': result += "\\_"; break;
            case '{': result += "\\{"; break;
            case '}': result += "\\}"; break;
            case '~': result += "\\textasciitilde{}"; break;
            case '^': result += "\\textasciicircum{}"; break;
            case '\\': result += "\\textbackslash{}"; break;
            default: result += ch; break;
        }
    }
    return result;
}

string TEXFigure::Generate()
{
	stringstream str;
	str<<"\\begin{figure}[htbp]\n\\centering\n";
	//теперь нужно определить размерность картинки
	unsigned int NRows=0;
	NRows=Content.size();
	char a='a';
	char NFigures=0;
	for(unsigned int i=0;i<NRows;i++)
	{
		vector<double> Fill;
		double k_norm=0;
		double p_norm=0;
		for(unsigned int j=0;j<Widths[i].size();j++)
		{
			if(Widths[i][j]<1)
			{
				k_norm+=Widths[i][j];
			}
			else
			{
				p_norm+=Widths[i][j];
			}
		}
		if(k_norm>0.97)
		{
			k_norm=k_norm/0.96;
			p_norm=p_norm/0.01;
		}
		else
		{
			p_norm=p_norm/(0.97-k_norm);
			k_norm=1;
			
		}
		for(unsigned int j=0;j<Widths[i].size();j++)
		{
			//cout<<"Widths["<<i<<"]["<<j<<"]:"<<Widths[i][j]<<"\n";
			if(Widths[i][j]<1)
			{
				Widths[i][j]=Widths[i][j]/k_norm;
			}
			else
			{
				Widths[i][j]=Widths[i][j]/p_norm;
			}
		}
		
		for(unsigned int j=0;j<Content[i].size();j++)
		{
			str<<TString::Format("\\begin{minipage}[h]{%.2f\\linewidth}\n",Widths[i][j]);
			if(Content[i][j].size()>0)
			{
				//выясняем, картинка - файл или строка tkiz
				if(Content[i][j].find("\\begin{tikzpicture}")!=string::npos)
				{
					str<<"\\center{\\resizebox{1\\linewidth}{!}{\n"<<Content[i][j]<<"\n}\n \\\\";
					if(Content[i].size()>1 ||Content.size()>1 )
					{
						str<<a<<")";
					}
					str<<"}\n";
					NFigures++;
					a++;
				}
				else if(Content[i][j].size()>0)
				{
					if(Content[i][j][0]=='\r')
					{
						str<<Content[i][j].substr(1);
					}
					else
					{
						str<<"\\center{\\includegraphics[width=1\\linewidth]{"<<Content[i][j]<<"} \\\\";
						if(Content[i].size()>1 ||Content.size()>1 )
						{
							str<<a<<")";
						}
						str<<"}\n";
						NFigures++;
						a++;
					}
					
				}
			}
			str<<"\\end{minipage}\n";
			if((int)j<(int)Content[i].size()-1)
			{
				str<<"\\hfill\n";
			}
		}
		if((int)i<(int)Content.size()-1)
		{
			str<<"\\vfill\n";
		}
	}
	if(Caption.size()>0)
	{
		str<<"\\caption{"<<Caption<<"}\n";
	}
	if(Label.size()>0)
	{
		str<<"\\label{"<<Label<<"}\n";
	}
	str<<"\\end{figure}\n";
	return str.str();
}

string GetTextInBrackets(unsigned int start_pos,string str)
{
	/*if(start_pos==string::npos)
	{
		return "";
	}*/
	string result;
	int OpenCount=0, CloseCount=0;
	for(unsigned int i=start_pos;i<str.size();i++)
	{
		if(str[i]=='{')
		{
			OpenCount++;
			if(OpenCount==1)
			{
				continue;
			}
		}
		if(str[i]=='}')
		{
			CloseCount++;
		}
		if(OpenCount>0 && OpenCount!=CloseCount)
		{
			result+=str[i];
		}
		if(OpenCount==CloseCount && OpenCount>0)
		{
			break;
		}
		
	}
	return result;
}

TEXFigure &operator << (TEXFigure &tx, string value)
{
	if(tx.Content.size()<tx.CurrentRow+1)
	{
		tx.Content.resize(tx.CurrentRow+1);
		tx.Widths.resize(tx.CurrentRow+1);
	}
	if(value=="\n")//<<"\n" означает переход на новую строку
	{
		tx.CurrentRow++;
		return tx;
	}
	if(value.find("caption={")!=string::npos || value.find("label={")!=string::npos|| value.find("width={")!=string::npos)
	{
		int capt=(int)value.find("caption={");
		int lab=(int)value.find("label={");
		int wid=(int)value.find("width={");
		if(capt>-1)
		{
			tx.Caption=GetTextInBrackets(capt,value);
		}
		if(lab>-1)
		{
			tx.Label=GetTextInBrackets(lab,value);
		}
		if(wid>-1)
		{
			if((tx.Widths[tx.CurrentRow].size()==tx.Content[tx.CurrentRow].size()) && tx.Content[tx.CurrentRow].size() > 0)
			{
				tx.Widths[tx.CurrentRow][tx.Widths[tx.CurrentRow].size()-1]=atof(GetTextInBrackets(wid,value).c_str());
			}
			//tx.Widths[tx.CurrentRow].push_back(atof(GetTextInBrackets(lab,value).c_str()));
		}
	}
	else
	{
		tx.Content[tx.CurrentRow].push_back(value);
		tx.Widths[tx.CurrentRow].push_back(1);//по умолчанию делим поровну
	}
	return tx;
}

TEXFormula &operator << (TEXFormula &tx, string value)
{
	if(value.find("label={")!=string::npos)
	{
		int lab=value.find("label={");
		if((unsigned int)lab!=string::npos)
		{
			tx.Label=GetTextInBrackets(lab,value);
		}
	}
	else
	{
		tx.Formula=value;
	}
	return tx;
}

string TEXFormula::Generate()
{
	stringstream s;
	s<<"\\begin{equation}\n"<<Formula<<"\n";
	if(Label.size()>0)
	s<<"\\label{"<<Label<<"}\n";
	s<<"\\end{equation}\n";
	return s.str();
}

string TEXTable::Generate() {
    size_t rows = Cells.size();
    if (rows == 0) return "";

    // Коррекция MultiRow, чтобы не выходить за границы таблицы
    for (size_t i = 0; i < rows; ++i) {
        size_t col = 0;
        for (auto& cell : Cells[i]) {
            int& mr = cell.MultiRow;
            if (mr > 1 && i + mr > rows) {
                mr = rows - i;   // обрезаем до доступного количества строк
                if (mr < 1) mr = 1;
            }
            col += cell.MultiCol;
        }
    }

    // layout[i][j] → указатель на ячейку, если (i,j) – начало объединения
    vector<vector<TEXTableCell*>> layout(rows);
    // verticalSpan[i][j] → true, если ячейка (i,j) занята вертикальным объединением
    vector<vector<bool>> verticalSpan(rows);

    // 1. Размещение ячеек с учётом объединений
    for (size_t i = 0; i < rows; ++i) {
        size_t j = 0;
        for (auto& cell : Cells[i]) {
            while (j < verticalSpan[i].size() && verticalSpan[i][j]) ++j;

            int mc = cell.MultiCol;
            int mr = cell.MultiRow;

            if (layout[i].size() < j + mc) {
                layout[i].resize(j + mc, nullptr);
                verticalSpan[i].resize(j + mc, false);
            }
            layout[i][j] = &cell;

            // Пометить занятые позиции в последующих строках
            for (size_t r = i + 1; r < i + mr && r < rows; ++r) {
                if (verticalSpan[r].size() < j + mc) {
                    verticalSpan[r].resize(j + mc, false);
                    if (layout[r].size() < j + mc) layout[r].resize(j + mc, nullptr);
                }
                for (size_t c = j; c < j + mc; ++c)
                    verticalSpan[r][c] = true;
            }
            j += mc;
        }
    }

    // Определить общее число колонок
    size_t totalCols = 0;
    for (size_t i = 0; i < rows; ++i) {
        totalCols = max(totalCols, layout[i].size());
        totalCols = max(totalCols, verticalSpan[i].size());
    }
    for (size_t i = 0; i < rows; ++i) {
        layout[i].resize(totalCols, nullptr);
        verticalSpan[i].resize(totalCols, false);
    }

    // 2. Генерация LaTeX
    stringstream ss;
    ss << "\\begin{table}[h]\n\\centering\n";
    //if (!Caption.empty()) ss << "\\caption{" << escapeLatex(Caption) << "}\n";
    //if (!Label.empty())   ss << "\\label{" << escapeLatex(Label) << "}\n";
    
    if (!Caption.empty()) ss << "\\caption{" << Caption << "}\n";
    if (!Label.empty())   ss << "\\label{" << Label << "}\n";

    string colSpec = "|";
    for (size_t j = 0; j < totalCols; ++j) colSpec += "c|";
    ss << "\\begin{tabular}{" << colSpec << "}\n\\hline\n";

    // Генерация строк
    for (size_t i = 0; i < rows; ++i) {
        size_t col = 0;
        while (col < totalCols) {
            if (layout[i][col] != nullptr) {
                TEXTableCell* cell = layout[i][col];
                int mc = cell->MultiCol;
                int mr = cell->MultiRow;
                //string content = escapeLatex(cell->Content);
                string content = cell->Content;

                if (mc > 1 && mr > 1) {
                    // \multicolumn{...}{|c|}{\multirow{...}{*}{...}}
                    ss << "\\multicolumn{" << mc << "}{|c|}{\\multirow{" << mr << "}{*}{" << content << "}}";
                } else if (mc > 1) {
                    ss << "\\multicolumn{" << mc << "}{|c|}{" << content << "}";
                } else if (mr > 1) {
                    ss << "\\multirow{" << mr << "}{*}{" << content << "}";
                } else {
                    ss << content;
                }
                col += mc;
            } else {
                ++col;
            }
            if (col < totalCols) ss << " & ";
        }

        // Горизонтальные линии
        if (i == rows - 1) {
            ss << " \\\\ \\hline\n";
        } else {
            // Найти интервалы колонок, НЕ перекрытых вертикальными объединениями из следующей строки
            vector<pair<int,int>> intervals;
            int start = -1;
            for (size_t j = 0; j < totalCols; ++j) {
                bool needLine = !verticalSpan[i+1][j];
                if (needLine) {
                    if (start == -1) start = j;
                } else {
                    if (start != -1) {
                        intervals.emplace_back(start, j-1);
                        start = -1;
                    }
                }
            }
            if (start != -1) intervals.emplace_back(start, totalCols-1);

            if (intervals.size() == 1 && intervals[0].first == 0 && intervals[0].second == (int)totalCols-1) {
                ss << " \\\\ \\hline\n";
            } else {
                ss << " \\\\";
                for (auto& inv : intervals) {
                    ss << " \\cline{" << inv.first+1 << "-" << inv.second+1 << "}";
                }
                ss << "\n";
            }
        }
    }

    ss << "\\end{tabular}\n\\end{table}\n";
    return ss.str();
}
TEXTable &operator << (TEXTable &tx, string value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	if(value=="\n")//<<"\n" означает переход на новую строку
	{
		tx.CurrentRow++;
		return tx;
	}
	if(value[0]=='\e')
	{
		value=value.substr(1);
		int NEscape=atoi(value.c_str());
		tx.Cells[tx.CurrentRow].resize(tx.Cells[tx.CurrentRow].size()+NEscape);
	}
	if(value.find("caption={")!=string::npos || value.find("label={")!=string::npos|| value.find("width={")!=string::npos)
	{
		int capt=(int)value.find("caption={");
		int lab=(int)value.find("label={");
		if(capt>-1)
		{
			tx.Caption=GetTextInBrackets(capt,value);
		}
		if(lab>-1)
		{
			tx.Label=GetTextInBrackets(lab,value);
		}
		return tx;
	}
	TEXTableCell c;
	if(value.find("mr={")!=string::npos || value.find("mc={")!=string::npos)
	{
		int mc=(int)value.find("mc={");
		int mr=(int)value.find("mr={");
		if(mc>-1)
		{
			c.MultiCol=atoi(GetTextInBrackets(mc,value).c_str());
		}
		if(mr>-1)
		{
			c.MultiRow=atoi(GetTextInBrackets(mr,value).c_str());
		}
		
		TString ts(value);
		ts.ReplaceAll(TString::Format("mr={%d}",c.MultiRow),"");
		ts.ReplaceAll(TString::Format("mc={%d}",c.MultiCol),"");
		ts.ReplaceAll("  "," ");
		value=string(ts.Data());
		c.Content=value;
	}
	else
	{
		c.Content=value;
	}
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
TEXTable &operator << (TEXTable &tx, double value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	TEXTableCell c;
	c.Content=to_string(value);
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
TEXTable &operator << (TEXTable &tx, float value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	TEXTableCell c;
	c.Content=to_string(value);
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
TEXTable &operator << (TEXTable &tx, int value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	TEXTableCell c;
	c.Content=to_string(value);
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
TEXTable &operator << (TEXTable &tx, unsigned int value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	TEXTableCell c;
	c.Content=to_string(value);
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
TEXTable &operator << (TEXTable &tx, char value)
{
	if(tx.Cells.size()<tx.CurrentRow+1)
	{
		tx.Cells.resize(tx.CurrentRow+1);
	}
	TEXTableCell c;
	c.Content+=to_string(value);
	tx.Cells[tx.CurrentRow].push_back(c);
	return tx;
}
void TEXTable::PrintInTerminal()
{
	for(unsigned int i=0;i<Cells.size();i++)
	{
		for(unsigned int j=0;j<Cells[i].size();j++)
		{
			cout<<Cells[i][j].Content<<" ";
		}
		cout<<"\n";
	}
}

string TEXPage::Generate()
{
	stringstream s;
	for(unsigned int i=0;i<Content.size();i++)
	{
		if(Content[i].first=="str")
		{
			s<<Strings[Content[i].second];
		}
		if(Content[i].first=="TEXFigure")
		{
			s<<Figures[Content[i].second].Generate();
		}
		if(Content[i].first=="TEXTable")
		{
			s<<Tables[Content[i].second].Generate();
		}
		if(Content[i].first=="TEXFormula")
		{
			s<<Formulas[Content[i].second].Generate();
		}
		if(Content[i].first=="TEXFigure*")
		{
			s<<Figures_[Content[i].second]->Generate();
		}
		if(Content[i].first=="TEXTable*")
		{
			s<<Tables_[Content[i].second]->Generate();
		}
		if(Content[i].first=="TEXFormula*")
		{
			s<<Formulas_[Content[i].second]->Generate();
		}
	}
	return s.str();
}

TEXPage &operator << (TEXPage &tx, string value)
{
	tx.Strings.push_back(value);
	if(value.find("title={")!=string::npos || value.find("subtitle={")!=string::npos)
	{
		int capt=(int)value.find("title={");
		int lab=(int)value.find("subtitle={");
		if(capt==lab+3)
		{
			capt=-1;
		}
		if(capt>-1)
		{
			tx.Title=GetTextInBrackets(capt,value);
		}
		if(lab>-1)
		{
			tx.Subtitle=GetTextInBrackets(lab,value);
		}
		return tx;
	}
	pair<string,unsigned int> p={"str",tx.Strings.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXPage &operator << (TEXPage &tx, double value)
{
	if(tx.Strings.size()==0)
	{
		tx.Strings.push_back(to_string(value));
		pair<string,unsigned int> p={"str",tx.Strings.size()-1};
		tx.Content.push_back(p);
	}
	else
	{
		tx.Strings[tx.Strings.size()-1]+=value;
	}
	return tx;
}
TEXPage &operator << (TEXPage &tx, float value)
{
	if(tx.Strings.size()==0)
	{
		tx.Strings.push_back(to_string(value));
		pair<string,unsigned int> p={"str",tx.Strings.size()-1};
		tx.Content.push_back(p);
	}
	else
	{
		tx.Strings[tx.Strings.size()-1]+=value;
	}
	return tx;
}
TEXPage &operator << (TEXPage &tx, int value)
{
	if(tx.Strings.size()==0)
	{
		tx.Strings.push_back(to_string(value));
		pair<string,unsigned int> p={"str",tx.Strings.size()-1};
		tx.Content.push_back(p);
	}
	else
	{
		tx.Strings[tx.Strings.size()-1]+=value;
	}
	return tx;
}
TEXPage &operator << (TEXPage &tx, unsigned int value)
{
	if(tx.Strings.size()==0)
	{
		tx.Strings.push_back(to_string(value));
		pair<string,unsigned int> p={"str",tx.Strings.size()-1};
		tx.Content.push_back(p);
	}
	else
	{
		tx.Strings[tx.Strings.size()-1]+=value;
	}
	return tx;
}
TEXPage &operator << (TEXPage &tx, char value)
{
	if(tx.Strings.size()==0)
	{
		string aa(1,value);
		tx.Strings.push_back(string(aa));
		pair<string,unsigned int> p={"str",tx.Strings.size()-1};
		tx.Content.push_back(p);
	}
	else
	{
		tx.Strings[tx.Strings.size()-1]+=value;
	}
	return tx;
}

TEXPage &operator << (TEXPage &tx, TEXFigure value)
{
	tx.Figures.push_back(value);
	pair<string,unsigned int> p={"TEXFigure",tx.Figures.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXPage &operator << (TEXPage &tx, TEXFormula value)
{
	tx.Formulas.push_back(value);
	pair<string,unsigned int> p={"TEXFormula",tx.Formulas.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXPage &operator << (TEXPage &tx, TEXTable value)
{
	tx.Tables.push_back(value);
	pair<string,unsigned int> p={"TEXTable",tx.Tables.size()-1};
	tx.Content.push_back(p);
	return tx;
}

TEXPage &operator << (TEXPage &tx, TEXFigure* value)
{
	tx.Figures_.push_back(value);
	pair<string,unsigned int> p={"TEXFigure*",tx.Figures_.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXPage &operator << (TEXPage &tx, TEXFormula* value)
{
	tx.Formulas_.push_back(value);
	pair<string,unsigned int> p={"TEXFormula*",tx.Formulas_.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXPage &operator << (TEXPage &tx, TEXTable* value)
{
	tx.Tables_.push_back(value);
	pair<string,unsigned int> p={"TEXTable*",tx.Tables_.size()-1};
	tx.Content.push_back(p);
	return tx;
}
TEXDocument &operator << (TEXDocument &tx, string value)
{
	if(value=="\\newpage")
	{
		tx.Pages.resize(tx.Pages.size()+1);
		tx.ActualPage=&tx.Pages[tx.Pages.size()-1];
		return tx;
	}
	else if(value.size()>0)
	{
		if(tx.Pages.size()==0)
		{
			tx.Pages.resize(1);
		}
	}
	tx.ActualPage=&tx.Pages[tx.Pages.size()-1];
	(*tx.ActualPage)<<value;
	return tx;
}
TEXDocument &operator << (TEXDocument &tx, TEXPage &value)
{
	tx.Pages.push_back(value);
	tx.ActualPage=&tx.Pages[tx.Pages.size()-1];
	return tx;
}
TEXDocument& operator<<(TEXDocument &tx,const char* value)
{	
	return tx << std::string(value);
}

string TEXDocument::Generate()
{
	stringstream str;
	str<<Preamble;
	for(unsigned int i=0;i<Pages.size();i++)
	{
		if(PreambleType=="beamer")
		{
			str<<"\\begin{frame}[fragile]\n";
			if(Pages[i].Title.size()>0)
			{
				str<<"\\frametitle{"<<Pages[i].Title<<"}\n";
			}
			if(Pages[i].Subtitle.size()>0)
			{
				str<<"\\framesubtitle{"<<Pages[i].Subtitle<<"}\n";
			}
			str<<Pages[i].Generate();
			str<<"\\end{frame}\n";
		}
		else
		{
			str<<Pages[i].Generate()<<"\n";
			if(Pages[i].Title.size()>0)
			{
				str<<"\\section{"<<Pages[i].Title<<"}\n";
			}
			if(Pages[i].Subtitle.size()>0)
			{
				str<<"\\subsection{"<<Pages[i].Subtitle<<"}\n";
			}
			if(Pages.size()>1 && i<Pages.size()-1)
			{
				str<<"\\newpage\n";
			}
			
		}
	}
	str<<"\\end{document}";
	return str.str();
}
TEXDocument::TEXDocument(string doctype)
{
	//сначала прочитаем доступные перамбулы
	string PathToTexStreamer=getenv("TEX_STREAMER");
	PathToTexStreamer+="/preambles.json";
	std::map<std::string, std::string> preambles;
	try
	{
		// Открываем файл
		std::ifstream file(PathToTexStreamer);
		if (!file.is_open())
		{
			std::cerr << "Ошибка: не удалось открыть файл preambles.json" << std::endl;
		}

		// Парсим JSON
		json j;
		file >> j;

		// Проверяем, что корневой элемент — объект
		if (!j.is_object())
		{
			std::cerr << "Ошибка: корневой элемент JSON не является объектом" << std::endl;
		}

		// Преобразуем JSON объект в map<string, string>
		// Способ 1: явный обход
		for (auto& [key, value] : j.items())
		{
			if (value.is_string())
			{
				preambles[key] = value.get<std::string>();
			}
			else
			{
				std::cerr << "Предупреждение: значение для ключа '" << key << "' не строка, пропускаем" << std::endl;
			}
		}

		// Альтернативный способ (одной строкой), но требует строгого соответствия типов:
		// preambles = j.get<std::map<std::string, std::string>>();

		// Вывод результата для проверки
	}
	catch (const json::parse_error& e)
	{
		std::cerr << "Ошибка парсинга JSON: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Общая ошибка: " << e.what() << std::endl;
	}
	if(preambles.find(doctype) != preambles.end())
	{
		Preamble=preambles[doctype];
		if(doctype.find("article")!=string::npos)
		{
			PreambleType="article";
		}
		else if(doctype.find("beamer")!=string::npos)
		{
			PreambleType="beamer";
		}
	}
	Pages.resize(1);
	ActualPage=&Pages[0];
}
