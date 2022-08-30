#include "IOInterface.h"
#include "utils.h"
// #include <iostream>


// // global variables
// bool MYGLOBAL::NORMALRun = true;




// int MYGLOBAL::fileCounter = 0;

// int MYGLOBAL::overflowCounter = 0;
// int MYGLOBAL::failureCounter = 0;
// int MYGLOBAL::concreteFailure = 0;
// int MYGLOBAL::reentrancyCounter = 0;
// std::string MYGLOBAL::sourceFile;

z3::context PARAMS::z3context;
unsigned PARAMS::Z3TIMEOUT = 10000;
std::string PARAMS::CName;
std::string PARAMS::SolcVer;
bool PARAMS::Optimize = false;
int PARAMS::Run = 0;
bool PARAMS::CFG = false;
// default the overflow is not allowed.
bool PARAMS::Overflow = true;
bool PARAMS::CrossCall = false;

// int MYGLOBAL::callCnt = 0;
// std::string MYGLOBAL::failAt = "none";

// std::string MYGLOBAL::stage; 
// std::map<std::string, std::string> MYGLOBAL::StorageUints;
// std::set<std::string> MYGLOBAL::StorageMappings;
// std::set<std::string> MYGLOBAL::StorageArrs;
// std::set<std::string> MYGLOBAL::StorageOmit;
// std::map<std::string, std::string> MYGLOBAL::Allvars;

// bool MYGLOBAL::prim = false;
// bool MYGLOBAL::largeNum = false;
// // defined in storage.h
// std::vector<Storage> txStorage;
// std::vector<Storage> inductStorage;
// std::map<int, Storage> inductStorageMap;


// // initialise the static variables in class.
// int Node::counter = 0;

// using namespace std;

int main(int argc, char** argv){

	IOInterface input;	
	if (!input.parseArguments(argc, argv))
		return 1;

	if (!input.processInput())
		return 1;

	return 0;

}