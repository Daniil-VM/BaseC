#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Структуры и константы
#define MAX_LINE_LENGTH 100
#define MONTHS_IN_YEAR 12
#define DEFAULT_MONTH 0 // 0 означает отсутствие определенного месяца

// Определение структуры TemperatureRecord
typedef struct 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureRecord;

// Определение структуры MonthlyStats
typedef struct 
{
    float avg_temp;
    int min_temp;
    int max_temp;
} MonthlyStats;

// Определение структуры YearlyStats
typedef struct 
{
    float avg_temp;
    int min_temp;
    int max_temp;
} YearlyStats;

// Вывод информации о программе
void printHelp();
void printInfo();

// Основные функции
void handleArguments(int argc, char *argv[], const char **filename, int *month);
void processFile(const char *filename, int month, int filterMonth);

// Функции для работы с CSV-файлом и сбора статистики
bool parseCSV(const char *filename, TemperatureRecord **records, int *count, int filterMonth);
int formatCheck(TemperatureRecord *record, const char *line, int filterMonth, char *errorMsg);
MonthlyStats computeMonthlyStats(const TemperatureRecord *records, int count, int month);
YearlyStats computeYearlyStats(const TemperatureRecord *records, int count);

// Вспомогательные функции
bool isLeapYear(int year);
bool isValidDay(int day, int month, int year);
void initializeRecord(TemperatureRecord *record);
const char* monthReturn(int month);

#endif // TEMP_FUNCTIONS_H