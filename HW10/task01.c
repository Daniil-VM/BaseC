/*Сдать решение задачи G1-Три раза
Имя входного файла:	input.txt
Имя выходного файла:	output.txt

Три раза
В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов 
в ней.
Формат входных данных
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Формат результата
   Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.*/

#include <stdio.h>
#include <string.h>

int main()
{
   FILE *input_file = fopen("input.txt", "r");
   FILE *output_file = fopen("output.txt", "w");

   if (input_file == NULL || output_file == NULL)
   {
      printf("Ошибка открытия файла.\n");
      return 1;
   }

   char input_string[101];
   fgets(input_string, sizeof(input_string), input_file);

   // Удаляем возможный символ новой строки в конце строки
   input_string[strcspn(input_string, "\n")] = '\0';

   int length = strlen(input_string);

   // Выводим строку три раза через запятую и пробел
   fprintf(output_file, "%s, %s, %s %d\n", input_string, input_string, input_string, length);

   fclose(input_file);
   fclose(output_file);

   return 0;
}
