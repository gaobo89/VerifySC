#pragma once

// this line is for boost log linking
#define BOOST_LOG_DYN_LINK 1


// #define BLOCKLENGTH 2000
// // measured as milliseconds, 1000u is 1000ms.
// // #define  10000u
// #define NUMBERRANGE 300
// #define LOOPCOUNTER 10

// -2**255
#define POW255n "-57896044618658097711785492504343953926634992332820282019728792003956564819968"
// 2**256 - 1
#define POW256p "115792089237316195423570985008687907853269984665640564039457584007913129639935"
#define U32 "4294967295"


// 1 stands for bold, defaultly all is bold.
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define FRED(x) RED x RESET
#define FGRN(x) GRN x RESET
#define FYEL(x) YEL x RESET


#include <map>
#include <string>
#include "z3++.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/any.hpp>


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


using bigint = boost::multiprecision::cpp_int;
using u256 = boost::multiprecision::uint256_t;
using s256 = boost::multiprecision::int256_t;
using u160 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<160, 160, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
// following is to define a new number type with boost.
// using u256 = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;


namespace logging = boost::log;
namespace keywords = boost::log::keywords;

namespace PARAMS{

    // share the same context across all the environment.
    extern z3::context z3context;     
    extern unsigned Z3TIMEOUT;

    extern std::string CName;
    extern std::string SolcVer;
    extern bool Optimize;
    extern int Run;
    extern bool CFG;

    // uselss after evm bytecode compiled by Solidity 0.8.0
	extern bool Overflow;

    extern bool CrossCall;
}


namespace MYGLOBAL{

    // extern bool NORMALRun;
    
    // extern int fileCounter;
    // extern int overflowCounter;
    // extern int failureCounter;
    // extern int concreteFailure;
    // extern int reentrancyCounter;

    // extern std::string sourceFile;

    // extern int callCnt;

    // extern std::string failAt; //contract or call.

    // // stage can be "bin", "Runtime", "conc" etc.
    // extern std::string stage;
    // // key: variable location; value: type
    // extern std::map<std::string, std::string> StorageUints;
    // extern std::set<std::string> StorageMappings;
    // extern std::set<std::string> StorageOmit;
    // extern std::set<std::string> StorageArrs;
    // extern std::map<std::string, std::string> Allvars;

    // extern bool prim;
    // // used for txInv.cpp
    // extern bool largeNum;
    // to keep the CALLDATALOAD accordant.
    // extern std::map<std::string, boost::any> inputEnv;    
}


static std::map<std::string, logging::trivial::severity_level> logLevels = {
    { "trace"   , logging::trivial::trace},
    { "debug"   , logging::trivial::debug},
    { "info"    , logging::trivial::info},
    { "warning" , logging::trivial::warning},
    { "error"   , logging::trivial::error},
    { "fatal"   , logging::trivial::fatal}
};