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
#include <direct.h>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = filesystem;

class FileManager
{
private:
	string currentPath;
	string allDiscs;

public:
	
	FileManager() 
	{
		stringAllDisks(allDiscs);
		string first = allDiscs.substr(0, 1);
		currentPath = first + ":\\";
	}

	string getCurrenPath();
	
	string getAllDisks();
	
	void setCurrentPath(string path);

	void showAllDisks();	//show all disks

	void stringAllDisks(string &a);// получает все диски и записывает их в строку a

	void showFolderContents();// show all files and folders in current path

	void createFolder(string path);	

	void deleteFolder(string path);
	
	void renameFolder (string path, string newName);
	
	bool directorySearch(string folder); // если находит папку возвращает тру
	
	bool fileSearch(); // если находит файл возвращает тру
		
	void createFile (string path);
	
	void deleteFile(string path);
	
	void renameFile(string path, string newName);
	
	int fileSize(string path);
	
	void showCurrentPath ();
};

