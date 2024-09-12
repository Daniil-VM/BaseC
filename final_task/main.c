#include "temp_functions.h"

int main(int argc, char *argv[]) 
{
    const char *filename = NULL;
    int month = DEFAULT_MONTH;
    
    /*
    Функция handleArguments() принимает аргументы командной строки от пользователя,
    выводит информацию о программе и сообщает о критичных ошибках для дальнейшей 
    работы программы, далее управление полностью передаётся функции processFile().
    */
    handleArguments(argc, argv, &filename, &month);

    /*Вывод сообщения с кратким описанием программы в случае запуска без аргументов*/
    if (!filename) 
    {
        printHelp();
        return 1;
    }

    int filterMonth = month;
     /*
    Все манипуляции с файлом происходят внутри функции processFile().
    Выделение памяти, чтение файла, проверка правильности заполнения CSV-файла,
    вычисление и вывод статистических данных, вывод сообщений об ошибках.
    */
    processFile(filename, month, filterMonth);

    return 0;
}