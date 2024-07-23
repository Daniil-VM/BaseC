/*
 * HW05.task08; Решение задачи B8. "Ровно одна цифра 9"
 * Ввести целое число и определить, верно ли, что в нём ровно одна
 * цифра «9».
 * Формат входных данных:
 *       Одно целое число
 * Формат результата:
 *       Единственное слово: YES или NO
 */

#include <stdio.h>

int main(int argc, char **argv)
{
   int num, count = 0;
   scanf("%d", &num);

// Поиск цифры 9
   while (num != 0)
   {
      if (num % 10 == 9 || num % 10 == -9)
            count++;
      num = num / 10;
   }

// Вывод результата
   count == 1 ? printf("YES") : printf("NO");

   return 0;
}

