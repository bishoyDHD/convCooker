#ifndef trekvar_h
#define trekvar_h 1

#include <TTree.h>
#include <TFile.h>
#include <vector>

class Target{
public:
  Target();
  virtual ~Target();
  void beginRoot(std::string);
  void writeRoot();
  void evtLoop(TFile*);
  void setEvtNo(int);
private:
  TargetInfo* tgtInfo;
  TTree* tree,*ptree;
  TFile* hfile;
  std::string fname;
  Int_t usrEvtNo;
  Int_t run;
  Int_t eventNumber;
  Int_t eventFlag;
  Int_t TOF1Gap;
  Int_t TOF2Gap;
  Int_t extraTOF1;
  Double_t phiAngle;
  Double_t deltaPhiAngle;
  Double_t chiS;
  Int_t ndf;
  Double_t reducedChiS;
  Int_t leptonCounter;
  Double_t intersectTargetX;
  Double_t intersectTargetY;
  Double_t deltaX;
  Double_t deltaY;
  Double_t intersectSFTX;
  Double_t intersectSFTY;
  Double_t kaonCentroidX;
  Double_t kaonCentroidY;
  Double_t kaonCentroidXErr;
  Double_t kaonCentroidYErr;
  Double_t kaonStopIntersectX;
  Double_t kaonStopIntersectY;
  Double_t kaonStopX;
  Double_t kaonStopY;
  Double_t kaonStopXEr;
  Double_t kaonStopYEr;
  Double_t RKstop;
  Int_t kaonBarStop;
  Int_t kaonClusterSize;
  Double_t kaonReducedChiS;
  Int_t ckMultiplicity;
  Int_t cpiMultiplicity;
  Double_t trackLength;
  Double_t C2XCentroid;
  Double_t TDCDiff;
  Double_t sumADCHGLeptons;
  Double_t leptonAverageTDC;
  Double_t kaonAverageTDC;
  Double_t m_kaon;
  Double_t Dm_kaon;
  Double_t b_kaon;
  Double_t Db_kaon;
  Double_t rho_kaon;
  Double_t C_kaon;
  Double_t m_lepton;
  Double_t Dm_lepton;
  Double_t b_lepton;
  Double_t Db_lepton;
  Double_t rho_lepton;
  Double_t C_lepton;
  Int_t hasEdgeBars;
  Int_t isGoodTOF1;
  Int_t pruningMethod;
  Int_t kStopType;
  Int_t caseNum;
  Int_t kstopErrFlag;
  Int_t badEventFlag;
};
#endif
