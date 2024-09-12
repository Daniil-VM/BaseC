/*Сдать решение задачи F1-Сортировка по возрастанию

Сортировка по взрастанию
Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.
Формат входных данных
   Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
Формат результата
   Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.*/

#include <stdio.h>

// Прототип функции
void sort_array(int size, int a[]);

// Реализация функции
void sort_array(int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // Обмен элементов
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Пример использования функции
/*int main()
{
   int array[] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0};
   int size = sizeof(array) / sizeof(array[0]);

   sort_array(size, array);

   for (int i = 0; i < size; i++)
   {
      printf("%d ", array[i]);
   }
   printf("\n");

   return 0;
}*/