// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TexStreamer
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "TexStreamer.hh"
#include "TexStreamerDict.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TexStreamer(void *p = nullptr);
   static void *newArray_TexStreamer(Long_t size, void *p);
   static void delete_TexStreamer(void *p);
   static void deleteArray_TexStreamer(void *p);
   static void destruct_TexStreamer(void *p);
   static void streamer_TexStreamer(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TexStreamer*)
   {
      ::TexStreamer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TexStreamer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TexStreamer", ::TexStreamer::Class_Version(), "TexStreamer.hh", 24,
                  typeid(::TexStreamer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TexStreamer::Dictionary, isa_proxy, 16,
                  sizeof(::TexStreamer) );
      instance.SetNew(&new_TexStreamer);
      instance.SetNewArray(&newArray_TexStreamer);
      instance.SetDelete(&delete_TexStreamer);
      instance.SetDeleteArray(&deleteArray_TexStreamer);
      instance.SetDestructor(&destruct_TexStreamer);
      instance.SetStreamerFunc(&streamer_TexStreamer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TexStreamer*)
   {
      return GenerateInitInstanceLocal(static_cast<::TexStreamer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TexStreamer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXFigure(void *p = nullptr);
   static void *newArray_TEXFigure(Long_t size, void *p);
   static void delete_TEXFigure(void *p);
   static void deleteArray_TEXFigure(void *p);
   static void destruct_TEXFigure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXFigure*)
   {
      ::TEXFigure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXFigure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXFigure", ::TEXFigure::Class_Version(), "TexStreamer.hh", 97,
                  typeid(::TEXFigure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXFigure::Dictionary, isa_proxy, 4,
                  sizeof(::TEXFigure) );
      instance.SetNew(&new_TEXFigure);
      instance.SetNewArray(&newArray_TEXFigure);
      instance.SetDelete(&delete_TEXFigure);
      instance.SetDeleteArray(&deleteArray_TEXFigure);
      instance.SetDestructor(&destruct_TEXFigure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXFigure*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXFigure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXFigure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXFormula(void *p = nullptr);
   static void *newArray_TEXFormula(Long_t size, void *p);
   static void delete_TEXFormula(void *p);
   static void deleteArray_TEXFormula(void *p);
   static void destruct_TEXFormula(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXFormula*)
   {
      ::TEXFormula *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXFormula >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXFormula", ::TEXFormula::Class_Version(), "TexStreamer.hh", 110,
                  typeid(::TEXFormula), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXFormula::Dictionary, isa_proxy, 4,
                  sizeof(::TEXFormula) );
      instance.SetNew(&new_TEXFormula);
      instance.SetNewArray(&newArray_TEXFormula);
      instance.SetDelete(&delete_TEXFormula);
      instance.SetDeleteArray(&deleteArray_TEXFormula);
      instance.SetDestructor(&destruct_TEXFormula);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXFormula*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXFormula*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXFormula*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXTableCell(void *p = nullptr);
   static void *newArray_TEXTableCell(Long_t size, void *p);
   static void delete_TEXTableCell(void *p);
   static void deleteArray_TEXTableCell(void *p);
   static void destruct_TEXTableCell(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXTableCell*)
   {
      ::TEXTableCell *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXTableCell >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXTableCell", ::TEXTableCell::Class_Version(), "TexStreamer.hh", 118,
                  typeid(::TEXTableCell), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXTableCell::Dictionary, isa_proxy, 4,
                  sizeof(::TEXTableCell) );
      instance.SetNew(&new_TEXTableCell);
      instance.SetNewArray(&newArray_TEXTableCell);
      instance.SetDelete(&delete_TEXTableCell);
      instance.SetDeleteArray(&deleteArray_TEXTableCell);
      instance.SetDestructor(&destruct_TEXTableCell);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXTableCell*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXTableCell*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXTableCell*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXTable(void *p = nullptr);
   static void *newArray_TEXTable(Long_t size, void *p);
   static void delete_TEXTable(void *p);
   static void deleteArray_TEXTable(void *p);
   static void destruct_TEXTable(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXTable*)
   {
      ::TEXTable *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXTable >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXTable", ::TEXTable::Class_Version(), "TexStreamer.hh", 125,
                  typeid(::TEXTable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXTable::Dictionary, isa_proxy, 4,
                  sizeof(::TEXTable) );
      instance.SetNew(&new_TEXTable);
      instance.SetNewArray(&newArray_TEXTable);
      instance.SetDelete(&delete_TEXTable);
      instance.SetDeleteArray(&deleteArray_TEXTable);
      instance.SetDestructor(&destruct_TEXTable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXTable*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXTable*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXTable*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXPage(void *p = nullptr);
   static void *newArray_TEXPage(Long_t size, void *p);
   static void delete_TEXPage(void *p);
   static void deleteArray_TEXPage(void *p);
   static void destruct_TEXPage(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXPage*)
   {
      ::TEXPage *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXPage >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXPage", ::TEXPage::Class_Version(), "TexStreamer.hh", 144,
                  typeid(::TEXPage), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXPage::Dictionary, isa_proxy, 4,
                  sizeof(::TEXPage) );
      instance.SetNew(&new_TEXPage);
      instance.SetNewArray(&newArray_TEXPage);
      instance.SetDelete(&delete_TEXPage);
      instance.SetDeleteArray(&deleteArray_TEXPage);
      instance.SetDestructor(&destruct_TEXPage);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXPage*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXPage*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXPage*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TEXDocument(void *p = nullptr);
   static void *newArray_TEXDocument(Long_t size, void *p);
   static void delete_TEXDocument(void *p);
   static void deleteArray_TEXDocument(void *p);
   static void destruct_TEXDocument(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TEXDocument*)
   {
      ::TEXDocument *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TEXDocument >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TEXDocument", ::TEXDocument::Class_Version(), "TexStreamer.hh", 178,
                  typeid(::TEXDocument), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TEXDocument::Dictionary, isa_proxy, 4,
                  sizeof(::TEXDocument) );
      instance.SetNew(&new_TEXDocument);
      instance.SetNewArray(&newArray_TEXDocument);
      instance.SetDelete(&delete_TEXDocument);
      instance.SetDeleteArray(&deleteArray_TEXDocument);
      instance.SetDestructor(&destruct_TEXDocument);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TEXDocument*)
   {
      return GenerateInitInstanceLocal(static_cast<::TEXDocument*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TEXDocument*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TexStreamer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TexStreamer::Class_Name()
{
   return "TexStreamer";
}

//______________________________________________________________________________
const char *TexStreamer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TexStreamer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TexStreamer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TexStreamer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TexStreamer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TexStreamer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TexStreamer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TexStreamer*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXFigure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXFigure::Class_Name()
{
   return "TEXFigure";
}

//______________________________________________________________________________
const char *TEXFigure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXFigure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXFigure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXFigure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXFigure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXFigure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXFigure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXFigure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXFormula::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXFormula::Class_Name()
{
   return "TEXFormula";
}

//______________________________________________________________________________
const char *TEXFormula::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXFormula*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXFormula::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXFormula*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXFormula::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXFormula*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXFormula::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXFormula*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXTableCell::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXTableCell::Class_Name()
{
   return "TEXTableCell";
}

//______________________________________________________________________________
const char *TEXTableCell::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXTableCell*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXTableCell::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXTableCell*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXTableCell::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXTableCell*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXTableCell::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXTableCell*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXTable::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXTable::Class_Name()
{
   return "TEXTable";
}

//______________________________________________________________________________
const char *TEXTable::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXTable*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXTable::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXTable*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXTable::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXTable*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXTable::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXTable*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXPage::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXPage::Class_Name()
{
   return "TEXPage";
}

//______________________________________________________________________________
const char *TEXPage::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXPage*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXPage::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXPage*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXPage::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXPage*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXPage::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXPage*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TEXDocument::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TEXDocument::Class_Name()
{
   return "TEXDocument";
}

//______________________________________________________________________________
const char *TEXDocument::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXDocument*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TEXDocument::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TEXDocument*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEXDocument::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXDocument*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEXDocument::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TEXDocument*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TexStreamer::Streamer(TBuffer &R__b)
{
   // Stream an object of class TexStreamer.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TVirtualPS::Streamer(R__b);
      R__b >> fXsize;
      R__b >> fYsize;
      R__b >> fType;
      R__b >> fBoundingBox;
      R__b >> fRange;
      R__b >> fStandalone;
      R__b >> fCurrentRed;
      R__b >> fCurrentGreen;
      R__b >> fCurrentBlue;
      R__b >> fCurrentAlpha;
      R__b >> fLineScale;
      R__b.StreamObject(&(Buff),typeid(Buff));
      R__b.StreamObject(&(TexStream),typeid(TexStream));
      { TString R__str; R__str.Streamer(R__b); Preamble = R__str.Data(); }
      { TString R__str; R__str.Streamer(R__b); PreambleType = R__str.Data(); }
      R__b.CheckByteCount(R__s, R__c, TexStreamer::IsA());
   } else {
      R__c = R__b.WriteVersion(TexStreamer::IsA(), kTRUE);
      TVirtualPS::Streamer(R__b);
      R__b << fXsize;
      R__b << fYsize;
      R__b << fType;
      R__b << fBoundingBox;
      R__b << fRange;
      R__b << fStandalone;
      R__b << fCurrentRed;
      R__b << fCurrentGreen;
      R__b << fCurrentBlue;
      R__b << fCurrentAlpha;
      R__b << fLineScale;
      R__b.StreamObject(&(Buff),typeid(Buff));
      R__b.StreamObject(&(TexStream),typeid(TexStream));
      { TString R__str = Preamble.c_str(); R__str.Streamer(R__b);}
      { TString R__str = PreambleType.c_str(); R__str.Streamer(R__b);}
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TexStreamer(void *p) {
      return  p ? new(p) ::TexStreamer : new ::TexStreamer;
   }
   static void *newArray_TexStreamer(Long_t nElements, void *p) {
      return p ? new(p) ::TexStreamer[nElements] : new ::TexStreamer[nElements];
   }
   // Wrapper around operator delete
   static void delete_TexStreamer(void *p) {
      delete (static_cast<::TexStreamer*>(p));
   }
   static void deleteArray_TexStreamer(void *p) {
      delete [] (static_cast<::TexStreamer*>(p));
   }
   static void destruct_TexStreamer(void *p) {
      typedef ::TexStreamer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TexStreamer(TBuffer &buf, void *obj) {
      ((::TexStreamer*)obj)->::TexStreamer::Streamer(buf);
   }
} // end of namespace ROOT for class ::TexStreamer

//______________________________________________________________________________
void TEXFigure::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXFigure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXFigure::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXFigure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXFigure(void *p) {
      return  p ? new(p) ::TEXFigure : new ::TEXFigure;
   }
   static void *newArray_TEXFigure(Long_t nElements, void *p) {
      return p ? new(p) ::TEXFigure[nElements] : new ::TEXFigure[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXFigure(void *p) {
      delete (static_cast<::TEXFigure*>(p));
   }
   static void deleteArray_TEXFigure(void *p) {
      delete [] (static_cast<::TEXFigure*>(p));
   }
   static void destruct_TEXFigure(void *p) {
      typedef ::TEXFigure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXFigure

//______________________________________________________________________________
void TEXFormula::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXFormula.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXFormula::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXFormula::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXFormula(void *p) {
      return  p ? new(p) ::TEXFormula : new ::TEXFormula;
   }
   static void *newArray_TEXFormula(Long_t nElements, void *p) {
      return p ? new(p) ::TEXFormula[nElements] : new ::TEXFormula[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXFormula(void *p) {
      delete (static_cast<::TEXFormula*>(p));
   }
   static void deleteArray_TEXFormula(void *p) {
      delete [] (static_cast<::TEXFormula*>(p));
   }
   static void destruct_TEXFormula(void *p) {
      typedef ::TEXFormula current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXFormula

//______________________________________________________________________________
void TEXTableCell::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXTableCell.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXTableCell::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXTableCell::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXTableCell(void *p) {
      return  p ? new(p) ::TEXTableCell : new ::TEXTableCell;
   }
   static void *newArray_TEXTableCell(Long_t nElements, void *p) {
      return p ? new(p) ::TEXTableCell[nElements] : new ::TEXTableCell[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXTableCell(void *p) {
      delete (static_cast<::TEXTableCell*>(p));
   }
   static void deleteArray_TEXTableCell(void *p) {
      delete [] (static_cast<::TEXTableCell*>(p));
   }
   static void destruct_TEXTableCell(void *p) {
      typedef ::TEXTableCell current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXTableCell

//______________________________________________________________________________
void TEXTable::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXTable.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXTable::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXTable::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXTable(void *p) {
      return  p ? new(p) ::TEXTable : new ::TEXTable;
   }
   static void *newArray_TEXTable(Long_t nElements, void *p) {
      return p ? new(p) ::TEXTable[nElements] : new ::TEXTable[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXTable(void *p) {
      delete (static_cast<::TEXTable*>(p));
   }
   static void deleteArray_TEXTable(void *p) {
      delete [] (static_cast<::TEXTable*>(p));
   }
   static void destruct_TEXTable(void *p) {
      typedef ::TEXTable current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXTable

//______________________________________________________________________________
void TEXPage::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXPage.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXPage::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXPage::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXPage(void *p) {
      return  p ? new(p) ::TEXPage : new ::TEXPage;
   }
   static void *newArray_TEXPage(Long_t nElements, void *p) {
      return p ? new(p) ::TEXPage[nElements] : new ::TEXPage[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXPage(void *p) {
      delete (static_cast<::TEXPage*>(p));
   }
   static void deleteArray_TEXPage(void *p) {
      delete [] (static_cast<::TEXPage*>(p));
   }
   static void destruct_TEXPage(void *p) {
      typedef ::TEXPage current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXPage

//______________________________________________________________________________
void TEXDocument::Streamer(TBuffer &R__b)
{
   // Stream an object of class TEXDocument.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TEXDocument::Class(),this);
   } else {
      R__b.WriteClassBuffer(TEXDocument::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TEXDocument(void *p) {
      return  p ? new(p) ::TEXDocument : new ::TEXDocument;
   }
   static void *newArray_TEXDocument(Long_t nElements, void *p) {
      return p ? new(p) ::TEXDocument[nElements] : new ::TEXDocument[nElements];
   }
   // Wrapper around operator delete
   static void delete_TEXDocument(void *p) {
      delete (static_cast<::TEXDocument*>(p));
   }
   static void deleteArray_TEXDocument(void *p) {
      delete [] (static_cast<::TEXDocument*>(p));
   }
   static void destruct_TEXDocument(void *p) {
      typedef ::TEXDocument current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TEXDocument

namespace ROOT {
   static TClass *vectorlEvectorlEstringgRsPgR_Dictionary();
   static void vectorlEvectorlEstringgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEstringgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEstringgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEstringgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEstringgRsPgR(void *p);
   static void destruct_vectorlEvectorlEstringgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<string> >*)
   {
      vector<vector<string> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<string> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<string> >", -2, "vector", 389,
                  typeid(vector<vector<string> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEstringgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<string> >) );
      instance.SetNew(&new_vectorlEvectorlEstringgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEstringgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEstringgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEstringgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEstringgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<string> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<string> >","std::vector<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::allocator<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<string> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEstringgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<string> >*>(nullptr))->GetClass();
      vectorlEvectorlEstringgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEstringgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEstringgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<string> > : new vector<vector<string> >;
   }
   static void *newArray_vectorlEvectorlEstringgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<string> >[nElements] : new vector<vector<string> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEstringgRsPgR(void *p) {
      delete (static_cast<vector<vector<string> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEstringgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<string> >*>(p));
   }
   static void destruct_vectorlEvectorlEstringgRsPgR(void *p) {
      typedef vector<vector<string> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<string> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 389,
                  typeid(vector<vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<double> >","std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<double> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<double> >*>(nullptr))->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete (static_cast<vector<vector<double> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] (static_cast<vector<vector<double> >*>(p));
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEvectorlETEXTableCellgRsPgR_Dictionary();
   static void vectorlEvectorlETEXTableCellgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlETEXTableCellgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlETEXTableCellgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlETEXTableCellgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlETEXTableCellgRsPgR(void *p);
   static void destruct_vectorlEvectorlETEXTableCellgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<TEXTableCell> >*)
   {
      vector<vector<TEXTableCell> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<TEXTableCell> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<TEXTableCell> >", -2, "vector", 389,
                  typeid(vector<vector<TEXTableCell> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlETEXTableCellgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<TEXTableCell> >) );
      instance.SetNew(&new_vectorlEvectorlETEXTableCellgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlETEXTableCellgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlETEXTableCellgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlETEXTableCellgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlETEXTableCellgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<TEXTableCell> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<TEXTableCell> >","std::vector<std::vector<TEXTableCell, std::allocator<TEXTableCell> >, std::allocator<std::vector<TEXTableCell, std::allocator<TEXTableCell> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<TEXTableCell> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlETEXTableCellgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<TEXTableCell> >*>(nullptr))->GetClass();
      vectorlEvectorlETEXTableCellgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlETEXTableCellgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlETEXTableCellgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<TEXTableCell> > : new vector<vector<TEXTableCell> >;
   }
   static void *newArray_vectorlEvectorlETEXTableCellgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<TEXTableCell> >[nElements] : new vector<vector<TEXTableCell> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlETEXTableCellgRsPgR(void *p) {
      delete (static_cast<vector<vector<TEXTableCell> >*>(p));
   }
   static void deleteArray_vectorlEvectorlETEXTableCellgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<TEXTableCell> >*>(p));
   }
   static void destruct_vectorlEvectorlETEXTableCellgRsPgR(void *p) {
      typedef vector<vector<TEXTableCell> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<TEXTableCell> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 389,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr))->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete (static_cast<vector<string>*>(p));
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] (static_cast<vector<string>*>(p));
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEpairlEstringcOunsignedsPintgRsPgR_Dictionary();
   static void vectorlEpairlEstringcOunsignedsPintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEpairlEstringcOunsignedsPintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p);
   static void destruct_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<string,unsigned int> >*)
   {
      vector<pair<string,unsigned int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<string,unsigned int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<string,unsigned int> >", -2, "vector", 389,
                  typeid(vector<pair<string,unsigned int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEstringcOunsignedsPintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<string,unsigned int> >) );
      instance.SetNew(&new_vectorlEpairlEstringcOunsignedsPintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEstringcOunsignedsPintgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEstringcOunsignedsPintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEstringcOunsignedsPintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEstringcOunsignedsPintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<string,unsigned int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<pair<string,unsigned int> >","std::vector<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, unsigned int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, unsigned int> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<pair<string,unsigned int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEstringcOunsignedsPintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<pair<string,unsigned int> >*>(nullptr))->GetClass();
      vectorlEpairlEstringcOunsignedsPintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEstringcOunsignedsPintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<string,unsigned int> > : new vector<pair<string,unsigned int> >;
   }
   static void *newArray_vectorlEpairlEstringcOunsignedsPintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<string,unsigned int> >[nElements] : new vector<pair<string,unsigned int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p) {
      delete (static_cast<vector<pair<string,unsigned int> >*>(p));
   }
   static void deleteArray_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p) {
      delete [] (static_cast<vector<pair<string,unsigned int> >*>(p));
   }
   static void destruct_vectorlEpairlEstringcOunsignedsPintgRsPgR(void *p) {
      typedef vector<pair<string,unsigned int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<pair<string,unsigned int> >

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 389,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETEXTableCellgR_Dictionary();
   static void vectorlETEXTableCellgR_TClassManip(TClass*);
   static void *new_vectorlETEXTableCellgR(void *p = nullptr);
   static void *newArray_vectorlETEXTableCellgR(Long_t size, void *p);
   static void delete_vectorlETEXTableCellgR(void *p);
   static void deleteArray_vectorlETEXTableCellgR(void *p);
   static void destruct_vectorlETEXTableCellgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXTableCell>*)
   {
      vector<TEXTableCell> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXTableCell>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXTableCell>", -2, "vector", 389,
                  typeid(vector<TEXTableCell>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXTableCellgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXTableCell>) );
      instance.SetNew(&new_vectorlETEXTableCellgR);
      instance.SetNewArray(&newArray_vectorlETEXTableCellgR);
      instance.SetDelete(&delete_vectorlETEXTableCellgR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXTableCellgR);
      instance.SetDestructor(&destruct_vectorlETEXTableCellgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXTableCell> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXTableCell>","std::vector<TEXTableCell, std::allocator<TEXTableCell> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXTableCell>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXTableCellgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXTableCell>*>(nullptr))->GetClass();
      vectorlETEXTableCellgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXTableCellgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXTableCellgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTableCell> : new vector<TEXTableCell>;
   }
   static void *newArray_vectorlETEXTableCellgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTableCell>[nElements] : new vector<TEXTableCell>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXTableCellgR(void *p) {
      delete (static_cast<vector<TEXTableCell>*>(p));
   }
   static void deleteArray_vectorlETEXTableCellgR(void *p) {
      delete [] (static_cast<vector<TEXTableCell>*>(p));
   }
   static void destruct_vectorlETEXTableCellgR(void *p) {
      typedef vector<TEXTableCell> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXTableCell>

namespace ROOT {
   static TClass *vectorlETEXTablegR_Dictionary();
   static void vectorlETEXTablegR_TClassManip(TClass*);
   static void *new_vectorlETEXTablegR(void *p = nullptr);
   static void *newArray_vectorlETEXTablegR(Long_t size, void *p);
   static void delete_vectorlETEXTablegR(void *p);
   static void deleteArray_vectorlETEXTablegR(void *p);
   static void destruct_vectorlETEXTablegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXTable>*)
   {
      vector<TEXTable> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXTable>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXTable>", -2, "vector", 389,
                  typeid(vector<TEXTable>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXTablegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXTable>) );
      instance.SetNew(&new_vectorlETEXTablegR);
      instance.SetNewArray(&newArray_vectorlETEXTablegR);
      instance.SetDelete(&delete_vectorlETEXTablegR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXTablegR);
      instance.SetDestructor(&destruct_vectorlETEXTablegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXTable> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXTable>","std::vector<TEXTable, std::allocator<TEXTable> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXTable>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXTablegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXTable>*>(nullptr))->GetClass();
      vectorlETEXTablegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXTablegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXTablegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTable> : new vector<TEXTable>;
   }
   static void *newArray_vectorlETEXTablegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTable>[nElements] : new vector<TEXTable>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXTablegR(void *p) {
      delete (static_cast<vector<TEXTable>*>(p));
   }
   static void deleteArray_vectorlETEXTablegR(void *p) {
      delete [] (static_cast<vector<TEXTable>*>(p));
   }
   static void destruct_vectorlETEXTablegR(void *p) {
      typedef vector<TEXTable> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXTable>

namespace ROOT {
   static TClass *vectorlETEXTablemUgR_Dictionary();
   static void vectorlETEXTablemUgR_TClassManip(TClass*);
   static void *new_vectorlETEXTablemUgR(void *p = nullptr);
   static void *newArray_vectorlETEXTablemUgR(Long_t size, void *p);
   static void delete_vectorlETEXTablemUgR(void *p);
   static void deleteArray_vectorlETEXTablemUgR(void *p);
   static void destruct_vectorlETEXTablemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXTable*>*)
   {
      vector<TEXTable*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXTable*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXTable*>", -2, "vector", 389,
                  typeid(vector<TEXTable*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXTablemUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXTable*>) );
      instance.SetNew(&new_vectorlETEXTablemUgR);
      instance.SetNewArray(&newArray_vectorlETEXTablemUgR);
      instance.SetDelete(&delete_vectorlETEXTablemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXTablemUgR);
      instance.SetDestructor(&destruct_vectorlETEXTablemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXTable*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXTable*>","std::vector<TEXTable*, std::allocator<TEXTable*> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXTable*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXTablemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXTable*>*>(nullptr))->GetClass();
      vectorlETEXTablemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXTablemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXTablemUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTable*> : new vector<TEXTable*>;
   }
   static void *newArray_vectorlETEXTablemUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXTable*>[nElements] : new vector<TEXTable*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXTablemUgR(void *p) {
      delete (static_cast<vector<TEXTable*>*>(p));
   }
   static void deleteArray_vectorlETEXTablemUgR(void *p) {
      delete [] (static_cast<vector<TEXTable*>*>(p));
   }
   static void destruct_vectorlETEXTablemUgR(void *p) {
      typedef vector<TEXTable*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXTable*>

namespace ROOT {
   static TClass *vectorlETEXPagegR_Dictionary();
   static void vectorlETEXPagegR_TClassManip(TClass*);
   static void *new_vectorlETEXPagegR(void *p = nullptr);
   static void *newArray_vectorlETEXPagegR(Long_t size, void *p);
   static void delete_vectorlETEXPagegR(void *p);
   static void deleteArray_vectorlETEXPagegR(void *p);
   static void destruct_vectorlETEXPagegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXPage>*)
   {
      vector<TEXPage> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXPage>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXPage>", -2, "vector", 389,
                  typeid(vector<TEXPage>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXPagegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXPage>) );
      instance.SetNew(&new_vectorlETEXPagegR);
      instance.SetNewArray(&newArray_vectorlETEXPagegR);
      instance.SetDelete(&delete_vectorlETEXPagegR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXPagegR);
      instance.SetDestructor(&destruct_vectorlETEXPagegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXPage> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXPage>","std::vector<TEXPage, std::allocator<TEXPage> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXPage>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXPagegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXPage>*>(nullptr))->GetClass();
      vectorlETEXPagegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXPagegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXPagegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXPage> : new vector<TEXPage>;
   }
   static void *newArray_vectorlETEXPagegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXPage>[nElements] : new vector<TEXPage>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXPagegR(void *p) {
      delete (static_cast<vector<TEXPage>*>(p));
   }
   static void deleteArray_vectorlETEXPagegR(void *p) {
      delete [] (static_cast<vector<TEXPage>*>(p));
   }
   static void destruct_vectorlETEXPagegR(void *p) {
      typedef vector<TEXPage> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXPage>

namespace ROOT {
   static TClass *vectorlETEXFormulagR_Dictionary();
   static void vectorlETEXFormulagR_TClassManip(TClass*);
   static void *new_vectorlETEXFormulagR(void *p = nullptr);
   static void *newArray_vectorlETEXFormulagR(Long_t size, void *p);
   static void delete_vectorlETEXFormulagR(void *p);
   static void deleteArray_vectorlETEXFormulagR(void *p);
   static void destruct_vectorlETEXFormulagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXFormula>*)
   {
      vector<TEXFormula> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXFormula>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXFormula>", -2, "vector", 389,
                  typeid(vector<TEXFormula>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXFormulagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXFormula>) );
      instance.SetNew(&new_vectorlETEXFormulagR);
      instance.SetNewArray(&newArray_vectorlETEXFormulagR);
      instance.SetDelete(&delete_vectorlETEXFormulagR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXFormulagR);
      instance.SetDestructor(&destruct_vectorlETEXFormulagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXFormula> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXFormula>","std::vector<TEXFormula, std::allocator<TEXFormula> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXFormula>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXFormulagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXFormula>*>(nullptr))->GetClass();
      vectorlETEXFormulagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXFormulagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXFormulagR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFormula> : new vector<TEXFormula>;
   }
   static void *newArray_vectorlETEXFormulagR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFormula>[nElements] : new vector<TEXFormula>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXFormulagR(void *p) {
      delete (static_cast<vector<TEXFormula>*>(p));
   }
   static void deleteArray_vectorlETEXFormulagR(void *p) {
      delete [] (static_cast<vector<TEXFormula>*>(p));
   }
   static void destruct_vectorlETEXFormulagR(void *p) {
      typedef vector<TEXFormula> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXFormula>

namespace ROOT {
   static TClass *vectorlETEXFormulamUgR_Dictionary();
   static void vectorlETEXFormulamUgR_TClassManip(TClass*);
   static void *new_vectorlETEXFormulamUgR(void *p = nullptr);
   static void *newArray_vectorlETEXFormulamUgR(Long_t size, void *p);
   static void delete_vectorlETEXFormulamUgR(void *p);
   static void deleteArray_vectorlETEXFormulamUgR(void *p);
   static void destruct_vectorlETEXFormulamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXFormula*>*)
   {
      vector<TEXFormula*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXFormula*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXFormula*>", -2, "vector", 389,
                  typeid(vector<TEXFormula*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXFormulamUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXFormula*>) );
      instance.SetNew(&new_vectorlETEXFormulamUgR);
      instance.SetNewArray(&newArray_vectorlETEXFormulamUgR);
      instance.SetDelete(&delete_vectorlETEXFormulamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXFormulamUgR);
      instance.SetDestructor(&destruct_vectorlETEXFormulamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXFormula*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXFormula*>","std::vector<TEXFormula*, std::allocator<TEXFormula*> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXFormula*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXFormulamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXFormula*>*>(nullptr))->GetClass();
      vectorlETEXFormulamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXFormulamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXFormulamUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFormula*> : new vector<TEXFormula*>;
   }
   static void *newArray_vectorlETEXFormulamUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFormula*>[nElements] : new vector<TEXFormula*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXFormulamUgR(void *p) {
      delete (static_cast<vector<TEXFormula*>*>(p));
   }
   static void deleteArray_vectorlETEXFormulamUgR(void *p) {
      delete [] (static_cast<vector<TEXFormula*>*>(p));
   }
   static void destruct_vectorlETEXFormulamUgR(void *p) {
      typedef vector<TEXFormula*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXFormula*>

namespace ROOT {
   static TClass *vectorlETEXFiguregR_Dictionary();
   static void vectorlETEXFiguregR_TClassManip(TClass*);
   static void *new_vectorlETEXFiguregR(void *p = nullptr);
   static void *newArray_vectorlETEXFiguregR(Long_t size, void *p);
   static void delete_vectorlETEXFiguregR(void *p);
   static void deleteArray_vectorlETEXFiguregR(void *p);
   static void destruct_vectorlETEXFiguregR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXFigure>*)
   {
      vector<TEXFigure> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXFigure>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXFigure>", -2, "vector", 389,
                  typeid(vector<TEXFigure>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXFiguregR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXFigure>) );
      instance.SetNew(&new_vectorlETEXFiguregR);
      instance.SetNewArray(&newArray_vectorlETEXFiguregR);
      instance.SetDelete(&delete_vectorlETEXFiguregR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXFiguregR);
      instance.SetDestructor(&destruct_vectorlETEXFiguregR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXFigure> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXFigure>","std::vector<TEXFigure, std::allocator<TEXFigure> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXFigure>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXFiguregR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXFigure>*>(nullptr))->GetClass();
      vectorlETEXFiguregR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXFiguregR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXFiguregR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFigure> : new vector<TEXFigure>;
   }
   static void *newArray_vectorlETEXFiguregR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFigure>[nElements] : new vector<TEXFigure>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXFiguregR(void *p) {
      delete (static_cast<vector<TEXFigure>*>(p));
   }
   static void deleteArray_vectorlETEXFiguregR(void *p) {
      delete [] (static_cast<vector<TEXFigure>*>(p));
   }
   static void destruct_vectorlETEXFiguregR(void *p) {
      typedef vector<TEXFigure> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXFigure>

namespace ROOT {
   static TClass *vectorlETEXFiguremUgR_Dictionary();
   static void vectorlETEXFiguremUgR_TClassManip(TClass*);
   static void *new_vectorlETEXFiguremUgR(void *p = nullptr);
   static void *newArray_vectorlETEXFiguremUgR(Long_t size, void *p);
   static void delete_vectorlETEXFiguremUgR(void *p);
   static void deleteArray_vectorlETEXFiguremUgR(void *p);
   static void destruct_vectorlETEXFiguremUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TEXFigure*>*)
   {
      vector<TEXFigure*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TEXFigure*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TEXFigure*>", -2, "vector", 389,
                  typeid(vector<TEXFigure*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETEXFiguremUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TEXFigure*>) );
      instance.SetNew(&new_vectorlETEXFiguremUgR);
      instance.SetNewArray(&newArray_vectorlETEXFiguremUgR);
      instance.SetDelete(&delete_vectorlETEXFiguremUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETEXFiguremUgR);
      instance.SetDestructor(&destruct_vectorlETEXFiguremUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TEXFigure*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TEXFigure*>","std::vector<TEXFigure*, std::allocator<TEXFigure*> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TEXFigure*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETEXFiguremUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TEXFigure*>*>(nullptr))->GetClass();
      vectorlETEXFiguremUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETEXFiguremUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETEXFiguremUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFigure*> : new vector<TEXFigure*>;
   }
   static void *newArray_vectorlETEXFiguremUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TEXFigure*>[nElements] : new vector<TEXFigure*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETEXFiguremUgR(void *p) {
      delete (static_cast<vector<TEXFigure*>*>(p));
   }
   static void deleteArray_vectorlETEXFiguremUgR(void *p) {
      delete [] (static_cast<vector<TEXFigure*>*>(p));
   }
   static void destruct_vectorlETEXFiguremUgR(void *p) {
      typedef vector<TEXFigure*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TEXFigure*>

namespace {
  void TriggerDictionaryInitialization_TexStreamer_Impl() {
    static const char* headers[] = {
"TexStreamer.hh",
"TexStreamerDict.h",
nullptr
    };
    static const char* includePaths[] = {
"/home/terawatt/Programs/root/root-install/include/",
"/home/terawatt/Programs/roottexstreamer/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TexStreamer dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TexStreamer;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXFigure;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXFormula;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXTableCell;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXTable;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXPage;
class __attribute__((annotate("$clingAutoload$TexStreamer.hh")))  TEXDocument;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TexStreamer dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TexStreamer.hh"
#include "TexStreamerDict.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TEXDocument", payloadCode, "@",
"TEXFigure", payloadCode, "@",
"TEXFormula", payloadCode, "@",
"TEXPage", payloadCode, "@",
"TEXTable", payloadCode, "@",
"TEXTableCell", payloadCode, "@",
"TexStreamer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TexStreamer",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TexStreamer_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TexStreamer_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TexStreamer() {
  TriggerDictionaryInitialization_TexStreamer_Impl();
}
