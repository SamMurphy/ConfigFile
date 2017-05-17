#pragma once
#include <map>
#include <string>

typedef std::map<std::string, std::string> ConfigInfo;
typedef std::map<std::string, std::string>::iterator ConfigInfoIterator;

class Config
{
public:
	Config();
	~Config();

	ConfigInfo configValues;

	void ReadInFromFile(const std::string& filePath);
	std::string& GetValue(const std::string& key);

	int GetValueAsInt(const std::string& key);
	float GetValueAsFloat(const std::string& key);
	double GetValueAsDouble(const std::string& key);


};

inline std::string& Config::GetValue(const std::string& key)
{
	// Found
	ConfigInfoIterator i = configValues.find(key);
	if (i != configValues.end())
	{
		return i->second;
	}
	// Not found
	std::string s = "";
	return s;
}



