/*HW04.task03; Решение задачи А9. "Наибольшее из пяти чисел"
 * Ввести пять чисел и найти наибольшее из них.*/
#include <stdio.h>

int main (void)
{
   int a, b, c, d, e;

   scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
   if (b > a)
   {
      a = b;
   }
   if (c > a)
   {
      a = c;
   }
   if (d > a)
   {
      a = d;
   }
   if (e > a)
   {
      a = e;
   }
   printf("%d", a);
   return 0;
}
