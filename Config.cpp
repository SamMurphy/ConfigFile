#pragma once
#include "stdafx.h"
#include "Config.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>



Config::Config()
{
}


Config::~Config()
{
}

void Config::ReadInFromFile(const std::string & filePath)
{
	std::ifstream fileStream;
	fileStream.open(filePath);	
	std::string line;

	if (fileStream.is_open())
	{
		while (std::getline(fileStream, line))
		{
			std::istringstream is_line(line);
			std::string key;
			if (std::getline(is_line, key, '='))
			{
				std::string value;
				if (key[0] == '#')
					continue;

				if (std::getline(is_line, value))
				{
					configValues[key] = value;
				}
			}
		}
	}
}

int Config::GetValueAsInt(const std::string & key)
{
	std::string value = GetValue(key);

	int i = 0;

	try
	{
		i = std::stoi(value);
	}
	catch(...)
	{
		printf("failed to parse %s value to int\n", key.c_str());
		return 0;
	}

	return i;
}

float Config::GetValueAsFloat(const std::string & key)
{
	std::string value = GetValue(key);

	float f = 0;

	try
	{
		f = std::stof(value);
	}
	catch (...)
	{
		printf("failed to parse %s value to float\n", key.c_str());
		return 0;
	}

	return f;
}

double Config::GetValueAsDouble(const std::string & key)
{
	std::string value = GetValue(key);

	double d = 0;

	try
	{
		d = std::stod(value);
	}
	catch (...)
	{
		printf("failed to parse %s value to double\n", key.c_str());
		return 0;
	}

	return d;
}
