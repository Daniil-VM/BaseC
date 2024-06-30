/*HW05.task05; Решение задачи B5. "Сумма цифр"
 * Ввести целое число и найти сумму его цифр.*/

#include <stdio.h>

int main(int argc, char **argv)
{
   int num, sum = 0;

   scanf("%d", &num);

   for (; num > 0;)
   {
      sum += num % 10;
      num /= 10;
   }

   printf("%d\n", sum);

   return 0;
}
