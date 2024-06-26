/*HW04.task07; Решение задачи А15. "Уравнение прямой"
 * Определить уравнение прямой по координатам двух точек.
 * Уравнение вида y=k*x+b.*/
#include <stdio.h>

int main (void)
{
   float X1, Y1, X2, Y2, K, B;

   scanf("%f %f %f %f", &X1, &Y1, &X2, &Y2);
   K = (Y1-Y2)/(X1-X2);
   B = Y2 - K*X2;
   printf("%.2f %.2f", K, B);
   return 0;
}
