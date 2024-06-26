/*HW04.task02; Решение задачи А8. "Наибольшее из трех чисел"
 * Ввести три числа и найти наибольшее из них.*/
#include <stdio.h>

int main (void)
{
   int a, b, c, max;

   scanf("%d %d %d", &a, &b, &c);
   max = a;
   if (b > a)
   {
      max = b;
   }
   if (c > b)
   {
      max = c;
   }
   printf("%d", max);

   return 0;
}
