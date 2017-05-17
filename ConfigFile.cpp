// ConfigFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Config.h"


int main()
{

	Config config;

	config.ReadInFromFile("D:/config.txt");

	int key = config.GetValueAsInt("key2");
	printf("value %d\n", key);

	system("PAUSE");

    return 0;
}

