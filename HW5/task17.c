/*
 * HW05.task17; Решение задачи B17. "Счастливые числа"
 * Ввести натурально число и напечатать все числа от 10 до введенного
 * числа - у которых сумма цифр равна произведению цифр
 * Формат входных данных:
 *       Одно натуральное число большее 10
 * Формат результата:
 *       Числа у которых сумма цифр равна произведению цифр через пробел
 *       в порядке возрастания. Не превосходящие введенное число.
 */


#include <stdio.h>

int _sum(int a)
{
   int sum = 0;
   while(a > 0)
   {
      sum += a % 10;
      a /= 10;
   }
   return sum;
}

int _prod(int a)
{
   int prod = 1;
   if(a == 0)
      return 0;
   else
   while(a > 0)
   {
      prod *= a % 10;
      a /= 10;
   }
   return prod;
}

int main(int argc, char **argv)
{
   int num, sum, prod;
   scanf("%d", &num);

   for(int i = 10; i <= num; ++i)
   {
      sum = _sum(i);
      prod = _prod(i);
      if(sum == prod)
         printf("%d ", i);
   }
   return 0;
}
