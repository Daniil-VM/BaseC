/*HW06.task05; Решение задачи C5. "Сумма от 1 до N"
 * Составить функцию, которая определяет сумму всех чисел от 1 до N и 
   привести пример ее использования.
   Формат входных данных
      Одно целое положительное число N
   Формат результата
      Целое число - сумма чисел от 1 до N*/

#include <stdio.h>

int sum(int);

int main(int argc, char **argv)
{
    int N;
    scanf("%d", &N);
    printf("%d\n", sum(N));
    return 0;
}

int sum(int N)
{
    int s = 0;
    for(int i=1; i<=N; i++)
    {
        s += i;
    }
    return (s);
}
