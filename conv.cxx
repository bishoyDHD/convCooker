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
  std::string fileName=pargs->getFile();
  TFile *file=new TFile(fileName.c_str());
  std::string name=pargs->getName();
  Target* tgtconv=new Target();
  // Begin convertions process
  tgtconv->beginRoot(name);
  tgtconv->convert(file);
  tgtconv->writeRoot();
  return 0;
}
