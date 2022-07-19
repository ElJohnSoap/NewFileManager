#pragma once
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
using namespace std;

class FileManager
{
private:
	string currentPath;

public:
	
	FileManager (string path) : currentPath { path } {}
	FileManager() : FileManager("C:\\") {}

	string getCurrenPath();
	void setCurrentPath(string path);

	void ShowAllDisks();

	void ShowFolderContents();
	



};

