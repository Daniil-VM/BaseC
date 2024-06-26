/*HW04.task08; Решение задачи А16. "В порядке возрастания"
 * Ввести три числа и определить, верно ли, что они вводились в поряд-
 * ке возрастания.*/
#include <stdio.h>

int main (void)
{
   int a, b, c;

   scanf("%d %d %d", &a, &b, &c);
   if (a < b && b < c)
      printf("YES");
   else
      printf("NO");
}
