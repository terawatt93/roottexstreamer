// @(#)root/postscript:$Id$
// Author: Olivier Couet

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TexStreamer
#define ROOT_TexStreamer


#include "TVirtualPS.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <TSystem.h>

using namespace std;

class TexStreamer : public TVirtualPS {

protected:
   Float_t      fXsize;           ///< Page size along X
   Float_t      fYsize;           ///< Page size along Y
   Int_t        fType;            ///< Workstation type used to know if the Tex is open
   Bool_t       fBoundingBox;     ///< True when the TeX header is printed
   Bool_t       fRange;           ///< True when a range has been defined
   Bool_t       fStandalone;      ///< True when a TeX file should be standalone
   Float_t      fCurrentRed;      ///< Current Red component
   Float_t      fCurrentGreen;    ///< Current Green component
   Float_t      fCurrentBlue;     ///< Current Blue component
   Float_t      fCurrentAlpha;    ///< Current Alpha value
   Float_t      fLineScale;       ///< Line width scale factor


public:
   TexStreamer();
   TexStreamer(const char *filename, Int_t type=-113);
   ~TexStreamer() override;
	std::stringstream Buff;
	ofstream TexStream;
	string Preamble;
	string PreambleType;
	void InitPreamble(string preamble_type="article_a4_12pt_geometry_1cm");
	void PrintTEX();
   void    CellArrayBegin(Int_t W, Int_t H, Double_t x1, Double_t x2, Double_t y1, Double_t y2) override;
   void    CellArrayFill(Int_t r, Int_t g, Int_t b) override;
   void    CellArrayEnd() override;
   void    Close(Option_t *opt="") override;
   Int_t   CMtoTeX(Double_t u) { return Int_t(0.5 + 72*u/2.54); }
   void    DefineMarkers();
   void    DrawBox(Double_t x1, Double_t y1,Double_t x2, Double_t  y2) override;
   void    DrawFrame(Double_t xl, Double_t yl, Double_t xt, Double_t  yt,
                     Int_t mode, Int_t border, Int_t dark, Int_t light) override;
   /*void    DrawPolyLine(Int_t n, TPoints *xy);
   void    DrawPolyLineNDC(Int_t n, TPoints *uv);*/
   void    DrawPolyMarker(Int_t n, Float_t *x, Float_t *y) override;
   void    DrawPolyMarker(Int_t n, Double_t *x, Double_t *y) override;
   void    DrawPS(Int_t n, Float_t *xw, Float_t *yw) override;
   void    DrawPS(Int_t n, Double_t *xw, Double_t *yw) override;
   void    NewPage() override;
   void    Off();
   void    On();
   void    Open(const char *filename, Int_t type=-111) override;
   void    Range(Float_t xrange, Float_t yrange);
   void    SetColor(Int_t color = 1);
   void    SetColor(Float_t r, Float_t g, Float_t b) override;
   void    SetFillColor(Color_t cindex=1) override;
   void    SetLineColor(Color_t cindex=1) override;
   void    SetLineStyle(Style_t linestyle = 1) override;
   void    SetLineWidth(Width_t linewidth = 1) override;
   void    SetLineScale(Float_t scale=1) { fLineScale = scale; }
   void    SetMarkerSize(Size_t msize=1) override;
   void    SetMarkerColor(Color_t cindex=1) override;
   void    SetTextColor(Color_t cindex=1) override;
   void    Text(Double_t x, Double_t y, const char *string) override;
   void    Text(Double_t, Double_t, const wchar_t *) override {}
   void    TextNDC(Double_t u, Double_t v, const char *string);
   void    TextNDC(Double_t, Double_t, const wchar_t *) {}
   Float_t UtoTeX(Double_t u);
   Float_t VtoTeX(Double_t v);
   Float_t XtoTeX(Double_t x);
   Float_t YtoTeX(Double_t y);
   
   virtual void  PrintFastTex(Int_t nch, const char *string="");
   virtual void  PrintStrTex(const char *string="");
   virtual void  WriteIntegerTex(Int_t i, Bool_t space=kTRUE);
   virtual void  WriteRealTex(Float_t r, Bool_t space=kTRUE);
   string CanvasToTEX( Int_t type=-111);
   ClassDefOverride(TexStreamer, 1);  //Tex driver
};

