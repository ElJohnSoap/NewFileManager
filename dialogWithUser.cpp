#include "dialogWithUser.h"
#include "FileManager.h"
using namespace std;

void dialogWithUser::help()
{
	cout << "Assistent \n";
	cout << "help - help" << endl;
	cout << "cd  - change directory" << endl;
	cout << "pd  - go to the parent directory" << endl;
	cout << "root - root directory" << endl;
	cout << "all - show directory" << endl;
	cout << "cfo - create folder" << endl;
	cout << "cfi - create file" << endl;
	cout << "delfi - delete file" << endl;
	cout << "deldir - delete folder" << endl;
	cout << "refile - rename file" << endl;
	cout << "refol - rename folder" << endl;
	cout << "exit - exit program" << endl;
	cout << "cls - clear screen" << endl;
}

string dialogWithUser::setName()
{
	string path;
	cout << "Enter name: ";
	cin >> path;
	return path;
}

FileManager& dialogWithUser::commandRoot(FileManager& a)
{
	a.showAllDisks();
	string disc;
	cout << "Выберите диск из списка и введите его букву (пример: D" << endl;
	cin >> disc;
	if (strstr(a.getAllDisks().c_str(), disc.c_str()))
	{
		disc = disc + ":\\";
		a.setCurrentPath(disc);
		return a;
	}
	else 
	{
		cout << "Диск не найден" << endl;
		return a;
	}
	
}

FileManager& dialogWithUser::commandCd(FileManager& a)
{
	// проверка на наличие папки
	string folder = setName();
	if (a.directorySearch(folder))
	{
		a.setCurrentPath(a.getCurrenPath() + folder + "\\");
		//a.getCurrenPath() = a.getCurrenPath() + folder + "\\";
		cout << "Directory changed" << endl;
	}
	else 
		cout << "Directory not found" << endl;
	
	return a;
}

FileManager& dialogWithUser::commandPd(FileManager& a)
{//проверяем что не корневой каталог, если нет переходим вверх
	//разбираем строку на символы в цикле проверям что не равно текущему пути
	for (int i = 0; i < a.getAllDisks().length(); i++)
	{
		string temp(1, a.getAllDisks()[i]);
		temp = temp + ":\\";
		//cout << temp << endl;
		if (temp == a.getCurrenPath())
		{
			cout << "You are in root directory" << endl;
			return a;
		}
	}
	string s2 = "\\";
	string s = a.getCurrenPath();
	/*cout << s.rfind(s2);*/
	s.erase(s.rfind(s2)); //удаляем последний слеш
	s.erase(s.rfind(s2)); //удаляем имя директории и последний слеш 
	/*cout << s;*/
	s = s + "\\";
	a.setCurrentPath(s);
}

FileManager& dialogWithUser::commandCfo(FileManager& a)
{
	// проверяем что такой директории нет и создаем
	
	string folder = setName();
	string nameFolderFull = a.getCurrenPath() + folder + "\\";
	if (a.directorySearch(folder))
	{
		cout << "the directory already exists" << endl;
	}
	else
	{
		a.createFolder(nameFolderFull);
		cout << "directory created" << endl;	
	}
	return a;	
}

FileManager& dialogWithUser::commandCfi(FileManager& a)
{
	string nameFile = setName();
	string nameFileFull = a.getCurrenPath() + nameFile;
	a.createFile("C:\\test\\12345.txt" );
	return a;
}

FileManager& dialogWithUser::commandDelDir(FileManager& a)
{
	 string folder = setName();
	 string nameFolderFull = a.getCurrenPath() + folder;
	if (a.directorySearch(folder))
	{
		a.deleteFolder(nameFolderFull);
		cout << "directory deleted" << endl;
	}
	else
		cout << "directory not found" << endl;
	return a;
}

FileManager& dialogWithUser::commandDelFi(FileManager& a)
{
	string nameFile = setName();
	string nameFileFull = a.getCurrenPath() + nameFile;
	a.deleteFile(nameFileFull);
	return a;
}
FileManager& dialogWithUser::commandReFol(FileManager& a)
{
	string oldName = setName();
	if (a.directorySearch(oldName))
	{
		oldName = a.getCurrenPath() + oldName;
		string newName = a.getCurrenPath() + setName();
		a.renameFolder(oldName, newName);
		cout << "directory renamed" << endl;
	}
	else
		cout << "directory not found" << endl;
	return a;
}

FileManager& dialogWithUser::commandReFile(FileManager& a)
{
	string oldName = setName();
	if (a.fileSearch(oldName))
	{
		oldName = a.getCurrenPath() + oldName;
		string newName = a.getCurrenPath() + setName();
		a.renameFile(oldName, newName);
		cout << "file renamed" << endl;
	}
	else
		cout << "file not found" << endl;
	return a;
	
	//std::filesystem::exists("helloworld.txt");//!!!!!!!!!!!!!

}


void dialogWithUser::receivingProcessingCommand()
{
	FileManager tempPath; // объект класса FileManager
	
	do
	{
		tempPath.showCurrentPath();
		//cout << "Enter command: ";
		cin >> command;

		if (command == "exit")
		{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else if (command == "root")
		{
			commandRoot(tempPath);
		}
		else if (command == "help")
		{
			help();
		}
		else if (command == "all")
		{
			tempPath.showFolderContents();
		}
		else if (command == "cd")
		{
			commandCd(tempPath);
		}
		else if (command == "pd")
		{
			commandPd(tempPath);
		}
		else if (command == "cfo")
		{
			commandCfo(tempPath);
		}
		else if (command == "cfi")
		{
			commandCfi(tempPath);
		}
		else if (command == "delfi")
		{
			commandDelFi(tempPath);
		}
		else if (command == "deldir")
		{
			commandDelDir(tempPath);
		}
		else if (command == "refol")
		{
			commandReFol(tempPath);
		}
		else if (command == "cls")
		{
			system("cls");
		}
		else
		{
			cout << "Command not found" << endl;
		}		
	} 
	while (command != "exit");
}

/*else if (command == "dir")
		{
			cout << "Directory: " << endl;
			for (auto& p : fs::directory_iterator("."))
			{
				cout << p.path().filename() << endl;
			}
		}
		else if (command == "cd")
		{
			cout << "Enter directory: ";
			string directory;
			getline(cin, directory);
			_chdir(directory.c_str());
		}
		else if (command == "mkdir")
		{
			cout << "Enter directory: ";
			string directory;
			getline(cin*/