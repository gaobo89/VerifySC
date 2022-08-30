#pragma once

// #include "ContractInfo.h"
#include <boost/program_options.hpp>
#include <boost/property_tree/json_parser.hpp>


class IOInterface{
	public:
		/// Parse command line arguments and return false if we should not continue
		bool parseArguments(int _argc, char** _argv);
		/// Parse the files and create source code objects
		
		bool processInput();
		/// Perform actions on the input depending on provided compiler arguments
		/// @returns true on success.
	// 	bool actOutput();

	// 	std::vector<ContractInfo> m_contractInfos;
	

	private:
		boost::program_options::variables_map m_args;
		std::string m_source;
	// 	boost::property_tree::ptree m_jsonRoot;

	// 	void compiled2JSON(std::string file);
	// 	std::string updateLoopFile(std::string file);
	// 	void getJson(std::string file);

	// 	std::string analyze(std::string file, std::string contractName, 
	// 		std::map<std::string, std::map<std::string, OrgStruct> > &elemContracts);
};

// void outputUnvisited(std::set<int> unvisitBFLoop, std::set<int> unvisitInLoop, std::set<int> unvisitAFLoop,
// 	std::map<int, BasicBlock> &cfgInfo);

// void rplLoopVars(const boost::property_tree::ptree& astTree, OrgStruct org, std::map<std::string, std::string>& globalVars,
// 	std::map<int, VarsInfo4Rplc>& loopNGVars4Rplc, std::map<std::string, std::string>& allVars);