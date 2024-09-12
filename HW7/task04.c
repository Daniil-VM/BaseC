/*Сдать решение задачи D4-В прямом порядке

В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами 
или новыми строками. Необходимо реализовать рекурсивную функцию.
   void print_num(int num)
Формат входных данных
   Одно целое неотрицательное число
Формат результата
   Все цифры числа через пробел в прямом порядке.*/

#include <stdio.h>

// Рекурсивная функция для вывода цифр числа в прямом порядке
void print_num(int num)
{
   // Базовый случай: если число равно 0, ничего не делаем
   if (num == 0)
   {
      return;
   }
    
   // Рекурсивный вызов для оставшейся части числа
   print_num(num / 10);
    
   // Выводим последнюю цифру числа
   printf("%d ", num % 10);
}

int main()
{
   int N;
    
   // Ввод числа
   scanf("%d", &N);
    
   // Если число равно 0, выводим его сразу
   if (N == 0)
   {
      printf("0\n");
   } else 
   {
      // Вызов рекурсивной функции для вывода цифр в прямом порядке
      print_num(N);
      printf("\n");
   }
    
   return 0;
}