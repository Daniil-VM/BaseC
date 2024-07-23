/*
 * HW05.task19; Решение задачи B19. "Сумма цифр равна 10"
 * Ввести натуральное число и определить, верно ли, что сумма его цифр
 * равна 10.
 * Формат входных данных:
 *       Натуральное число
 * Формат результата:
 *       YES или NO
 */



#include <stdio.h>


int main(int argc, char **argv)
{
   int num;
   scanf("%d", &num);

   int sum = 0;
   while(num > 0)
   {
      sum += num % 10;
      num /= 10;
   }
   printf("%s\n", sum == 10 ? "YES" : "NO");

   return 0;
}

