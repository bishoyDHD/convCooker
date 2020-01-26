#ifndef cookerConv_h
#define cookerConv_h 1

#include <TObject.h>
#include <vector>
//const int maxEvt=151212;
class CRTBase: public TObject{
 public:
  CRTBase();
  virtual ~CRTBase();
  ClassDef(CRTBase,1);
};

class targetE36: public CRTBase {
public:
  UInt_t run;
  UInt_t eventNumber;
  UInt_t eventFlag;
  Int_t TOF1Gap;
  Int_t TOF2Gap;
  //Int_t extraTOF1;
  Int_t extraTOF1_size;
  std::vector<Int_t> *extraTOF1=0;
  std::vector<std::vector<Int_t>> *vec_extraTOF1=0;
  Float_t phiAngle;
  Float_t deltaPhiAngle;
  Int_t badEventFlag;
  targetE36();
  virtual ~targetE36();
  ClassDef(targetE36,2);
};
class mwpcE36: public CRTBase{
public:
  UInt_t run ;
  UInt_t event;
  Int_t nTracks;
  Int_t fgapNumTof2;
  Int_t nHits;
  Double_t fTof2SP;
  Double_t fTof1SP;
  Double_t fVertSP;
  Double_t fSftSNx;
  Double_t fSftSNy;
  Double_t fSftSNz;
  Double_t fVertMPhi;
  mwpcE36();
  virtual ~mwpcE36();
  ClassDef(mwpcE36,2);
};
#endif
