/*HW06.task03; Решение задачи C3. "Среднее арифметическое"
 * Написать функцию, которая возвращает среднее арифметическое двух
 * переданных ей аргументов (параметров). int middle(int a, int b)*/

#include <stdio.h>

int middle(int a, int b);

int main(void)
{
   int a, b;

   scanf("%d %d", &a, &b);
   printf("%d", middle(a, b));

   return 0;
}

int middle(int a, int b)
{
   return a = (a + b)/2;
}
