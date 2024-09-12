/*HW06.task02; Решение задачи C2. "Степень числа"
 * Составить функцию, возведение числа N в степень P. int power(n, p) и
 * привести пример ее использования.*/

#include <stdio.h>

int power(int n, int p)
{
   int result;
   result = n;

   switch (p == 0)
      {
      case 1:
         result = 1;
      break;
      default:
         for (int i = 1; i < p; i++)
         {
         result = result * n;
         }
      }
   return result;
}

int main(void)
{
   int n, p;

   scanf("%d %d", &n, &p);
   printf("%d", power(n, p));

   return 0;
}

