/*HW04.task11; Решение задачи А19. "Существует ли треугольник"
 * Даны стороны треугольника a, b, c. Определить существует ли такой
 * треугольник.*/
#include <stdio.h>

int main (void)
{
   int a, b, c;

   scanf("%d %d %d", &a, &b, &c);
   if ((a + b) > c && (b + c) > a && (c + a) > b)
   printf("YES");
   else
   printf("NO");
   return 0;
}
