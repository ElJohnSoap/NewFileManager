﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <string>
#include <iostream>
#include <IntSafe.h>
#include <Windows.h>
#include <set>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <fstream>
#include "FileManager.h"

using namespace std;
namespace fs = filesystem;

class dialogWithUser
{
private:
	string command;

public:

	dialogWithUser() {};

	void receivingProcessingCommand();
	void help();
	string setPath();
	FileManager& commandRoot(FileManager&a);
	FileManager& commandCd(FileManager& a);
	FileManager& commandPd(FileManager& a);

};

/*cout << "Commands: " << endl;
cout << "help - show this message" << endl;
cout << "exit - exit program" << endl;
cout << "dir - show directory" << endl;
cout << "cd - change directory" << endl;
cout << "mkdir - create directory" << endl;
cout << "rmdir - remove directory" << endl;
cout << "rename - rename file" << endl;
cout << "copy - copy file" << endl;
cout << "move - move file" << endl;
cout << "del - delete file" << endl;
cout << "open - open file" << endl;
cout << "save - save file" << endl;
cout << "type - type file" << endl;
cout << "exit - exit program" << endl;*/