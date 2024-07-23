/*
 * HW05.task10; Решение задачи B10. "Цифры по возрастанию"
 * Ввести целое число и определить, верно ли, что все его цифры распо-
 * ложены в порядке возрастания.
 * Формат входных данных:
 *       Целое число
 * Формат результата:
 *       Единственное слово: YES или NO
 */

#include <stdio.h>

/*Данная функция сравнивает цифры полученного числа от младшего разряда
к старшему*/
int compareNum (int number)
{
   int a, count = 0;
   while (number != 0)
   {
      a = number % 10;
      number /= 10;
      if (a <= number % 10)
         count++;
   }
   return count;
}

int main(int argc, char **argv)
{
   int num;
   scanf("%d", &num);

   compareNum(num) == 0 ? printf("YES") : printf("NO");

   return 0;
}
