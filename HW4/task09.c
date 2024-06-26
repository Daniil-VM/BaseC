/*HW04.task09; Решение задачи А17. "Время года"
 * Ввести номер месяца и вывести название времени года.
 * winter, spring, summer, autumn*/
#include <stdio.h>

int main (void)
{
   int Season;

   scanf("%d", &Season);
   if (Season >= 3 && Season <=5)
      printf("spring");
   if (Season >= 6 && Season <=8)
      printf("summer");
   if (Season >= 9 && Season <=11)
      printf("autumn");
   if (Season >= 12 || Season <=2)
      printf("winter");
   return 0;
}
