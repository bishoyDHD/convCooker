#ifndef trekvar_h
#define trekvar_h 1

#include "cookerConv.h"
#include <TTree.h>
#include <TFile.h>
#include <vector>

class Target{
public:
  Target();
  virtual ~Target();
  void beginRoot(std::string);
  void writeRoot();
  void convert(TFile*);
  void setEvtNo(int);
private:
  int dummy=-1000;
  targetE36* tgtInfo;
  TTree* tree,*ptree;
  TFile* hfile;
  std::string fname;
  Int_t usrEvtNo;
  Int_t run;
  Int_t eventNumber;
  Int_t eventFlag;
  Int_t TOF1Gap;
  Int_t TOF2Gap;
  //Int_t extraTOF1;
  Int_t extraTOF1_size;
  std::vector<Int_t> *extraTOF1=0;
  std::vector<std::vector<Int_t>> *vec_extraTOF1=0;
  Float_t phiAngle;
  Float_t deltaPhiAngle;
  /*
  Float_t chiS;
  Int_t ndf;
  Float_t reducedChiS;
  Int_t leptonCounter;
  Float_t intersectTargetX;
  Float_t intersectTargetY;
  Float_t deltaX;
  Float_t deltaY;
  Float_t intersectSFTX;
  Float_t intersectSFTY;
  Float_t kaonCentroidX;
  Float_t kaonCentroidY;
  Float_t kaonCentroidXErr;
  Float_t kaonCentroidYErr;
  Float_t kaonStopIntersectX;
  Float_t kaonStopIntersectY;
  Float_t kaonStopX;
  Float_t kaonStopY;
  Float_t kaonStopXEr;
  Float_t kaonStopYEr;
  Float_t RKstop;
  Int_t kaonBarStop;
  Int_t kaonClusterSize;
  Float_t kaonReducedChiS;
  Int_t ckMultiplicity;
  Int_t cpiMultiplicity;
  Float_t trackLength;
  Float_t C2XCentroid;
  Float_t TDCDiff;
  Int_t sumADCHGLeptons;
  Float_t leptonAverageTDC;
  Float_t kaonAverageTDC;
  Float_t m_kaon;
  Float_t Dm_kaon;
  Float_t b_kaon;
  Float_t Db_kaon;
  Float_t rho_kaon;
  Float_t C_kaon;
  Float_t m_lepton;
  Float_t Dm_lepton;
  Float_t b_lepton;
  Float_t Db_lepton;
  Float_t rho_lepton;
  Float_t C_lepton;
  Bool_t hasEdgeBars;
  Bool_t isGoodTOF1;
  Int_t pruningMethod;
  Int_t kStopType;
  Int_t caseNum;
  Int_t kstopErrFlag;*/
  Int_t badEventFlag;
};
class mwpc{
public:
  mwpc();
  ~mwpc();
  void beginRoot(std::string);
  void writeRoot();
  void convert(TFile*);
  void setEvtNo(int);
private:
  int dummy=-1000;
  mwpcE36* mwpcInfo;
  TTree* tree,*ptree;
  TFile* hfile;
  std::string fname;
  UInt_t usrEvtNo;
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
  Double_t fVertMPhi; // compare with target phi
};
class tofM2{
public:
  tofM2();
  ~tofM2();
  void beginRoot(std::string);
  void writeRoot();
  void convert(TFile*);
  void setEvtNo(int);
private:
  int dummy=-1000;
  std::string fname;
  UInt_t usrEvtNo;
  trekM2* m2Info;
  TTree* tree,*ptree;
  TFile* hfile;
  Int_t           run;
  Int_t           event;
  std::vector<int>     *gapToF1;
  std::vector<int>     *gapToF2;
  std::vector<double>  *M2;
  std::vector<double>  *vert_p;
  std::vector<double>  *beta;
  std::vector<double>  *Ep;
};
#endif
