#include <usage.h>

usage::usage():nameRoot("e36Conv.root"),typeCh(2){

}
usage::~usage(){

}
void usage::printUsage(std::string name){
  std::cout<<" Usage:       "<<name<<" source"<<std::endl;
  std::cout<<" Must specify rootfile to be converted !!!"<<std::endl;
  std::cout<<" -n #number:  maximum number of events to be processed\n";
  std::cout<<" -r runNo:    Need to set the run number otherwise won't run\n";
  std::cout<<" -f:          Name of the rootfile to be read in\n";
  std::cout<<" -t:          Name of type rootfile to be converted\n";
  std::cout<<"              For now 1=target & 2=MWPC\n";
  std::cout<<" -o out.root: string out.root is the name of the output ROOT file. By default, it is e36Conv.root\n";
  std::cout<<" Example:     ./tgtGap -[opt1] -[opt2] /path/to/Run#MS.root\n";
  std::cout<<" -h:          Print this help menu\n";
}

bool usage::parseArgs(int argc, char** argv){
  if(argc==1) return false;
  bool writeHelp=false;
  for(int i=1; i<argc; i++){
    if(argv[i][0]=='-'){
      switch(argv[i][1]){
        case 'h':
	  writeHelp=true;
	  break;
	case 'n':
	  nmax=std::stoul(argv[i+1]);
	  i++;
	  break;
	case 'r':
	  runNo=std::stoul(argv[i+1]);
	  i++;
	  break;
	case 't':
	  typeCh=std::stoul(argv[i+1]);
	  i++;
	  break;
	case 'f':
	  fileName=argv[i+1];
          i++;
          break;
	case 'o':
	  nameRoot=argv[i+1];
	  i++;
	  break;
      }// end of switch statement
    }// end of top if loop
    else{ // default options
      fileName=argv[i];
      //channel=7;
    }
  }
  if(writeHelp){
    if(nmax>0){
      std::cout<<" Max number of evens: "<<nmax<<std::endl;
    }
  }
  return true;
}
