//
//  Logger.cpp
//  CGProj
//

#include "Logger.h"

void Logger::print(std::string text)
{
	std::cout << text << "\n";
}

void Logger::printError(std::string text)
{
	std::cout << "[ERROR] " << text << "\n";
}
