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
class kekcc: public CRTBase{
public:
  // Declaration of leaf types
  Int_t   runnum;
  Int_t   ievent;
  Int_t   runtype;
  Int_t   mode;
  Int_t   mc_evid;
  Int_t   trigtype[3];
  Int_t   fidg;
  Int_t   TF1g;
  Int_t   TF2g;
  Float_t mc_part_ab[30];
  Int_t   mc_procfl[5];
  Float_t mc_pos[3];
  Float_t ktime;
  Float_t kfib[2];
  Int_t   gd_tgkcl;
  Int_t   gd_tgtgkdis;
  Float_t tgpath;
  Float_t vtex[3];
  Int_t   nfib;
  Float_t tginfor[100][3];
  Int_t   tginfoi[100][3];
  Int_t   ex_trver;
  Int_t   vertr;
  Float_t trchi2;
  Float_t c2_pos[3];
  Float_t c3_pos[3];
  Float_t c4_pos[3];
  Float_t dfid[3];
  Float_t dtf2[3];
  Float_t trsft[3];
  Float_t trac[3];
  Float_t trfidfib[3];
  Float_t p_gap;
  Float_t pmu;
  Float_t ppi;
  Float_t calfidt;
  Float_t toft;
  Float_t flen;
  Float_t mass;
  Float_t act;
  Float_t acadc;
  Float_t act_u[12];
  Float_t act_d[12];
  Float_t acadc_u[12];
  Float_t acadc_d[12];
  Float_t pgct;
  Float_t pgcadc;
  Float_t chie;
  Float_t chim;
  Double_t mass2;
  kekcc();
  virtual ~kekcc();
  ClassDef(kekcc,2);
};
#endif
