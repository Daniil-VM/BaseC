/*HW05.task02; Решение задачи B2. "Квадраты от А до В"
 * Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от
 * a до b.*/

#include <stdio.h>

int main(int argc, char **argv)
{
   int i, a, b, square;

   scanf("%d %d", &a, &b);
   for (i = a; i <= b; i++)
   {
      square = i * i;
      printf("%d ", square);
   }
   return 0;
}
