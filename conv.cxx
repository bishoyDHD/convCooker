#include <iostream>
#include "usage.h"
#include "trekvar.h"
#define _USE_MATH_DEFINES

//static TApplication *app = new TApplication("App", NULL, NULL);
int main(int argc,char** argv){
  // Read in existing ROOT file
  usage* pargs=new usage();
  if(!pargs->parseArgs(argc,argv)){
    pargs->printUsage("convCooker");
    return 0; //executes the exit procedure
  }
  // need activate parseArgs function
  pargs->parseArgs(argc,argv);
  int ch=pargs->getCh(); // must be set
  std::string fileName=pargs->getFile();
  TFile *file=new TFile(fileName.c_str());
  std::string name=pargs->getName();
  UInt_t runNo=pargs->getRunNo();
  Target* tgtconv=new Target();
  mwpc*   mwpcconv=new mwpc();
  // Begin convertions process
  std::cout<<" ***************************************\n";
  std::cout<<"         Starting the converter         \n";
  std::cout<<" ***************************************\n";
  switch(ch){
    case 1:
      tgtconv->beginRoot(name);
      tgtconv->convert(file);
      tgtconv->writeRoot();
      delete tgtconv;
      break;
    case 2:
      mwpcconv->beginRoot(name);
      mwpcconv->convert(file);
      mwpcconv->writeRoot();
      delete mwpcconv;
      break;
  }// end of switch statement
  return 0;
}
