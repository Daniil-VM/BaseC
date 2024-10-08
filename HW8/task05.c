/*Сдать решение задачи E5-Сумма положительных элементов

Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
Формат входных данных
   10 целых чисел через пробел
Формат результата
   Одно целое число - сумма положительных элементов массива*/

#include <stdio.h>

int main()
{
   int array[10];
   int sum = 0;

   // Ввод десяти целых чисел
   for (int i = 0; i < 10; i++)
   {
      scanf("%d", &array[i]);
   }

   // Подсчет суммы положительных элементов
   for (int i = 0; i < 10; i++)
   {
      if (array[i] > 0)
      {
         sum += array[i];
      }
   }

   // Вывод результата
   printf("%d\n", sum);

   return 0;
}
