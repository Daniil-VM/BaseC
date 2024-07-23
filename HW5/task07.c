/*
 * HW05.task07; Решение задачи B7. "Две одинаковые цифры не рядом"
 * Ввести целое число и определить, верно ли, что в его записи есть
 * две одинаковые цифры, НЕ обязательно стоящие рядом.
 * Формат входных данных:
 *       Одно целое число
 * Формат результата:
 *       Единственное слово: YES или NO
 */

#include <stdio.h>

int main(int argc, char **argv)
{
   int num;
   scanf("%d", &num);

   int count[10] = {0};

   while (num > 0)
   {
      count[num % 10]++;
      num /= 10;
   }

   for (int i = 0; i < 10; ++i)
   {
      if (count[i] >= 2)
      {
         printf("YES\n");
         return 0;
      }
   }

   printf("NO\n");
   return 0;
}
