/*
 * HW05.task13; Решение задачи B13. "Количество четных и нечетных цифр"
 * Посчитать количество четных и нечетных цифр числа.
 * Формат входных данных:
 *       Одно целое неотрицательное число.
 * Формат результата:
 *       Два числа через пробел. Количество четных и нечетных цифр
 *       в числе.
 */


#include <stdio.h>

int main(int argc, char **argv)
{
   unsigned int number;
   scanf("%u", &number);

   int temp;
   int oddDigit = 0, evenDigit = 0;
   while(number !=0)
      {
         temp = number % 10;
         if(temp == 0 || temp % 2 == 0)
            evenDigit++;
         else
            oddDigit++;
         number /= 10;
      }
   printf("%d %d", evenDigit, oddDigit);

   return 0;
}

