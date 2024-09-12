/*HW06.task01; Решение задачи C1. "Модуль числа"
 * Составить функцию, модуль числа и привести пример ее использования.*/

#include <stdio.h>

int abs(int);

int main(void)
{
   int number;

   scanf("%d", &number);
   printf("%d", abs(number));

   return 0;
}

int abs(int number)
{
   if (number < 0)
      return -number;
   else
      return number;
}
