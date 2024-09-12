/*Сдать решение задачи G4-Совпадения букв
Имя входного файла:	input.txt
Имя выходного файла:	output.txt

По одному разу
В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
Формат входных данных
   Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Формат результата
   Маленькие английские буквы через пробел.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Функция для подсчета частоты символов в строке
void count_frequencies(const char *str, int *freq)
{
   for (int i = 0; str[i] != '\0'; i++)
   {
      freq[str[i] - 'a']++;
   }
}

// Функция для сортировки символов в лексикографическом порядке
void sort_characters(char *chars, int count)
{
   for (int i = 0; i < count - 1; i++)
   {
      for (int j = i + 1; j < count; j++)
      {
         if (chars[i] > chars[j])
         {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
         }
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

   char word1[MAX_LENGTH + 1];
   char word2[MAX_LENGTH + 1];

   // Чтение двух слов из файла
   if (fscanf(input_file, "%s %s", word1, word2) != 2)
   {
      printf("Ошибка чтения файла.\n");
      return 1;
   }

   // Массивы для подсчета частоты символов
   int freq1[26] = {0};
   int freq2[26] = {0};

   count_frequencies(word1, freq1);
   count_frequencies(word2, freq2);

   // Массив для хранения символов, которые встречаются только один раз в обоих словах
   char unique_chars[26];
   int unique_count = 0;

   for (int i = 0; i < 26; i++)
   {
      if (freq1[i] == 1 && freq2[i] == 1)
      {
         unique_chars[unique_count++] = 'a' + i;
      }
   }

   // Сортировка символов в лексикографическом порядке
   sort_characters(unique_chars, unique_count);

   // Запись результата в файл
   for (int i = 0; i < unique_count; i++)
   {
      fprintf(output_file, "%c ", unique_chars[i]);
   }

   // Закрытие файлов
   fclose(input_file);
   fclose(output_file);

   return 0;
}
