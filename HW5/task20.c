/*
 * HW05.task20; Решение задачи B20. "Простое число"
 * Проверить число на простоту.
 * Формат входных данных:
 *       Натуральное число
 * Формат результата:
 *       Если число является простым напечатать YES, иначе NO
 */


#include <stdio.h>

int main(int argc, char **argv)
{
   int n, i, flag;
   scanf("%d", &n);

   if (n > 1)
   {
      flag = 1;
      for (i = 2; i < n; i++)
      {
         if (n % i == 0)
         {
            flag = 0;
            break;
         }
      }
      printf("%s", flag == 1 ? "YES" : "NO");
   }
   else
      printf("NO");

   return 0;
}

