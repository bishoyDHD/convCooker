#include "cookerConv.h"
#include <iostream>
#include "trekvar.h"

Target::Target():usrEvtNo(0){
  tgtInfo=new targetE36();
}
Target::~Target(){
}
void Target::beginRoot(std::string name){
  hfile=new TFile(name.c_str(),"RECREATE");
  tree = new TTree("target", "from target");
  tree->SetAutoSave();
  tree->Branch("tgtInfo","targetE36",(TObject**)&tgtInfo,256000,0);
}
void Target::writeRoot(){
  tree->Write();
  hfile->Write();
  hfile->Close();
}
void Target::convert(TFile* pFile){
  ptree=(TTree*)pFile->Get("tree");
  // obtain variables from input ROOT files
  ptree->SetBranchAddress("run",&run);
  ptree->SetBranchAddress("eventNumber",&eventNumber);
  ptree->SetBranchAddress("eventFlag",&eventFlag);
  ptree->SetBranchAddress("TOF1Gap",&TOF1Gap);
  ptree->SetBranchAddress("TOF2Gap",&TOF2Gap);
  /*
  ptree->SetBranchAddress("extraTOF1",extraTOF1);
  ptree->SetBranchAddress("phiAngle",phiAngle);
  ptree->SetBranchAddress("deltaPhiAngle",deltaPhiAngle);
  ptree->SetBranchAddress("chiS",chiS);
  ptree->SetBranchAddress("ndf",ndf);
  ptree->SetBranchAddress("reducedChiS",reducedChiS);
  ptree->SetBranchAddress("leptonCounter",leptonCounter);
  ptree->SetBranchAddress("intersectTargetX",intersectTargetX);
  ptree->SetBranchAddress("intersectTargetY",intersectTargetY);
  ptree->SetBranchAddress("deltaX",deltaX);
  ptree->SetBranchAddress("deltaY",deltaY);
  ptree->SetBranchAddress("intersectSFTX",intersectSFTX);
  ptree->SetBranchAddress("intersectSFTY",intersectSFTY);
  ptree->SetBranchAddress("kaonCentroidX",kaonCentroidX);
  ptree->SetBranchAddress("kaonCentroidY",kaonCentroidY);
  ptree->SetBranchAddress("kaonCentroidXErr",kaonCentroidXErr);
  ptree->SetBranchAddress("kaonCentroidYErr",kaonCentroidYErr);
  ptree->SetBranchAddress("kaonStopIntersectX",kaonStopIntersectX);
  ptree->SetBranchAddress("kaonStopIntersectY",kaonStopIntersectY);
  ptree->SetBranchAddress("kaonStopX",kaonStopX);
  ptree->SetBranchAddress("kaonStopY",kaonStopY);
  //ptree->SetBranchAddress("kaonStopXEr",kaonStopXEr);
  //ptree->SetBranchAddress("kaonStopYEr",kaonStopYEr);
  ptree->SetBranchAddress("RKstop",RKstop);
  ptree->SetBranchAddress("kaonBarStop",kaonBarStop);
  ptree->SetBranchAddress("kaonClusterSize",kaonClusterSize);
  ptree->SetBranchAddress("kaonReducedChiS",kaonReducedChiS);
  ptree->SetBranchAddress("ckMultiplicity",ckMultiplicity);
  ptree->SetBranchAddress("cpiMultiplicity",cpiMultiplicity);
  ptree->SetBranchAddress("trackLength",trackLength);
  ptree->SetBranchAddress("C2XCentroid",C2XCentroid);
  ptree->SetBranchAddress("TDCDiff",TDCDiff);
  ptree->SetBranchAddress("sumADCHGLeptons",sumADCHGLeptons);
  ptree->SetBranchAddress("leptonAverageTDC",leptonAverageTDC);
  ptree->SetBranchAddress("kaonAverageTDC",kaonAverageTDC);
  ptree->SetBranchAddress("m_kaon",m_kaon);
  ptree->SetBranchAddress("Dm_kaon",Dm_kaon);
  ptree->SetBranchAddress("b_kaon",b_kaon);
  ptree->SetBranchAddress("Db_kaon",Db_kaon);
  ptree->SetBranchAddress("rho_kaon",rho_kaon);
  ptree->SetBranchAddress("C_kaon",C_kaon);
  ptree->SetBranchAddress("m_lepton",&m_lepton);
  ptree->SetBranchAddress("Dm_lepton",Dm_lepton);
  ptree->SetBranchAddress("b_lepton",b_lepton);
  ptree->SetBranchAddress("Db_lepton",Db_lepton);
  ptree->SetBranchAddress("rho_lepton",rho_lepton);
  ptree->SetBranchAddress("C_lepton",C_lepton);
  ptree->SetBranchAddress("hasEdgeBars",hasEdgeBars);
  ptree->SetBranchAddress("isGoodTOF1",isGoodTOF1);
  ptree->SetBranchAddress("pruningMethod",pruningMethod);
  ptree->SetBranchAddress("kStopType",kStopType);
  ptree->SetBranchAddress("caseNum",caseNum);
  ptree->SetBranchAddress("kstopErrFlag",kstopErrFlag);
  ptree->SetBranchAddress("badEventFlag",badEventFlag);*/
  // Start filling the root tree and 
  // convert to the cooker version
  Int_t nentries=ptree->GetEntries();
  int badEvt=0;
  if(usrEvtNo!=0) nentries=usrEvtNo;
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
    tgtInfo->run=run;
    tgtInfo->eventNumber=eventNumber;
    tgtInfo->eventFlag=eventFlag;
    if(TOF1Gap!=0 && TOF2Gap!=0){
      tgtInfo->TOF1Gap=TOF1Gap;
      tgtInfo->TOF2Gap=TOF2Gap;
    }else{
      tgtInfo->TOF1Gap=dummy;
      tgtInfo->TOF2Gap=dummy;
      badEvt++;
    }
    tree->Fill();
  }
  std::cout<<"  Number of bad events: "<<badEvt<<std::endl;
}
