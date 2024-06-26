/*HW04.task04; Решение задачи А10. "Наименьшее из пяти чисел"
 * Ввести пять чисел и найти наименьшее из них.*/
#include <stdio.h>

int main (void)
{
   int a, b, c, d, e;

   scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
   if (b < a)
   {
      a = b;
   }
   if (c < a)
   {
      a = c;
   }
   if (d < a)
   {
      a = d;
   }
   if (e < a)
   {
      a = e;
   }
   printf("%d", a);
   return 0;
}
