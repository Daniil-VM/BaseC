/*
 * HW05.task10; Решение задачи B11. "Перевернуть число"
 * Ввести целое число и «перевернуть» его, так чтобы первая цифра стала
 * последней и т.д.
 * Формат входных данных:
 *       Целое число
 * Формат результата:
 *       Единственное слово: YES или NO
 */

#include <stdio.h>

unsigned int revNum(unsigned int a)
{
   unsigned int b = 0;
   while (a > 0)
   {
      b = b * 10 + a % 10;
      //printf("%d, %d | ", b, a);
      a = a / 10;
      //printf("%d\n", a);
   }
   return b;
}

int main(int argc, char **argv)
{
   unsigned int num;
   scanf("%d", &num);
   printf("%d", revNum(num));

   return 0;
}
