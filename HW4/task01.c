/*HW04.task01; Решение задачи А7. "Наибольшее из чисел"
 * Ввести два числа и вывести их в порядке возрастания.*/
#include <stdio.h>

int main (void)
{
   int a, b;

   scanf("%d %d", &a, &b);
   if (a >= b)
   {
      printf("%d %d", b, a);
   }
   else
   {
      printf("%d %d", a, b);
   }
   return 0;
}
