#pragma once

#include "global.h"

#include <string>
#include <iostream>
#include <vector>

#include <boost/any.hpp>
#include <boost/lexical_cast.hpp> //cast boost number to string.

std::string initEnv(std::string source);
void init_logging(std::string debugLevel);