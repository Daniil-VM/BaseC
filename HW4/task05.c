/*HW04.task05; Решение задачи А11. "Сумма максимума и минимума"
 * Напечатать сумму максимума и минимума.*/
#include <stdio.h>

int main (void)
{
   int a, b, c, d, e, min, max;

   scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
   min = a; max = a;
   //Поиск максимума:
   if (b > a)
   {
      max = b;
   }
   if (c > b)
   {
      max = c;
   }
   if (d > c)
   {
      max = d;
   }
   if (e > d)
   {
      max = e;
   }
   //Поиск минимума:
   if (b < a)
   {
      min = b;
   }
   if (c < b)
   {
      min = c;
   }
   if (d < c)
   {
      min = d;
   }
   if (e < d)
   {
      min = e;
   }
   printf("%d", max + min);
   return 0;
}
