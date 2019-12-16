#include "cookerConv.h"
#include <iostream>
#include "trekvar.h"

mwpc::mwpc():usrEvtNo(0){
  mwpcInfo=new mwpcE36();
}
mwpc::~mwpc(){
}
void mwpc::beginRoot(std::string name){
  hfile=new TFile(name.c_str(),"RECREATE");
  tree = new TTree("tracks", "from mwpc");
  tree->SetAutoSave();
  tree->Branch("mwpInfo","mwpcE36",(TObject**)&mwpcInfo,256000,0);
}
void mwpc::writeRoot(){
  tree->Write();
  hfile->Write();
  hfile->Close();
}
void mwpc::convert(TFile* pFile){
  ptree=(TTree*)pFile->Get("tracks");
  // obtain variables from input ROOT files
  ptree->SetBranchAddress("run",&run);
  ptree->SetBranchAddress("event",&event);
  ptree->SetBranchAddress("nTracks",&nTracks);
  ptree->SetBranchAddress("fgapNumTof2",&fgapNumTof2);
  ptree->SetBranchAddress("nHits",&nHits);
  ptree->SetBranchAddress("fTof2SP",&fTof2SP);
  ptree->SetBranchAddress("fVertSP",&fVertSP);
  // Start filling the root tree and 
  // convert to the cooker version
  Int_t nentries=ptree->GetEntries();
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
    mwpcInfo->run=run;
    mwpcInfo->event=event;
    mwpcInfo->nTracks=nTracks;
    mwpcInfo->nHits=nHits;
    mwpcInfo->fgapNumTof2=fgapNumTof2;
    mwpcInfo->fTof2SP=fTof2SP;
    mwpcInfo->fVertSP=fVertSP;
    tree->Fill();
  }
  std::cout<<"************************************* "<<std::endl;
  std::cout<<"*******|   END OF CONVERTER   |****** "<<std::endl;
  std::cout<<"************************************* "<<std::endl;
}
