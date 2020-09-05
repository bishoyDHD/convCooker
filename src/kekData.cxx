#include "kekData.h"
#include <iostream>

kekData::kekData(): usrEvtNo(0){
  tree=NULL;
  ptree=NULL;
  kekccInfo=new kekcc();
}
kekData::~kekData(){
  std::cout<<"**************************************\n";
  std::cout<<"*****| Exiting KEK Analysis File |****\n";
  std::cout<<"**************************************\n";
}
void kekData::beginRoot(std::string name){
  hfile=new TFile(name.c_str(),"RECREATE");
  tree=new TTree("data","From KEK datfile");
  tree->SetAutoSave();
  tree->Branch("kekccInfo","kekcc",(TObject**)&kekccInfo,256000,0);
  h1M2[0]=new TH1D("h1M2","Mass^{2}",500,-7000,35000);
  h1M2[1]=new TH1D("h1M2cut","Mass^{2}",500,-7000,35000);
  h1Pgap[0]=new TH1D("h1Pgap","Gap Momentum",70,180,250);
  h1Pgap[1]=new TH1D("h1Pmu","Muon Momentum",70,180,250);
  h2pid[0]=new TH2D("h1acadc", "AC ADC vs M^{2}",50,-7000,35000,25,0,10000);
  h2pid[1]=new TH2D("h1pgcadc","PGC ADC vs M^{2}",50,-7000,35000,25,0,10000);
  h2M2vP=new TH2D("h2M2vP","Momentum vs M^{2}",50,-7000,35000,15,180,235);
}
void kekData::writeRoot(){
  tree->Write();
  hfile->Write();
  hfile->Close();
}
void kekData::convert(TFile* pfile){
  ptree=(TTree*)pfile->Get("tr1");
  // obtain variables from the input ROOT file
   ptree->SetBranchAddress("runnum", &runnum, &b_runnum);
   ptree->SetBranchAddress("ievent", &ievent, &b_ievent);
   ptree->SetBranchAddress("runtype", &runtype, &b_runtype);
   ptree->SetBranchAddress("mode", &mode, &b_mode);
   ptree->SetBranchAddress("mc_evid", &mc_evid, &b_mc_evid);
   ptree->SetBranchAddress("trigtype[3]", trigtype, &b_trigtype);
   ptree->SetBranchAddress("fidg", &fidg, &b_fidg);
   ptree->SetBranchAddress("TF1g", &TF1g, &b_TF1g);
   ptree->SetBranchAddress("TF2g", &TF2g, &b_TF2g);
   ptree->SetBranchAddress("mc_part_ab[30]", mc_part_ab, &b_mc_part_ab);
   ptree->SetBranchAddress("mc_procfl[5]", mc_procfl, &b_mc_procfl);
   ptree->SetBranchAddress("mc_pos[3]", mc_pos, &b_mc_pos);
   ptree->SetBranchAddress("ktime", &ktime, &b_ktime);
   ptree->SetBranchAddress("kfib[2]", kfib, &b_kfib);
   ptree->SetBranchAddress("gd_tgkcl", &gd_tgkcl, &b_gd_tgkcl);
   ptree->SetBranchAddress("gd_tgtgkdis", &gd_tgtgkdis, &b_gd_tgtgkdis);
   ptree->SetBranchAddress("tgpath", &tgpath, &b_tgpath);
   ptree->SetBranchAddress("vtex[3]", vtex, &b_vtex);
   ptree->SetBranchAddress("nfib", &nfib, &b_nfib);
   ptree->SetBranchAddress("tginfor[100][3]", tginfor, &b_tginfor);
   ptree->SetBranchAddress("tginfoi[100][3]", tginfoi, &b_tginfoi);
   ptree->SetBranchAddress("ex_trver", &ex_trver, &b_ex_trver);
   ptree->SetBranchAddress("vertr", &vertr, &b_vertr);
   ptree->SetBranchAddress("trchi2", &trchi2, &b_trchi2);
   ptree->SetBranchAddress("c2_pos[3]", c2_pos, &b_c2_pos);
   ptree->SetBranchAddress("c3_pos[3]", c3_pos, &b_c3_pos);
   ptree->SetBranchAddress("c4_pos[3]", c4_pos, &b_c4_pos);
   ptree->SetBranchAddress("dfid[3]", dfid, &b_dfid);
   ptree->SetBranchAddress("dtf2[3]", dtf2, &b_dtf2);
   ptree->SetBranchAddress("trsft[3]", trsft, &b_trsft);
   ptree->SetBranchAddress("trac[3]", trac, &b_trac);
   ptree->SetBranchAddress("trfidfib[3]", trfidfib, &b_trfidfib);
   ptree->SetBranchAddress("p_gap", &p_gap, &b_p_gap);
   ptree->SetBranchAddress("pmu", &pmu, &b_pmu);
   ptree->SetBranchAddress("ppi", &ppi, &b_ppi);
   ptree->SetBranchAddress("calfidt", &calfidt, &b_calfidt);
   ptree->SetBranchAddress("toft", &toft, &b_toft);
   ptree->SetBranchAddress("flen", &flen, &b_flen);
   ptree->SetBranchAddress("mass", &mass, &b_mass);
   ptree->SetBranchAddress("act", &act, &b_act);
   ptree->SetBranchAddress("acadc", &acadc, &b_acadc);
   ptree->SetBranchAddress("act_u[12]", act_u, &b_act_u);
   ptree->SetBranchAddress("act_d[12]", act_d, &b_act_d);
   ptree->SetBranchAddress("acadc_u[12]", acadc_u, &b_acadc_u);
   ptree->SetBranchAddress("acadc_d[12]", acadc_d, &b_acadc_d);
   ptree->SetBranchAddress("pgct", &pgct, &b_pgct);
   ptree->SetBranchAddress("pgcadc", &pgcadc, &b_pgcadc);
   ptree->SetBranchAddress("chie", &chie, &b_chie);
   ptree->SetBranchAddress("chim", &chim, &b_chim);

  Int_t nentries=ptree->GetEntries();
  if(usrEvtNo!=0) nentries=usrEvtNo;
  for(int i=0; i<nentries; i++){
    ptree->GetEntry(i);
    beta=(flen*cm)/(toft*ns*c);
    mass2=std::pow(p_gap,2)*(1/std::pow(beta,2)-1);
    h1M2[0]->Fill(mass2);
    h1Pgap[0]->Fill(p_gap);
    h1Pgap[1]->Fill(pmu);
    if(pmu<230.0){
      h1M2[1]->Fill(mass2);
      h2pid[0]->Fill(mass2,acadc);
      h2pid[1]->Fill(mass2,pgcadc);
      h2M2vP->Fill(mass2,p_gap);
    }
    // Store variables into a cooker appropriate format
    kekccInfo->runnum=runnum;
    kekccInfo->ievent=ievent;
    kekccInfo->runtype=runtype;
    kekccInfo->mode=mode;
    kekccInfo->mc_evid=mc_evid;
    std::copy(std::begin(trigtype),std::end(trigtype),std::begin(kekccInfo->trigtype));
    kekccInfo->fidg=fidg;
    kekccInfo->TF1g=TF1g;
    kekccInfo->TF2g=TF2g;
    std::copy(std::begin(mc_part_ab),std::end(mc_part_ab),
                           std::begin(kekccInfo->mc_part_ab));
    std::copy(std::begin(mc_procfl),std::end(mc_procfl),std::end(kekccInfo->mc_procfl));
    std::copy(std::begin(mc_pos),std::end(mc_pos),std::begin(kekccInfo->mc_pos));
    kekccInfo->ktime=ktime;
    std::copy(std::begin(kfib),std::end(kfib),std::begin(kekccInfo->kfib));
    kekccInfo->gd_tgkcl=gd_tgkcl;
    kekccInfo->gd_tgtgkdis=gd_tgtgkdis;
    kekccInfo->tgpath=tgpath;
    std::copy(std::begin(vtex),std::end(vtex),std::begin(kekccInfo->vtex));
    kekccInfo->nfib=nfib;
    std::copy(&tginfor[0][0],&tginfor[0][0]+100*3,&(kekccInfo->tginfor[0][0]));
    std::copy(&tginfoi[0][0],&tginfoi[0][0]+100*3,&(kekccInfo->tginfoi[0][0]));
    kekccInfo->ex_trver=ex_trver;
    kekccInfo->vertr=vertr;
    kekccInfo->trchi2=trchi2;
    std::copy(std::begin(c2_pos),std::end(c2_pos),std::begin(kekccInfo->c2_pos));
    std::copy(std::begin(c3_pos),std::end(c3_pos),std::begin(kekccInfo->c3_pos));
    std::copy(std::begin(c4_pos),std::end(c4_pos),std::begin(kekccInfo->c4_pos));
    std::copy(std::begin(dfid),std::end(dfid),std::begin(kekccInfo->dfid));
    std::copy(std::begin(dtf2),std::end(dtf2),std::begin(kekccInfo->dtf2));
    std::copy(std::begin(trsft),std::end(trsft),std::begin(kekccInfo->trsft));
    std::copy(std::begin(trac),std::end(trac),std::begin(kekccInfo->trac));
    std::copy(std::begin(trfidfib),std::end(trfidfib),std::begin(kekccInfo->trfidfib));
    kekccInfo->p_gap=p_gap;
    kekccInfo->pmu=pmu;
    kekccInfo->ppi=ppi;
    kekccInfo->calfidt=calfidt;
    kekccInfo->toft=toft;
    kekccInfo->flen=flen;
    kekccInfo->mass=mass;
    kekccInfo->act=act;
    kekccInfo->acadc=acadc;
    std::copy(std::begin(act_u),std::end(act_u),std::begin(kekccInfo->act_u));
    std::copy(std::begin(act_d),std::end(act_d),std::begin(kekccInfo->act_d));
    std::copy(std::begin(acadc_u),std::end(acadc_u),std::begin(kekccInfo->acadc_u));
    std::copy(std::begin(acadc_d),std::end(acadc_d),std::begin(kekccInfo->acadc_d));
    kekccInfo->pgct=pgct;
    kekccInfo->pgcadc=pgcadc;
    kekccInfo->chie=chie;
    kekccInfo->chim=chim;
  }
}
