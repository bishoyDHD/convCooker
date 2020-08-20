#include "kekData.h"
#include <iostream>

kekData::kekData(): usrEvtNo(0){
  tree=NULL;
  ptree=NULL;
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
  h1M2=new TH1D("h1M2","Mass^2",5000,-7000,30000);
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
    beta=flen/toft;
    mass2=std::pow(p_gap,2)/(1/std::pow(beta,2)-1);
    h1M2->Fill(mass2);
  }
}
