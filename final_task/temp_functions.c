#include "temp_functions.h"

// Функция считывания аргументов командной строки
void handleArguments(int argc, char *argv[], const char **filename, int *month)
{
   for (int i = 1; i < argc; i++)
   {
      if (strcmp(argv[i], "-h") == 0)
     {
         printInfo();
         exit(0);
     } else if (strcmp(argv[i], "-f") == 0)
     {
         if (i + 1 < argc)
         {
            *filename = argv[++i];
         } else
            {
               fprintf(stderr, "Ошибка: -для f требуется имя файла.\n");
               exit(1);
            }
         } else if (strcmp(argv[i], "-m") == 0)
            {
               if (i + 1 < argc)
               {
                  *month = atoi(argv[++i]);
                  if (*month < 1 || *month > 12)
                  {
                     fprintf(stderr, "Ошибка: Месяц должен быть между 1 и 12.\n");
                     exit(1);
                  }
               } else
               {
                  fprintf(stderr, "Ошибка: -для m требуется номер месяца.\n");
                  exit(1);
               }
            } else
            {
               fprintf(stderr, "Ошибка: Неизвестный аргумент %s\n", argv[i]);
               exit(1);
            }
   }
}

// Функция считывания данных из файла
bool parseCSV(const char *filename, TemperatureRecord **records, int *count, int filterMonth)
{
   FILE *file = fopen(filename, "r");
   
   if (!file)
   {
      perror("Ошибка при открытии файла");
      return false;
   }

   char line[MAX_LINE_LENGTH];
   int capacity = 10; // Устанавливаем вместимость массива
   *records = malloc(capacity * sizeof(TemperatureRecord));
   *count = 0;
   int lineNumber = 0;

   while (fgets(line, sizeof(line), file))
   {
      lineNumber++;
      char errorMsg[1024] = {0}; // Буфер для детализированного сообщения об ошибке

      if (*count >= capacity)
      {
         capacity *= 2; // Увеличиваем вместимость массива в случае нехватки места
         *records = realloc(*records, capacity * sizeof(TemperatureRecord));
      }

      TemperatureRecord record;
      initializeRecord(&record);
      int parseCount = sscanf(line, "%d;%d;%d;%d;%d;%d",
                  &record.year, &record.month, &record.day,
                  &record.hour, &record.minute, &record.temperature);

      if(parseCount != 6)           
      {
         if(filterMonth == 0 || filterMonth == record.month)
         {
            formatCheck(&record, line, filterMonth, errorMsg);
            fprintf(stderr, "Внимание! Недопустимый формат строки № %d\n", lineNumber);
            fprintf(stderr, "%s\n", errorMsg);
         }
         continue; // Пропускаем запись, если проверки не пройдены
      }
      // Проверка данных после успешного разбора строки
      if(!formatCheck(&record, line, filterMonth, errorMsg))
      {
         if (filterMonth == 0 || filterMonth == record.month)
            {
               fprintf(stderr, "Внимание! Cтрока № %d не прошла проверку формата данных.\n", lineNumber);
               fprintf(stderr, "%s\n", errorMsg);
            }
            continue; // Пропускаем запись, если проверки не пройдены
      }
    
      (*records)[*count] = record;
      (*count)++;
   }

   fclose(file);
   return true;
}

// Функция проверки формата записи
int formatCheck(TemperatureRecord *record, const char *line, int filterMonth, char *errorMsg)
{
   // Проверка года
   if (record->year < 1000 || record->year > 9999)
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимый год в строке: %s", line);
      }
      return false;
   }

   // Проверка месяца
   if (record->month < 1 || record->month > 12)
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимый месяц в строке: %s", line);
      }
      return false;
   }

   // Проверка дня
   if (!isValidDay(record->day, record->month, record->year))
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимый день для месяца %s в строке: %s", monthReturn(record->month), line);
      }
      return false;
   }

   // Проверка часа
   if (record->hour < 0 || record->hour > 23)
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимый час в строке: %s", line);
      }
      return false;
   }

   // Проверка минут
   if (record->minute < 0 || record->minute > 59)
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимая минута в строке: %s", line);
      }
      return false;
   }

   // Проверка температуры
   if (record->temperature < -99 || record->temperature > 99)
   {
      if (filterMonth == 0 || record->month == filterMonth)
      {
         sprintf(errorMsg, "Недопустимая температура в строке: %s", line);
      }
      return false;
   }

   return true;
}

// Проверка на високосный год
bool isLeapYear(int year)
{
   return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Проверка записи дней
bool isValidDay(int day, int month, int year)
{
   // Проверка дней для месяцев с 31 днем
   if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
   {
      return (day >= 1 && day <= 31);
   }
   // Проверка дней для месяцев с 30 днями
   if (month == 4 || month == 6 || month == 9 || month == 11)
   {
      return (day >= 1 && day <= 30);
   }
   // Проверка дней для февраля
   if (month == 2)
   {
      return (isLeapYear(year) ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28));
   }

   return false;
}

