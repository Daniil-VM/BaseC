/*HW05.task03; Решение задачи B3. "Сумма квадратов"
 * Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от
 * a до b.*/

#include <stdio.h>

int main(int argc, char **argv)
{
   int i, a, b, square, sum;
   sum = 0;

   scanf("%d %d", &a, &b);
   for (i = a; i <= b; i++)
   {
      square = i * i;
      sum += square;
   }
   printf("%d ", sum);
   return 0;
}
