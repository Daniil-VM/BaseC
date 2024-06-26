/*HW04.task10; Решение задачи А18. "Above, Less, Equal"
 * Ввести два числа. Если первое число больше второго, то программа пе-
 * чатает слово Above. Если первое число меньше второго, то программа
 * печатает слово Less. А если числа равны, программа напечатает сообще-
 * ние Equal.*/
#include <stdio.h>

int main (void)
{
   int a, b;
   char A[] = "Above", L[] = "Less", E[] = "Equal";

   scanf("%d %d", &a, &b);
   if (a > b)
      printf("%s", A);
   else
   if (a < b)
      printf("%s", L);
   else
      printf("%s", E);
   return 0;
}
