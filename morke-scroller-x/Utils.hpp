#pragma once

#include <iostream>
#include <vector>

class Utils
{
public:
	static std::vector<std::string> split(const std::string& str, char delim);
	static std::string deleteWhiteSpaces(const std::string& str);
};