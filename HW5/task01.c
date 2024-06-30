/*HW05.task01; Решение задачи B1. "Квадраты и кубы"
 * Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до
 * этого числа. Число не превосходит 100.*/

#include <stdio.h>

int main(int argc, char **argv)
{
   int i, number, square, cube;

   scanf("%d", &number);
   for (i = 1; i <= number; i++)
   {
      square = i * i;
      cube = i * i * i;
      printf("%d %d %d\n", i, square, cube);
   }
   return 0;
}
