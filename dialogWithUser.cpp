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
	cout << "exit - exit program" << endl;
	cout << "cls - clear screen" << endl;
}

string dialogWithUser::setPath()
{
	string path;
	cout << "Enter path to directory: ";
	cin >> path;
	return path;
}

FileManager& dialogWithUser::commandRoot(FileManager& a)
{
	a.showAllDisks();
	string disc;
	cout << "Выберите диск из списка и введите его букву D" << endl;
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
	cout << " Enter path to directory: ";
	string path;
	cin >> path;
	a.changeDirectoryDown(path)
		? cout << "Directory changed" << endl
		: cout << "Directory not found" << endl;
	return a;
}

FileManager& dialogWithUser::commandPd(FileManager& a)
{//проверяем что не корневой каталог, если нет переходим вверх
	//разбираем строку на символы в цикле проверям что не равно текущему пути
	for (int i = 0; i < a.getAllDisks().length(); i++)
	{

	}

 //находим в строке обр.слеш обрезаем
	
	
	
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