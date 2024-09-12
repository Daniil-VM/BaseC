/*Сдать решение задачи D5-Перевод в двоичную систему

В двоичную систему
Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
Формат входных данных
   Целое не отрицательное число в десятичной системе счисления
Формат результата
   Целое число в двоичной системе счисления*/

#include <stdio.h>

// Рекурсивная функция для перевода числа в двоичную систему
void decimal_to_binary(int num)
{
   // Базовый случай: если число равно 0, ничего не делаем
   if (num == 0)
   {
      return;
   }
    
   // Рекурсивный вызов для оставшейся части числа
   decimal_to_binary(num / 2);
    
   // Выводим остаток от деления на 2 (бит числа)
   printf("%d", num % 2);
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
      // Вызов рекурсивной функции для перевода числа в двоичную систему
      decimal_to_binary(N);
      printf("\n");
   }
    
   return 0;
}
