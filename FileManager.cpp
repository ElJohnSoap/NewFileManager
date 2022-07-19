#include "FileManager.h"

string FileManager::getCurrenPath()
{
	return currentPath;
}

void FileManager::setCurrentPath(string path)
{
	currentPath = path;
}

void FileManager::ShowAllDisks()
{
    const DWORD buffer_length = 104;
    WCHAR buffer[buffer_length + 1] = { 0 }; // room for null terminator

    GetLogicalDriveStrings(buffer_length, buffer);
    set<wchar_t> drives_letters;

    for (wchar_t* drive = buffer; *drive != 0; drive += 4)
    {
        drives_letters.insert(*drive);
    }

    set<wchar_t>::iterator itSet = drives_letters.begin(); //итератор для контейнера
    for (int i = 1; itSet != drives_letters.end(); i++, itSet++)
    {
        cout << char(*itSet) << ":\\ ";
    }
}

void FileManager::ShowFolderContents()
{
    //Запросим ПУТЬ (например, папка Temp на диске C,
        //запишется таким вот образом: c:\temp\)
    char path[70];
    cout << "\nEnter full path (for example, C:\\):";
    cin >> path;
    //Запросим маску файлов
    char mask[] = "*.*";
    /*cout << "\nEnter mask (for example, *.* or *.txt):";
    cin >> mask;*/
    //Соединив две строки, мы получим результат
    //т.е. что хочет найти пользователь и где
    strcat(path, mask);

    //Объявление указателя fileinfo
    //на структуру _finddata_t
    //и создание динамического объекта
    //структуры _finddata_t
    _finddata_t* fileinfo = new _finddata_t;
    //Начинаем поиск
    intptr_t done = _findfirst(path, fileinfo);
    //если done будет равняться -1,
    //то поиск вести бесмысленно
    int MayWeWork = done;
    //Счетчик, содержит информацию о количестве
    //найденых файлов.
    int count = 0;
    while (MayWeWork != -1)
    {
        count++;
        //Распечатали имя найденного файла
        cout << fileinfo->name << "\n\n";
        //Пытаемся найти следующий файл из группы
        MayWeWork = _findnext(done, fileinfo);
    }
    //Вывод сообщения о количестве найденных файлов.
    cout << "\nInformation: was found " << count;
    cout << " file(s) in folder..." << path << "\n\n";
    //Очистка памяти
    _findclose(done);
    delete fileinfo;
}
