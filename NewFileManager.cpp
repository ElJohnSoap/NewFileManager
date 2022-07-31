//Файловый менеджер должен иметь такие возможности :
//■ показывать содержимое дисков;
//■ создавать папки / файлы;
//■ удалять папки / файлы;
//■ переименовывать папки / файлы;
//■ копировать / переносить папки / файлы;
//■ вычислять размер папки / файла;
//■ производить поиск по маске(с поиском по подпапкам) и так далее.



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

#include "dialogWithUser.h"
#include "FileManager.h"
using namespace std;
namespace fs = filesystem;


int main(void)
{
	setlocale(LC_ALL, "ru");
	/*dialogWithUser dialog;

	dialog.receivingProcessingCommand();*/
	FileManager test;
	/*auto a = test.fileSearch("C:\\test\\test3\\*.txt");
	cout << a;*/
	}


//int main()
//{
//    setlocale(LC_ALL, "ru");
//    // Путь к целевой папке
//    std::string inPath = "C:\\Program Files\\*";// Обходим все файлы в папке
//    // Дескриптор для поиска
//   intptr_t handle;
//    struct _finddata_t fileinfo;
//    // Первый поиск
//    handle = _findfirst(inPath.c_str(), &fileinfo);
//    if (handle == -1)
//        return -1;
//    do
//    {
//        // Имя файла найденного файла
//        printf("%s\n", fileinfo.name);
//
//    } while (!_findnext(handle, &fileinfo));
//
//    _findclose(handle);
//    system("pause");
//    return 0;
//}
// 
// 
//struct _finddata_t c_file;
//intptr_t hFile;
//
//// Find first .c file in current directory
//if ((hFile = _findfirst("*.c", &c_file)) == -1L)
//printf("No *.c files in current directory!\n");
//else
//{
//    /*printf("Listing of .c files\n\n");
//    printf("RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ');
//    printf("--- --- --- ---  ----         ---- %25c ----\n", ' ');*/
//    do {
//        char buffer[30];
//        /*printf((c_file.attrib & _A_RDONLY) ? " Y  " : " N  ");
//        printf((c_file.attrib & _A_HIDDEN) ? " Y  " : " N  ");
//        printf((c_file.attrib & _A_SYSTEM) ? " Y  " : " N  ");
//        printf((c_file.attrib & _A_ARCH) ? " Y  " : " N  ");*/
//        ctime_s(buffer, _countof(buffer), &c_file.time_write);
//        printf(" %-12s %.24s  %9ld\n",
//            c_file.name, buffer, c_file.size);
//    } while (_findnext(hFile, &c_file) == 0);
//    _findclose(hFile);
//}

//Сделать обработку перехода на другой диск
