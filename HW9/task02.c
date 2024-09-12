/*Сдать решение задачи F2-Четные в начало

Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. 
Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
Формат входных данных
   Функцийя принмате на вход целые числа
Формат результата
   Отсортированный исходный массив*/

#include <stdio.h>

// Прототип функции
void sort_even_odd(int n, int a[]);

// Реализация функции
void sort_even_odd(int n, int a[])
{
   int even[n], odd[n];
   int even_count = 0, odd_count = 0;

   // Разделение элементов на четные и нечетные
   for (int i = 0; i < n; i++)
   {
      if (a[i] % 2 == 0)
      {
         even[even_count++] = a[i];
      } else
      {
         odd[odd_count++] = a[i];
      }
   }

   // Объединение четных и нечетных элементов в исходный массив
   for (int i = 0; i < even_count; i++)
   {
      a[i] = even[i];
   }
   for (int i = 0; i < odd_count; i++)
   {
      a[even_count + i] = odd[i];
   }
}

// Пример использования функции
/*
int main()
{
   int array[] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0};
   int size = sizeof(array) / sizeof(array[0]);

   sort_even_odd(size, array);

   for (int i = 0; i < size; i++)
   {
      printf("%d ", array[i]);
   }
   printf("\n");

   return 0;
}
*/