/*Сдать решение задачи G3-Последний символ - номера
Имя входного файла:	input.txt
Имя выходного файла:	output.txt

Последний номер символа
В файле input.txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом 
строки. Результат записать в файл output.txt
Формат входных данных
   Строка не более 1000 символов
Формат результата
   Целые числа через пробел - номера символа, который совпадает с последним символом строки*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
   FILE *input_file = fopen("input.txt", "r");
   FILE *output_file = fopen("output.txt", "w");

   if (input_file == NULL || output_file == NULL)
   {
      printf("Ошибка открытия файла.\n");
      return 1;
   }

   // Динамическое выделение памяти для строки
   char *input_string = (char *)malloc(MAX_LENGTH * sizeof(char));
   if (input_string == NULL)
   {
      printf("Ошибка выделения памяти.\n");
      return 1;
   }

   // Чтение строки из файла
   size_t length = 0;
   size_t capacity = MAX_LENGTH;
   int c;
   while ((c = fgetc(input_file)) != EOF)
   {
      if (length + 1 >= capacity)
      {
         capacity *= 2;
         input_string = (char *)realloc(input_string, capacity * sizeof(char));
         if (input_string == NULL)
         {
            printf("Ошибка перераспределения памяти.\n");
            return 1;
         }
      }
      input_string[length++] = (char)c;
   }
   input_string[length] = '\0'; // Добавляем завершающий нулевой символ

   // Убираем символ новой строки, если он есть
   if (length > 0 && input_string[length - 1] == '\n')
   {
      input_string[--length] = '\0';
   }

   char last_char = input_string[length - 1];

   // Вывод номеров символов, совпадающих с последним символом
   for (size_t i = 0; i < length - 1; i++)
   {
      if (input_string[i] == last_char)
      {
         fprintf(output_file, "%zu ", i);
      }
   }

   // Освобождаем память и закрываем файлы
   free(input_string);
   fclose(input_file);
   fclose(output_file);

   return 0;
}

