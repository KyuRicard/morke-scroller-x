#include "Utils.hpp"
#include <sstream>

std::vector<std::string> Utils::split(const std::string & str, char delim)
{
	std::stringstream ss(str);
	std::string line;
	std::vector<std::string> lines;
	while (std::getline(ss, line, delim))
	{
		lines.push_back(line);
	}
	return lines;
}

std::string Utils::deleteWhiteSpaces(const std::string & str)
{
	std::string res = "";
	for (char c : str)
	{
		if (!isspace(c))
			res += c;
	}
	return res;
}
