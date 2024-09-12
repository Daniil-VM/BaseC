/*Сдать решение задачи E1-Среднее арифметическое

Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
Формат входных данных
   5 целых не нулевых чисел через пробел
Формат результата
   Олно число в формате "%.3f"*/

#include <stdio.h>

int main()
{
   int array[5];
   int sum = 0;
   float average;

   // Ввод пяти целых чисел
   for (int i = 0; i < 5; i++)
   {
      scanf("%d", &array[i]);
      sum += array[i];
   }

   // Вычисление среднего арифметического
   average = (float)sum / 5;

   // Вывод результата с точностью до трех знаков после запятой
   printf("%.3f\n", average);

   return 0;
}