// Анализ данных и вывод статистики в консоль
void processFile(const char *filename, int month, int filterMonth)
{
   if (!filename) {
      fprintf(stderr, "Ошибка: имя файла не указано.\n");
      return;
   }

   TemperatureRecord *records = NULL;
   int count = 0;
   if (!parseCSV(filename, &records, &count, filterMonth))
   {
      return;
   }

   if (month == DEFAULT_MONTH)
   {
      YearlyStats yearly_stats = computeYearlyStats(records, count);
      printf("Годовая статистика:\n");
      printf("Средняя температура: %.2f\n", yearly_stats.avg_temp);
      printf("Минимальная температура: %d\n", yearly_stats.min_temp);
      printf("Максимальная температура: %d\n", yearly_stats.max_temp);

      printf("\nМесячная статистика:\n");
      printf("|  Месяц  | Сред. Темп | Мин. Темп | Макс. Темп |\n");
      printf("|---------|------------|-----------|------------|\n");

      for (int m = 1; m <= MONTHS_IN_YEAR; m++)
      {
         MonthlyStats monthly_stats = computeMonthlyStats(records, count, m);
         printf("| %4d    | %10.2f | %9d | %10d |\n", m, monthly_stats.avg_temp, 
                                                      monthly_stats.min_temp, monthly_stats.max_temp);
      }
   } else
   {
      MonthlyStats monthly_stats = computeMonthlyStats(records, count, month);
      printf("Статистика за %s:\n", monthReturn(month));
      printf("Средняя температура: %.2f\n", monthly_stats.avg_temp);
      printf("Минимальная температура: %d\n", monthly_stats.min_temp);
      printf("Максимальная температура: %d\n", monthly_stats.max_temp);
   }

   free(records);
}

MonthlyStats computeMonthlyStats(const TemperatureRecord *records, int count, int month)
{
   MonthlyStats stats = {0, 0, 0};
   int total_temp = 0;
   int count_temp = 0;

   stats.min_temp = 100; // Инициализирую до максимального значения
   stats.max_temp = -100; // Инициализирую до минимального значения

   for (int i = 0; i < count; i++)
   {
      if (records[i].month == month)
      {
         total_temp += records[i].temperature;
         count_temp++;
         if (records[i].temperature < stats.min_temp)
         {
            stats.min_temp = records[i].temperature;
         }
            if (records[i].temperature > stats.max_temp)
            {
               stats.max_temp = records[i].temperature;
            }
      }
   }

   if (count_temp > 0)
   {
      stats.avg_temp = (float)total_temp / count_temp;
   } else
   {
      stats.avg_temp = 0;
      stats.min_temp = 0;
      stats.max_temp = 0;
   }

   return stats;
}

YearlyStats computeYearlyStats(const TemperatureRecord *records, int count)
{
   YearlyStats stats = {0, 0, 0};
   int total_temp = 0;
   int count_temp = 0;

   stats.min_temp = 100; // Инициализирую до максимального значения
   stats.max_temp = -100; // Инициализирую до минимального значения

   for (int i = 0; i < count; i++)
   {
      total_temp += records[i].temperature;
      count_temp++;
      if (records[i].temperature < stats.min_temp)
      {
         stats.min_temp = records[i].temperature;
      }
      if (records[i].temperature > stats.max_temp)
      {
            stats.max_temp = records[i].temperature;
      }
   }

   if (count_temp > 0)
   {
      stats.avg_temp = (float)total_temp / count_temp;
   } else
   {
      stats.avg_temp = 0;
      stats.min_temp = 0;
      stats.max_temp = 0;
   }

   return stats;
}

void printHelp()
{
   printf("\nИспользование: temp_stats.\n");
   printf("Консольное приложение для вывода статистики измерений температурного датчика.\n");
   printf("Для получения подробной информации о назначении и функционале приложения введите:\n");
   printf("\"call temp_stats.exe -h\" - для запуска из cmd\n");
   printf("Замените \"call\" на \"./\" - для запуска из PowerShell и Bash\n");
}

void printInfo()
{
   printf("\nКонсольное приложение temp_stats.\n");
   printf("Назначение:\n");
   printf("Вывод статистики показаний датчика температуры по году и месяцам.\n");
   printf("Осуществляет считывание текстового файла csv, состоящего из строк следующего формата:\n");
   printf("\"yyyy;mm;dd;hh;mm;xx\", в случае неверного формата заполнения, выводит сообщения об ошибках.\n");
   printf("Приложение поддерживает следующий набор ключей:\n");
   printf("  -h               Описание функционала приложения. Список ключей.\n");
   printf("  -f <filename>    Передать наименование CSV-файла для обработки\n");
   printf("  -m <month>       Показать статистику за указанный месяц (от 1 до 12)\n");
   printf("Примеры ввода команд:\n");
   printf("\"call temp_stats.exe -f temperature_small.csv\" ... передает наименование CSV-файла для обработки\n");
   printf("\"call temp_stats.exe -f temperature_small.csv -m 1\" ... показывает статистику за указанный месяц\n");
}

void initializeRecord(TemperatureRecord *record)
{
   int year = 404;
   int month = 404;
   int day = 404;
   int hour = 404;
   int minute = 404;
   int temperature = 404;

   record->year = year;
   record->month = month;
   record->day = day;
   record->hour = hour;
   record->minute = minute;
   record->temperature = temperature;
}

const char* monthReturn(int month)
{
   static const char* months[] = 
   {
      "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
      "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
   };

   return months[month - 1];
}