/*
 * HW05.task06; Решение задачи B6. "Две одинаковые цифры"
 * Ввести целое число и определить, верно ли, что в его записи есть две
 * одинаковые цифры, стоящие рядом.
 * Формат входных данных:
 *       Одно целое число
 * Формат результата:
 *       Единственное слов: YES или NO
 */

#include <stdio.h>


int main(int argc, char **argv)
{
   unsigned long int numb;
   int val1 = 0;
   int val2 = 0;

   scanf("%lu", &numb);
   for (;numb > 0;)
   {
      do
      {
         val1 = numb % 10;
         numb /= 10;
         val2 = numb % 10;
         if (val1 == val2)
         {
            //printf("val1 = %d, val2 = %d\n", val1,val2);
            printf("YES\n");
            goto exit;
         }
      }while  (val1 != val2 && numb > 0);
   }
   printf("NO\n");

exit:
   return 0;
}
