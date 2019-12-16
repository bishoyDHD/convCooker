#ifndef usage_h
#define usage_h 1

#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>

class usage{
public:
  usage(); //default constructor
  ~usage(); // destructor
  void printUsage(std::string name);
  bool parseArgs(int argc, char** argv);
  std::string getFile(){return fileName;};
  inline void setName(std::string name){nameRoot=name;};
  std::string getName(){return nameRoot;};
  int getMaxN(){return nmax;};
  int getCh(){return typeCh;};
private:
  std::string fileName;
  std::string nameRoot;
  int nmax,typeCh;
};
#endif
