/*Сдать решение задачи D1-От 1 до N

От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N
Формат входных данных
   Одно натуральное число
Формат результата
   Последовательность чисел от 1 до введенного числа*/

#include <stdio.h>

void increase(unsigned int n)
{
    if (n > 0)
    {
        increase (n-1);
        printf("%u ", n);
    }
}

int main(int argc, char **argv)
{
    unsigned int num = 0;
    scanf("%u", &num);
    increase(num);
    return 0;
}
