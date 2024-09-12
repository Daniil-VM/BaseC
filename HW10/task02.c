/*Сдать решение задачи G2-Строка и цифры
Имя входного файла:	input.txt

Строка и цифры
Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt
Формат входных данных
   Четное N ≤ 26
Формат результата
   Строка из английских букв и цифр*/

#include <stdio.h>

int main()
{
   FILE *input_file = fopen("input.txt", "r");
   FILE *output_file = fopen("output.txt", "w");

   if (input_file == NULL || output_file == NULL)
   {
      printf("Ошибка открытия файла.\n");
      return 1;
   }

   int N;
   fscanf(input_file, "%d", &N);

   if (N % 2 != 0 || N > 26)
   {
      printf("Некорректное значение N.\n");
      return 1;
   }

   char result[N + 1];
   result[N] = '\0'; // Завершающий нулевой символ для строки

   int even_digit = 2; // Начинаем с 2, так как 0 не используется
   char letter = 'A';

   for (int i = 0; i < N; i++)
   {
      if (i % 2 == 0)
      {
         result[i] = letter++; // Заполняем нечетные позиции буквами
      } else
      {
         result[i] = '0' + even_digit; // Заполняем четные позиции цифрами
         even_digit += 2; // Переходим к следующей четной цифре
            if (even_digit > 8) 
            {
                even_digit = 2; // Если цифра превышает 8, начинаем снова с 2
            }
      }
   }

   fprintf(output_file, "%s\n", result);

   fclose(input_file);
   fclose(output_file);

   return 0;
}
