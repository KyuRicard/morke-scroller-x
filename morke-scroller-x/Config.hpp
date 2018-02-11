#pragma once
#include <iostream>
#include <map>
#include <string>

class Config
{
	const std::string filename = "config.ini";
	std::map<std::string, std::string> configs;

	Config();
	~Config();
public:
	static Config& getInstance()
	{
		static Config c;
		return c;
	}

	template<typename T>
	T getValue(const std::string& key);

	const std::string& operator[](const std::string& key);
	void defaultParams();
};

template<typename T>
inline T Config::getValue(const std::string& key)
{
	return configs[key];
}

template<>
inline int Config::getValue(const std::string& key)
{
	return stoi(configs[key]);
}

template<>
inline bool Config::getValue(const std::string& key)
{
	return configs[key] != "false";
}

template<>
inline float Config::getValue(const std::string& key)
{
	return stof(configs[key]);
}