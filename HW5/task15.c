/*
 * HW05.task14; Решение задачи B14. "НОД"
 * Составить программу для вычисления НОД с помощью алгоритма Евклида.
 * Даны два натуральных числа. Найти наибольший общий делитель.
 * Формат входных данных:
 *       Два неотрицательных целых числа
 * Формат результата:
 *       Одно целое число наибольший общий делитель
 */

#include <stdio.h>

int main(int argc, char **argv)
{
   int a, b, t;
   scanf("%d, %d", &a, &b);

   while (b != 0)
   {
      t = b;
      b = a % b;
      a = t;
   }
   printf("NOD=%d\n",a);
   return 0;


/*   int i=0, y;
   if (a == b)
   {
      printf("%d (1)", a);
      return 0;
   }
   else
   if (a > b)
   {
      i = b;
      y = a;
   }
   else
   {
      y = b;
      i = a;
   }
   for (; i > 0; i--)
   {
      printf("%d (2)", i);
      if (y % i == 0)
      {
         printf("%d (3)", i);
      }
   }

   if (a > b)
      printf("%d", a);
   else
      printf("%d", a);
*/
   return 0;
}