class TEXFigure:public TObject
{
	public:
	string FigName,Caption,Label;
	vector<vector<string> > Content;
	vector<vector<double> > Widths;
	string Generate();
	unsigned int CurrentRow=0;
	ClassDef(TEXFigure, 1);
};

TEXFigure &operator << (TEXFigure &tx, string value);

class TEXFormula:public TObject
{
	public:
	string Formula,Label;
	string Generate();
	ClassDef(TEXFormula, 1);
};
TEXFormula &operator << (TEXFormula &tx, string value);
class TEXTableCell:public TObject
{
	public:
	string Content;
	int MultiCol=1,MultiRow=1;
	ClassDef(TEXTableCell, 1);
};
class TEXTable:public TObject
{
	public:
	vector<vector<TEXTableCell> > Cells;
	string Caption,Label;
	string Generate();
	unsigned int CurrentRow=0;
	void PrintInTerminal();
	ClassDef(TEXTable, 1);
};

TEXTable &operator << (TEXTable &tx, string value);
TEXTable &operator << (TEXTable &tx, double value);
TEXTable &operator << (TEXTable &tx, float value);
TEXTable &operator << (TEXTable &tx, int value);
TEXTable &operator << (TEXTable &tx, unsigned int value);
TEXTable &operator << (TEXTable &tx, char value);


class TEXPage
{
	public:
	vector<TEXFigure> Figures;
	vector<TEXTable> Tables;
	vector<TEXFormula> Formulas;
	
	vector<TEXFigure*> Figures_;
	vector<TEXTable*> Tables_;
	vector<TEXFormula*> Formulas_;
	
	vector<string> Strings;
	string Title,Subtitle;//если используется beamer, это title и subtitle слайда. Если нет, то section и subsection
	vector<pair<string,unsigned int> > Content; 
	
	string Generate();
	ClassDef(TEXPage, 1);
};

TEXPage &operator << (TEXPage &tx, string value);
TEXPage &operator << (TEXPage &tx, double value);
TEXPage &operator << (TEXPage &tx, float value);
TEXPage &operator << (TEXPage &tx, int value);
TEXPage &operator << (TEXPage &tx, unsigned int value);
TEXPage &operator << (TEXPage &tx, char value);

TEXPage &operator << (TEXPage &tx, TEXFigure value);
TEXPage &operator << (TEXPage &tx, TEXFormula value);
TEXPage &operator << (TEXPage &tx, TEXTable value);

TEXPage &operator << (TEXPage &tx, TEXFigure* value);
TEXPage &operator << (TEXPage &tx, TEXFormula* value);
TEXPage &operator << (TEXPage &tx, TEXTable* value);

class TEXDocument:public TObject
{
	public:
	TEXDocument(string doctype="article_a4_12pt_geometry_1cm");
	string Preamble;
	string PreambleType;
	string OutFileName;
	vector<TEXPage> Pages;
	TEXPage *ActualPage;
	string Generate();
	ClassDef(TEXDocument, 1);
	void Save(string filename);
	void SaveAndCompile(string filename);
	//void Compile();
};
TEXDocument &operator << (TEXDocument &tx, string value);
TEXDocument &operator << (TEXDocument &tx, TEXPage &value);
TEXDocument& operator<<(TEXDocument &tx,const char* value);
template<typename T>TEXDocument& operator<<(TEXDocument &tx,const T& value)
{
	if(tx.Pages.size()==0)
	{
			tx.Pages.resize(1);
	}
	tx.ActualPage=&(tx.Pages[tx.Pages.size()-1]);
	(*tx.ActualPage)<<value;
	return tx;
}
template<typename T>TEXDocument& operator<<(TEXDocument &tx,const T* value)
{
	if(tx.Pages.size()==1)
	{
		tx.Pages.resize(1);
	}
	tx.ActualPage=&(tx.Pages[tx.Pages.size()-1]);
	(*tx.ActualPage)<<value;
	return tx;
}

/*template<typename T>TEXDocument& operator<<(TEXDocument &tx,const T& value);
template<typename T>TEXDocument& operator<<(TEXDocument &tx,const T* value);*/
#endif
