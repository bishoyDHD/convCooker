#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TNetFile.h"
#include "TRandom.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLine.h"
#include "TApplication.h"
#include "TBenchmark.h"
#include "target.h"
#define _USE_MATH_DEFINES

//static TApplication *app = new TApplication("App", NULL, NULL);
int main(){
  // Read in existing ROOT file
  TFile* rootFile=new TFile("/data/trek/E36/bishoy/sandBox/outputKFTracking/run3994.root"); // root file
  TTree* tree=(TTree*)rootFile->Get("tracks"); // tree in file
/*
  Int_t run,event; // run number and event number
  tree->SetBranchAddress("run",&run);
  tree->SetBranchAddress("event",&event);
  Int_t nTracks=2000; // number of tracks for an event
  tree->SetBranchAddress("nTracks",&nTracks);

  //-----------------------------------Muon---------------------------------------//
  //// For every hit of an event
  Int_t nHits[nTracks]; // number of hits (position detctors) are used to constrcut 
  Double_t chi2PerNDF[nTracks]; // chi2/NDF
  Int_t flagTargetToAC[nTracks]; // flag of layer from target to AC
  Bool_t flagTofMatch[nTracks]; // flag to identify if gap numbers of ToF1 and ToF2 match with each other (difference of gap numbers = 0 or +/-1)
  tree->SetBranchAddress("nHits",nHits);
  tree->SetBranchAddress("chi2PerNDF",chi2PerNDF);
  tree->SetBranchAddress("flagTargetToAC",flagTargetToAC);
  tree->SetBranchAddress("flagTofMatch",flagTofMatch);

  Double_t sMwpc4[nTracks]; // path location at C4
  Double_t tMwpc4[nTracks]; // path time at C4
  Double_t mXMwpc4[nTracks]; // x measurement at C4
  Double_t mYMwpc4[nTracks]; // y measurement at C4
  Double_t mZMwpc4[nTracks]; // location at C4 
  Double_t mXErrMwpc4[nTracks]; // error of x measurement at C4
  Double_t mYErrMwpc4[nTracks]; // error of y measurement at C4
  Double_t mZErrMwpc4[nTracks]; // 0.01 mm 
  Double_t xMwpc4[nTracks]; // x at C4 from tracking
  Double_t yMwpc4[nTracks]; // y at C4 from tracking
  Double_t zMwpc4[nTracks]; // z at C4 from tracking
  Double_t nXMwpc4[nTracks]; // x direction (nx) at C4 from tracking
  Double_t nYMwpc4[nTracks]; // y direction (ny) at C4 from tracking
  Double_t nZMwpc4[nTracks]; // z direction (nz) at C4 from tracking
  Double_t pMwpc4[nTracks]; // momentum at C4 from tracking
  tree->SetBranchAddress("sMwpc4",sMwpc4);
  tree->SetBranchAddress("tMwpc4",tMwpc4);
  tree->SetBranchAddress("mXMwpc4",mXMwpc4);
  tree->SetBranchAddress("mYMwpc4",mYMwpc4);
  tree->SetBranchAddress("mZMwpc4",mZMwpc4);
  tree->SetBranchAddress("mXErrMwpc4",mXErrMwpc4);
  tree->SetBranchAddress("mYErrMwpc4",mYErrMwpc4);
  tree->SetBranchAddress("mZErrMwpc4",mZErrMwpc4);
  tree->SetBranchAddress("xMwpc4",xMwpc4);
  tree->SetBranchAddress("yMwpc4",yMwpc4);
  tree->SetBranchAddress("zMwpc4",zMwpc4);
  tree->SetBranchAddress("nXMwpc4",nXMwpc4);
  tree->SetBranchAddress("nYMwpc4",nYMwpc4);
  tree->SetBranchAddress("nZMwpc4",nZMwpc4);
  tree->SetBranchAddress("pMwpc4",pMwpc4);

  Double_t sMwpc3[nTracks];
  Double_t tMwpc3[nTracks];
  Double_t mXMwpc3[nTracks];
  Double_t mYMwpc3[nTracks];
  Double_t mZMwpc3[nTracks];
  Double_t mXErrMwpc3[nTracks];
  Double_t mYErrMwpc3[nTracks];
  Double_t mZErrMwpc3[nTracks];
  Double_t xMwpc3[nTracks];
  Double_t yMwpc3[nTracks];
  Double_t zMwpc3[nTracks];
  Double_t nXMwpc3[nTracks];
  Double_t nYMwpc3[nTracks];
  Double_t nZMwpc3[nTracks];
  Double_t pMwpc3[nTracks];
  tree->SetBranchAddress("sMwpc3",sMwpc3);
  tree->SetBranchAddress("tMwpc3",tMwpc3);
  tree->SetBranchAddress("mXMwpc3",mXMwpc3);
  tree->SetBranchAddress("mYMwpc3",mYMwpc3);
  tree->SetBranchAddress("mZMwpc3",mZMwpc3);
  tree->SetBranchAddress("mXErrMwpc3",mXErrMwpc3);
  tree->SetBranchAddress("mYErrMwpc3",mYErrMwpc3);
  tree->SetBranchAddress("mZErrMwpc3",mZErrMwpc3);
  tree->SetBranchAddress("xMwpc3",xMwpc3);
  tree->SetBranchAddress("yMwpc3",yMwpc3);
  tree->SetBranchAddress("zMwpc3",zMwpc3);
  tree->SetBranchAddress("nXMwpc3",nXMwpc3);
  tree->SetBranchAddress("nYMwpc3",nYMwpc3);
  tree->SetBranchAddress("nZMwpc3",nZMwpc3);
  tree->SetBranchAddress("pMwpc3",pMwpc3);

  Double_t sMwpc2[nTracks];
  Double_t tMwpc2[nTracks];
  Double_t mXMwpc2[nTracks];
  Double_t mYMwpc2[nTracks];
  Double_t mZMwpc2[nTracks];
  Double_t mXErrMwpc2[nTracks];
  Double_t mYErrMwpc2[nTracks];
  Double_t mZErrMwpc2[nTracks];
  Double_t xMwpc2[nTracks];
  Double_t yMwpc2[nTracks];
  Double_t zMwpc2[nTracks];
  Double_t nXMwpc2[nTracks];
  Double_t nYMwpc2[nTracks];
  Double_t nZMwpc2[nTracks];
  Double_t pMwpc2[nTracks];
  tree->SetBranchAddress("sMwpc2",sMwpc2);
  tree->SetBranchAddress("tMwpc2",tMwpc2);
  tree->SetBranchAddress("mXMwpc2",mXMwpc2);
  tree->SetBranchAddress("mYMwpc2",mYMwpc2);
  tree->SetBranchAddress("mZMwpc2",mZMwpc2);
  tree->SetBranchAddress("mXErrMwpc2",mXErrMwpc2);
  tree->SetBranchAddress("mYErrMwpc2",mYErrMwpc2);
  tree->SetBranchAddress("mZErrMwpc2",mZErrMwpc2);
  tree->SetBranchAddress("xMwpc2",xMwpc2);
  tree->SetBranchAddress("yMwpc2",yMwpc2);
  tree->SetBranchAddress("zMwpc2",zMwpc2);
  tree->SetBranchAddress("nXMwpc2",nXMwpc2);
  tree->SetBranchAddress("nYMwpc2",nYMwpc2);
  tree->SetBranchAddress("nZMwpc2",nZMwpc2);
  tree->SetBranchAddress("pMwpc2",pMwpc2);

  Int_t gapNumTof2[nTracks];
  Double_t sTof2[nTracks];
  Double_t tTof2[nTracks];
  Double_t timeITof2[nTracks];
  Double_t timeOTof2[nTracks];
  Double_t timeMeanTof2[nTracks];
  Double_t xTof2[nTracks];
  Double_t yTof2[nTracks];
  Double_t zTof2[nTracks];
  Double_t nXTof2[nTracks];
  Double_t nYTof2[nTracks];
  Double_t nZTof2[nTracks];
  Double_t pTof2[nTracks];
  tree->SetBranchAddress("gapNumTof2",gapNumTof2);
  tree->SetBranchAddress("sTof2",sTof2);
  tree->SetBranchAddress("tTof2",tTof2);
  tree->SetBranchAddress("timeITof2",timeITof2);
  tree->SetBranchAddress("timeOTof2",timeOTof2);
  tree->SetBranchAddress("timeMeanTof2",timeMeanTof2);
  tree->SetBranchAddress("xTof2",xTof2);
  tree->SetBranchAddress("yTof2",yTof2);
  tree->SetBranchAddress("zTof2",zTof2);
  tree->SetBranchAddress("nXTof2",nXTof2);
  tree->SetBranchAddress("nYTof2",nYTof2);
  tree->SetBranchAddress("nZTof2",nZTof2);
  tree->SetBranchAddress("pTof2",pTof2);

  Int_t gapNumTof1[nTracks];
  Double_t sTof1[nTracks];
  Double_t tTof1[nTracks];
  Double_t timeUTof1[nTracks];
  Double_t timeDTof1[nTracks];
  Double_t timeMeanTof1[nTracks];
  Double_t xTof1[nTracks];
  Double_t yTof1[nTracks];
  Double_t zTof1[nTracks];
  Double_t nXTof1[nTracks];
  Double_t nYTof1[nTracks];
  Double_t nZTof1[nTracks];
  Double_t pTof1[nTracks];
  tree->SetBranchAddress("gapNumTof1",gapNumTof1);
  tree->SetBranchAddress("sTof1",sTof1);
  tree->SetBranchAddress("tTof1",tTof1);
  tree->SetBranchAddress("timeUTof1",timeUTof1);
  tree->SetBranchAddress("timeDTof1",timeDTof1);
  tree->SetBranchAddress("timeMeanTof1",timeMeanTof1);
  tree->SetBranchAddress("xTof1",xTof1);
  tree->SetBranchAddress("yTof1",yTof1);
  tree->SetBranchAddress("zTof1",zTof1);
  tree->SetBranchAddress("nXTof1",nXTof1);
  tree->SetBranchAddress("nYTof1",nYTof1);
  tree->SetBranchAddress("nZTof1",nZTof1);
  tree->SetBranchAddress("pTof1",pTof1);


  Double_t xSft[nTracks];
  Double_t ySft[nTracks];
  Double_t zSft[nTracks];
  Double_t nXSft[nTracks];
  Double_t nYSft[nTracks];
  Double_t nZSft[nTracks];
  Double_t pSft[nTracks];
  tree->SetBranchAddress("xSft",xSft);
  tree->SetBranchAddress("ySft",ySft);
  tree->SetBranchAddress("zSft",zSft);
  tree->SetBranchAddress("nXSft",nXSft);
  tree->SetBranchAddress("nYSft",nYSft);
  tree->SetBranchAddress("nZSft",nZSft);
  tree->SetBranchAddress("pSft",pSft);

  Double_t sVert[nTracks];
  Double_t tVert[nTracks];
  Double_t mXVert[nTracks];
  Double_t mYVert[nTracks];
  Double_t mPhiVert[nTracks];
  Double_t mXErrVert[nTracks];
  Double_t mYErrVert[nTracks];
  Double_t mPhiErrVert[nTracks];
  Double_t xVert[nTracks];
  Double_t yVert[nTracks];
  Double_t zVert[nTracks];
  Double_t nXVert[nTracks];
  Double_t nYVert[nTracks];
  Double_t nZVert[nTracks];
  Double_t pVert[nTracks];
  Double_t phiVert[nTracks];
  tree->SetBranchAddress("sVert",sVert);
  tree->SetBranchAddress("tVert",tVert);
  tree->SetBranchAddress("mXVert",mXVert);
  tree->SetBranchAddress("mYVert",mYVert);
  tree->SetBranchAddress("mPhiVert",mPhiVert);
  tree->SetBranchAddress("mXErrVert",mXErrVert);
  tree->SetBranchAddress("mYErrVert",mYErrVert);
  tree->SetBranchAddress("mPhiErrVert",mPhiErrVert);
  tree->SetBranchAddress("xVert",xVert);
  tree->SetBranchAddress("yVert",yVert);
  tree->SetBranchAddress("zVert",zVert);
  tree->SetBranchAddress("nXVert",nXVert);
  tree->SetBranchAddress("nYVert",nYVert);
  tree->SetBranchAddress("nZVert",nZVert);
  tree->SetBranchAddress("pVert",pVert);
  tree->SetBranchAddress("phiVert",phiVert);

  //-----------------------------------PionPlus---------------------------------------//
  Double_t tTof1PionPlus[nTracks];
  Double_t pTof1PionPlus[nTracks];
  tree->SetBranchAddress("tTof1PionPlus",tTof1PionPlus);
  tree->SetBranchAddress("pTof1PionPlus",pTof1PionPlus);

  Double_t tVertPionPlus[nTracks];
  Double_t pVertPionPlus[nTracks];
  tree->SetBranchAddress("tVertPionPlus",tVertPionPlus);
  tree->SetBranchAddress("pVertPionPlus",pVertPionPlus);

  //-----------------------------------Positron---------------------------------------//
  Double_t tTof1Positron[nTracks];
  Double_t pTof1Positron[nTracks];
  tree->SetBranchAddress("tTof1Positron",tTof1Positron);
  tree->SetBranchAddress("pTof1Positron",pTof1Positron);

  Double_t tVertPositron[nTracks];
  Double_t pVertPositron[nTracks];
  tree->SetBranchAddress("tVertPositron",tVertPositron);
  tree->SetBranchAddress("pVertPositron",pVertPositron);

  Int_t nentries=tree->GetEntries();

  TFile* hfile = new TFile("trackPi0.root", "RECREATE");
  TTree* ttree  = new TTree("trackingVar", "from tracking");
  ttree->SetAutoSave();
  trackingE36* ptr = new trackingE36;
  ttree->Branch("testBranch","trackingE36",(TObject**)&ptr,128000,0);
  TH1D*h1=new TH1D("h1"," K_{#pi2} momentum cut",55,0.140,.300);

  int dummy=-10000;
  for(int i = 0; i < nentries; i++){
    tree->GetEntry(i);
    ptr->evtNum=event;
    for(int j=0; j<nTracks; j++){
      //if(pVertPionPlus[j]>198.962 && pVertPionPlus[j]<212.638){
	//std::cout<<"\n  poinPlus has momentum P_pi+ = "<<pVertPionPlus[j]<<"\t"<<pVert[j]<<"\t"<<gapNumTof2[j]<<"\n\n";
        double phiMap[12]={60,30,0,330,300,270,240,210,180,150,120,90};
	double phi=((phiMap[gapNumTof2[j]])*M_PI/180);
        //std::cout<<"  --- Gap number check "<<gapNumTof1[j]<<" --- \n";
	ptr->tof2Gap=gapNumTof2[j];
        ptr->nxVert=nXVert[j]*std::cos(phi)-nYVert[j]*std::sin(phi);
	ptr->nyVert=nXVert[j]*std::sin(phi)+nYVert[j]*std::cos(phi);
	ptr->nzVert=nZVert[j];
        ptr->xVert=xVert[j];
	ptr->yVert=yVert[j];
	ptr->zVert=zVert[j];
	ptr->pVertpi0=pVertPionPlus[j]/1000.;
	h1->Fill(pVertPionPlus[j]/1000.);
      //}else{
	//ptr->tof2Gap=dummy;
        //ptr->nxVert=dummy;
	//ptr->nyVert=dummy;
	//ptr->nzVert=dummy;
	//ptr->pVertpi0=dummy;
      //}
    }
    ttree->Fill();
  }

  TCanvas* c1=new TCanvas("c1", " Momentum canvas", 950, 800);
  c1->cd();
  gStyle->SetOptStat(0);
  h1->GetXaxis()->SetTitle("Momentum [GeV/c]");
  h1->GetYaxis()->SetTitle("counts/bin");
  h1->SetLineWidth(2);
  h1->Draw("hist");
  auto tl1=new TLine(.195,0.0,.195,3700);
  auto tl2=new TLine(.215,0.0,.215,3700);
  tl1->SetLineColor(kRed);
  tl2->SetLineColor(kRed);
  tl1->SetLineWidth(3);
  tl2->SetLineWidth(3);
  tl1->Draw();
  tl2->Draw();
  c1->Write();

  ttree->Write();
  h1->Write();
  hfile->Close();
  rootFile->Close();
  delete ptr;*/
  return 0;
}
