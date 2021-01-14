#include "cookerConv.h"                                                           
#include <iostream>
#include "trekvar.h"

tofM2::tofM2():usrEvtNo(0){
  m2Info=new trekM2();
  ptree=NULL;
}
tofM2::~tofM2(){
  std::cout<<"**********************************\n";
  std::cout<<" ---- Exiting TOFM2 converter ----\n";
  std::cout<<"**********************************\n";
}
void tofM2::beginRoot(std::string name){
  hfile=new TFile(name.c_str(),"RECREATE");
  tree = new TTree("tofM2", "from tofM2");
  tree->SetAutoSave();
  tree->Branch("m2Info","trekM2",(TObject**)&m2Info,256000,0);
}
void tofM2::writeRoot(){
  tree->Write();
  hfile->Write();
  hfile->Close();
}
void tofM2::convert(TFile* pFile){
  ptree=(TTree*)pFile->Get("Tof_M2");
  // obtain variables from input ROOT files
  ptree->SetBranchAddress("run",&run);
  ptree->SetBranchAddress("event",&event);
  ptree->SetBranchAddress("gapToF1",&gapToF1);
  ptree->SetBranchAddress("gapToF2",&gapToF2);
  ptree->SetBranchAddress("M2",&M2);
  ptree->SetBranchAddress("vert_p",&vert_p);
  ptree->SetBranchAddress("beta",&beta);
  ptree->SetBranchAddress("Ep",&Ep);
  // Start filling the root tree and
  // convert to the cooker version
  Int_t nentries=ptree->GetEntries();
  int badEvt=0;
  if(usrEvtNo!=0) nentries=usrEvtNo;
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
    m2Info->run=run;
    m2Info->event=event;
    m2Info->gapToF1=gapToF1;
    m2Info->gapToF2=gapToF2;
    m2Info->M2=M2;
    m2Info->vert_p=vert_p;
    m2Info->beta=beta;
    m2Info->Ep=Ep;
  }
}
