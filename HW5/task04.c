/*HW05.task04; Решение задачи B4. "Ровно три цифры"
 * Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.*/

#include <stdio.h>

int main(int argc, char **argv)
{
   unsigned int a, b, number;
   a = 99;
   b = 1000;

   scanf("%d", &number);
   if (a < number && number < b)
   {
      printf("YES");
   }
   else
      printf("NO");
   return 0;
}
