#include <stdio.h>

int main(void)
{
   int A=0, x1=0, x2=0, x3=0;

   scanf("%d", &A); // На входе трехзначное положительное число

   x1 = A/100;
   x2 = (A/10)%10;
   x3 = (A%100)%10;

   printf("%d\n", A=x1+x2+x3);

   return 0;
}
