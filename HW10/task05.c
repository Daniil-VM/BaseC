/*Сдать решение задачи G5-Заменить a на b
Имя входного файла:	input.txt
Имя выходного файла:	output.txt

Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" 
и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
Формат входных данных
   Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Формат результата
   Строка из маленьких и больших английских букв, знаков препинания и пробелов.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Функция для замены букв "a" на "b" и наоборот
void replace_ab(char *str)
{
   for (int i = 0; str[i] != '\0'; i++)
   {
      if (str[i] == 'a')
      {
         str[i] = 'b';
      } else if (str[i] == 'b')
      {
         str[i] = 'a';
      } else if (str[i] == 'A')
      {
         str[i] = 'B';
      } else if (str[i] == 'B')
      {
         str[i] = 'A';
      }
   }
}

int main()
{
   FILE *input_file = fopen("input.txt", "r");
   FILE *output_file = fopen("output.txt", "w");

   if (input_file == NULL || output_file == NULL)
   {
      printf("Ошибка открытия файла.\n");
      return 1;
   }

   char input_string[MAX_LENGTH + 1];

   // Чтение строки из файла
   if (fgets(input_string, MAX_LENGTH + 1, input_file) == NULL)
   {
      printf("Ошибка чтения файла.\n");
      return 1;
   }

   // Замена букв "a" на "b" и наоборот
   replace_ab(input_string);

   // Запись результата в файл
   fprintf(output_file, "%s", input_string);

   // Закрытие файлов
   fclose(input_file);
   fclose(output_file);

   return 0;
}
