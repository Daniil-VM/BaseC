#include <stdio.h>

int main(void)
{
   int a=0, b=0, c=0;
   float X=0.00;

   scanf("%d %d %d", &a, &b, &c);
   X = (a+b+c)/3.00;
   printf("%.2f", X);

   return 0;
}
