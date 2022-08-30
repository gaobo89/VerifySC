#include "utils.h"

#include <fstream>
#include <iostream>
#include <typeinfo> // used for typeid

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
namespace bm = boost::multiprecision;

using namespace std;

string initEnv(string source){
	srand(time(NULL));
   
    // make directory of output to save the intermediate files.
    if(fs::exists("output"))
        fs::remove_all("output");
    fs::create_directory("output");

    // fs::path homePath(fs::current_path());
    fs::path sourcePath(source);
    string fileName = sourcePath.filename().string();
    string outputStr = "output/" + fileName;

    // cout << "source in cpp is: " << source << endl;
    fs::copy_file(source, outputStr);

    return outputStr;
 
}


void init_logging(string debugLevel) {
    logging::register_simple_formatter_factory<logging::trivial::severity_level, 
    	char>("Severity");

    logging::add_file_log (
        keywords::file_name = "output/debugInfo.log",
        keywords::format = "[%TimeStamp%] [%Severity%] %Message%" );

    logging::core::get()->set_filter (
    	// trace --> debug --> info --> warning --> error --> fatal
        logging::trivial::severity >= logLevels[debugLevel] );

    logging::add_common_attributes();
}
