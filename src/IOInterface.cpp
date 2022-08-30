#include "IOInterface.h"
#include "utils.h"

#include <regex>
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
namespace po = boost::program_options;
namespace pt = boost::property_tree;
namespace po_style = boost::program_options::command_line_style;

using namespace MYGLOBAL;



bool IOInterface::parseArguments(int _argc, char** _argv){

	po::options_description desc(
R"(Usage: sverify [options] [input_file...]
Example: sverify -s test/example.sol -d info 
The options are as following)", 
		po::options_description::m_default_line_length,
		po::options_description::m_default_line_length - 30
	);
	desc.add_options()
	("help,h", "produce help message")
	("source,s", po::value<string>(), "input file for analysis")
	("contract,c", po::value<string>(), "contract name for analysis")
	("SolcVersion,v", po::value<string>(), "solidity compiler version")
	("Optimize,m", po::value<string>(), "Optimize with yes or no")
	("Run,r", po::value<int>(), "Optimize times")
	("debugLevel,d", po::value<string>(), "available options: trace, debug, info, warning")
	("CFG,g", "generate CFG and save as dot file")
	("CrossCall,k", "detect cross-contract function calls")
	("overflow,o", "overflow is allowed")
	("z3time,z", po::value<int>(), "z3 solver time, 1000 means 1s, default 10s")
	;

	try{
		po::store(po::command_line_parser(_argc, _argv).options(desc)
			.style(po_style::unix_style|po_style::case_insensitive).run(), m_args);
		po::notify(m_args);
	}catch (po::error const& _exception){
		cerr << _exception.what() << endl;
		return false;
	}


	if(m_args.count("source")) { 
		m_source = m_args["source"].as<std::string>();

		if(m_args.count("contract"))
			PARAMS::CName = m_args["contract"].as<string>();

		string debugLevel = "fatal";
		if(m_args.count("debugLevel"))
			debugLevel = m_args["debugLevel"].as<string>();
		init_logging(debugLevel);


		if(m_args.count("overflow"))
			PARAMS::Overflow = false;

		if(m_args.count("CFG"))
			PARAMS::CFG = true;

		if(m_args.count("CrossCall"))
			PARAMS::CrossCall = true;
		
		if(m_args.count("SolcVersion"))
			PARAMS::SolcVer = m_args["SolcVersion"].as<string>();
		else
			PARAMS::SolcVer = "solc_0.5.11";


		if(m_args.count("Optimize")){
			string tempOp = m_args["Optimize"].as<string>();
	        if(boost::iequals(tempOp, "yes")){
	            PARAMS::Optimize = true;
	            PARAMS::Run = m_args["Run"].as<int>();
	        }
		}

		if(m_args.count("z3time"))
			PARAMS::Z3TIMEOUT = m_args["z3time"].as<int>();

		// copy the source file by users to a new folder "output"
		// and analyze the contracts based on this file.
		m_source = initEnv(m_source);
		return true;
	}else{
		cout << desc << "\n";
		// at least input source for analysis.
		return false;
	}
}



bool IOInterface::processInput(){
// 	map<string, map<string, OrgStruct> > elemContracts;
// 	vector<string> holdon;

// 	string file = m_source;
// 	// file = updateLoopFile(file);
// 	// cout << "updated file is: " << file << endl;

// 	// start to analysis the updated file.
// 	compiled2JSON(file);
// 	getJson(file);


// 	for (auto key : m_jsonRoot.get_child("contracts")) {
// 		cout << "original contract: " << key.first << endl;
// 		resetGlobal();
// 		resetState();

// 		string result = analyze(file, key.first, elemContracts);
// 		if(result == "holdon"){ 
// 			cout << "holdon contract: " << key.first << endl;
// 			holdon.push_back(key.first); 
// 		}
// 	}


// 	// in case some contracts depend on others.
// 	while(!holdon.empty()){
// 		std::vector<string> holdon1 = holdon;
// 		holdon.clear();
// 		for(auto contract : holdon1){
// 			cout << "dependant contract: " << contract << endl;
// 			resetGlobal();
// 			resetState();

// 			string result = analyze(file, contract, elemContracts);
// 			if(result == "holdon"){ 
// 				cout << "still holdon contract: " << contract << endl;
// 				holdon.push_back(contract); 
// 			}
// 		}
// 	}

// 	cout << "finished analysis!\n";

// 	// ...
	return true;
}



// void IOInterface::compiled2JSON(string file){
// 	// string cmdstr = SolcVer + " --combined-json asm,ast,bin,bin-Runtime,hashes %s > %s";
// 	string cmdstr = SolcVer + " --combined-json asm,ast,bin,bin-Runtime %s > %s";
// 	if(Optimize){
// 		if(Run == 200)
// 			cmdstr = SolcVer + " --Optimize --combined-json asm,ast,bin,bin-Runtime %s > %s";
// 		else
// 			cmdstr = SolcVer + " --Optimize-Runs " + to_string(Run) + " --combined-json asm,ast,bin,bin-Runtime %s > %s";
// 	}
	
// 	RunCMD(cmdstr, file, file + ".json");
// }