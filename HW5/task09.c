/*
 * HW05.task09; Решение задачи B9. "Все цифры четные"
 * Ввести целое число и определить, верно ли, что все его цифры четные.
 * Формат входных данных:
 *       Одно целое число
 * Формат результата:
 *       Единственное слово: YES или NO
 */

#include <stdio.h>

int main(int argc, char **argv)
{
   int num, evenCount, oddCount;
   evenCount = 0;
   oddCount = 0;
   scanf("%d", &num);

// Поиск четных цифр
   while (num != 0)
   {
      num % 10 % 2 == 0 ? evenCount++ : oddCount++;
      num = num / 10;
   }

// Вывод результата
   oddCount == 0 ? printf("YES") : printf("NO");

   return 0;
}
