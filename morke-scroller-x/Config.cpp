#include "Config.hpp"
#include <fstream>
#include "Utils.hpp"
#include <algorithm>

#include <filesystem>

Config::Config()
{
	std::fstream fs(filename);
	std::string content = std::string(std::istreambuf_iterator<char>(fs), std::istreambuf_iterator<char>());
	if (content.empty())
	{
		defaultParams();
	}
	else
	{
		auto lines = Utils::split(content, '\n');
		for (auto line : lines)
		{
			auto vec = Utils::split(line, '=');
			auto key = Utils::deleteWhiteSpaces(vec[0]);
			auto value = Utils::deleteWhiteSpaces(vec[1]);
			configs[key] = value;
		}
	}	
}

Config::~Config()
{
	std::fstream fs(filename, std::ios::out);
	fs.clear();
	for (auto p : configs)
	{
		fs << p.first << "=" << p.second << '\n';
	}
}

const std::string& Config::operator[](const std::string& key)
{
	return configs[key];
}

void Config::defaultParams()
{
#define o(k, v) configs[k] = v;
	o("width", "1280") o("height", "720") o("fullscreen", "false") o("borderless", "false") o("fps", "60") o("display", "0") o("antialiasing", "1") o("vsync", "false")
		o("fov", "60")
#undef o
}


