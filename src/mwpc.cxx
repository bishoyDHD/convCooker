#include "cookerConv.h"
#include <iostream>
#include "trekvar.h"

mwpc::mwpc():usrEvtNo(0){
  mwpcInfo=new mwpcE36();
  ptree=NULL;
}
mwpc::~mwpc(){
  std::cout<<"*********************************\n";
  std::cout<<" ---- Exiting MWPC converter ----\n";
  std::cout<<"*********************************\n";
}
void mwpc::beginRoot(std::string name){
  hfile=new TFile(name.c_str(),"RECREATE");
  tree = new TTree("tracks", "from mwpc");
  tree->SetAutoSave();
  tree->Branch("mwpcInfo","mwpcE36",(TObject**)&mwpcInfo,256000,0);
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
  ptree->SetBranchAddress("fTof1SP",&fTof1SP);
  ptree->SetBranchAddress("fVertSP",&fVertSP);
  ptree->SetBranchAddress("fSftSNx",&fSftSNx);
  ptree->SetBranchAddress("fSftSNy",&fSftSNy);
  ptree->SetBranchAddress("fSftSNz",&fSftSNz);
  ptree->SetBranchAddress("fVertMPhi",&fVertMPhi);
  // Start filling the root tree and 
  // convert to the cooker version
  Int_t nentries=ptree->GetEntries();
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
    mwpcInfo->run=run;
    mwpcInfo->event=event;
    mwpcInfo->nTracks=nTracks;
    mwpcInfo->nHits=nHits;
    mwpcInfo->fgapNumTof2=(fgapNumTof2+1);
    mwpcInfo->fTof2SP=fTof2SP;
    mwpcInfo->fTof1SP=fTof1SP;
    mwpcInfo->fVertSP=fVertSP;
    mwpcInfo->fSftSNx=fSftSNx;
    mwpcInfo->fSftSNy=fSftSNy;
    mwpcInfo->fSftSNz=fSftSNz;
    mwpcInfo->fVertMPhi=fVertMPhi;
    tree->Fill();
  }
  std::cout<<"************************************* "<<std::endl;
  std::cout<<"*******|   END OF CONVERTER   |****** "<<std::endl;
  std::cout<<"************************************* "<<std::endl;
}
