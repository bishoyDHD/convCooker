#include "cookerConv.h"
#include "trekvar.h"

Target::Target():usrEvtNo(0){
  tgtInfo=new TargetInfo();
}
Target::~Target(){
}
void Target::beginRoot(std::string name){
  hfile=new TFile(name.c_str());
  tree = new TTree("target", "E36 MC");
  tree->Branch("tgtInfo","TargeInfo",(TObject**)&tgtInfo,256000,0);
}
void Target::writeRoot(){
  hfile->Close();
  hfile->Write();
}
void Target::evtLoop(TFile* pFile){
  ptree=(TTree*)pFile->Get("tree");
  // obtain variables from input ROOT files
  ptree->SetBranchAddress("run",&run);
  ptree->SetBranchAddress("event",&eventNumber);
  ptree->SetBranchAddress("eventFlag",&eventFlag);
  ptree->SetBranchAddress("TOF1Gap",&TOF1Gap);
  ptree->SetBranchAddress("TOF2Gap",&TOF2Gap);
  ptree->SetBranchAddress("extraTOF1",&extraTOF1);
  ptree->SetBranchAddress("phiAngle",&phiAngle);
  ptree->SetBranchAddress("deltaPhiAngle",&deltaPhiAngle);
  ptree->SetBranchAddress("chiS",&chiS);
  ptree->SetBranchAddress("ndf",&ndf);
  ptree->SetBranchAddress("reducedChiS",&reducedChiS);
  ptree->SetBranchAddress("leptonCounter",&leptonCounter);
  ptree->SetBranchAddress("intersectTargetX",&intersectTargetX);
  ptree->SetBranchAddress("intersectTargetY",&intersectTargetY);
  ptree->SetBranchAddress("deltaX",&deltaX);
  ptree->SetBranchAddress("deltaY",&deltaY);
  ptree->SetBranchAddress("intersectSFTX",&intersectSFTX);
  ptree->SetBranchAddress("intersectSFTY",&intersectSFTY);
  ptree->SetBranchAddress("kaonCentroidX",&kaonCentroidX);
  ptree->SetBranchAddress("kaonCentroidY",&kaonCentroidY);
  ptree->SetBranchAddress("kaonCentroidXErr",&kaonCentroidXErr);
  ptree->SetBranchAddress("kaonCentroidYErr",&kaonCentroidYErr);
  ptree->SetBranchAddress("kaonStopIntersectX",&kaonStopIntersectX);
  ptree->SetBranchAddress("kaonStopIntersectY",&kaonStopIntersectY);
  ptree->SetBranchAddress("kaonStopX",&kaonStopX);
  ptree->SetBranchAddress("kaonStopY",&kaonStopY);
  ptree->SetBranchAddress("kaonStopXEr",&kaonStopXEr);
  ptree->SetBranchAddress("kaonStopYEr",&kaonStopXEr);
  ptree->SetBranchAddress("RKstop",&RKstop);
  ptree->SetBranchAddress("kaonBarStop",&kaonBarStop);
  ptree->SetBranchAddress("kaonClusterSize",&kaonClusterSize);
  ptree->SetBranchAddress("kaonReducedChiS",&kaonReducedChiS);
  ptree->SetBranchAddress("ckMultiplicity",&ckMultiplicity);
  ptree->SetBranchAddress("cpiMultiplicity",&cpiMultiplicity);
  ptree->SetBranchAddress("trackLength",&trackLength);
  ptree->SetBranchAddress("C2XCentroid",&C2XCentroid);
  ptree->SetBranchAddress("TDCDiff",&TDCDiff);
  ptree->SetBranchAddress("sumADCHGLeptons",&sumADCHGLeptons);
  ptree->SetBranchAddress("leptonAverageTDC",&leptonAverageTDC);
  ptree->SetBranchAddress("kaonAverageTDC",&kaonAverageTDC);
  ptree->SetBranchAddress("m_kaon",&m_kaon);
  ptree->SetBranchAddress("Dm_kaon",&Dm_kaon);
  ptree->SetBranchAddress("b_kaon",&b_kaon);
  ptree->SetBranchAddress("Db_kaon",&Db_kaon);
  ptree->SetBranchAddress("rho_kaon",&rho_kaon);
  ptree->SetBranchAddress("C_kaon",&C_kaon);
  ptree->SetBranchAddress("m_lepton",&m_lepton);
  ptree->SetBranchAddress("Dm_lepton",&Dm_lepton);
  ptree->SetBranchAddress("b_lepton",&b_lepton);
  ptree->SetBranchAddress("Db_lepton",&Db_lepton);
  ptree->SetBranchAddress("rho_lepton",&rho_lepton);
  ptree->SetBranchAddress("C_lepton",&C_lepton);
  ptree->SetBranchAddress("hasEdgeBars",&hasEdgeBars);
  ptree->SetBranchAddress("isGoodTOF1",&isGoodTOF1);
  ptree->SetBranchAddress("pruningMethod",&pruningMethod);
  ptree->SetBranchAddress("kStopType",&kStopType);
  ptree->SetBranchAddress("caseNum",&caseNum);
  ptree->SetBranchAddress("kstopErrFlag",&kstopErrFlag);
  ptree->SetBranchAddress("badEventFlag",&badEventFlag);
  // Start filling the root tree and 
  // convert to the cooker version
  Int_t nentries=ptree->GetEntries();
  if(usrEvtNo!=0) nentries=usrEvtNo;
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
  }
}
