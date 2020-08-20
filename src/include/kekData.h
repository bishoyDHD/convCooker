#ifndef kekData_h
#define kekData_h 1

#include <TFile.h>
#include <TTree.h>
#include <vector>
#include <TH1D.h>

class kekData{
public:
  kekData();
  virtual ~kekData();
  void beginRoot(std::string);
  void writeRoot();
  void setEvtNo();
  void convert(TFile*);
private:
  // Tree variables
  TFile* hfile;
  TTree* tree, *ptree;
  Int_t usrEvtNo;
  Double_t mass2,beta;
  TH1D* h1M2;
  // Declaration of leaf types
  Int_t   runnum;
  Int_t   ievent;
  Int_t   runtype;
  Int_t   mode;
  Int_t   mc_evid;
  Int_t   trigtype[3];
  Int_t   fidg;
  Int_t   TF1g;
  Int_t   TF2g;
  Float_t mc_part_ab[30];
  Int_t   mc_procfl[5];
  Float_t mc_pos[3];
  Float_t ktime;
  Float_t kfib[2];
  Int_t   gd_tgkcl;
  Int_t   gd_tgtgkdis;
  Float_t tgpath;
  Float_t vtex[3];
  Int_t   nfib;
  Float_t tginfor[100][3];
  Int_t   tginfoi[100][3];
  Int_t   ex_trver;
  Int_t   vertr;
  Float_t trchi2;
  Float_t c2_pos[3];
  Float_t c3_pos[3];
  Float_t c4_pos[3];
  Float_t dfid[3];
  Float_t dtf2[3];
  Float_t trsft[3];
  Float_t trac[3];
  Float_t trfidfib[3];
  Float_t p_gap;
  Float_t pmu;
  Float_t ppi;
  Float_t calfidt;
  Float_t toft;
  Float_t flen;
  Float_t mass;
  Float_t act;
  Float_t acadc;
  Float_t act_u[12];
  Float_t act_d[12];
  Float_t acadc_u[12];
  Float_t acadc_d[12];
  Float_t pgct;
  Float_t pgcadc;
  Float_t chie;
  Float_t chim;
  // List of branches
  TBranch* b_runnum;   //!
  TBranch* b_ievent;   //!
  TBranch* b_runtype;   //!
  TBranch* b_mode;   //!
  TBranch* b_mc_evid;   //!
  TBranch* b_trigtype;   //!
  TBranch* b_fidg;   //!
  TBranch* b_TF1g;   //!
  TBranch* b_TF2g;   //!
  TBranch* b_mc_part_ab;   //!
  TBranch* b_mc_procfl;   //!
  TBranch* b_mc_pos;   //!
  TBranch* b_ktime;   //!
  TBranch* b_kfib;   //!
  TBranch* b_gd_tgkcl;   //!
  TBranch* b_gd_tgtgkdis;   //!
  TBranch* b_tgpath;   //!
  TBranch* b_vtex;   //!
  TBranch* b_nfib;   //!
  TBranch* b_tginfor;   //!
  TBranch* b_tginfoi;   //!
  TBranch* b_ex_trver;   //!
  TBranch* b_vertr;   //!
  TBranch* b_trchi2;   //!
  TBranch* b_c2_pos;   //!
  TBranch* b_c3_pos;   //!
  TBranch* b_c4_pos;   //!
  TBranch* b_dfid;   //!
  TBranch* b_dtf2;   //!
  TBranch* b_trsft;   //!
  TBranch* b_trac;   //!
  TBranch* b_trfidfib;   //!
  TBranch* b_p_gap;   //!
  TBranch* b_pmu;   //!
  TBranch* b_ppi;   //!
  TBranch* b_calfidt;   //!
  TBranch* b_toft;   //!
  TBranch* b_flen;   //!
  TBranch* b_mass;   //!
  TBranch* b_act;   //!
  TBranch* b_acadc;   //!
  TBranch* b_act_u;   //!
  TBranch* b_act_d;   //!
  TBranch* b_acadc_u;   //!
  TBranch* b_acadc_d;   //!
  TBranch* b_pgct;   //!
  TBranch* b_pgcadc;   //!
  TBranch* b_chie;   //!
  TBranch* b_chim;   //!
};
#endif
