/*
 * HW05.task21; Решение задачи B21. "Заглавные в строчные"
 * Дан текст состоящий из английских букв и цифр, заканчивается символом
 * «.» Перевести все заглавные английские буквы в строчные.
 * Формат входных данных:
 *       Текст из маленьких, больших английских букв и пробелов.
 *       В конце текста символ точка.
 * Формат результата:
 *       Текст из маленьких английских букв.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
   char c = 0;

   while (c != '.')
   {
      c = getchar();

      (c>='A' && c<='Z') ? putchar(c += 32) : (c != '.') ? putchar(c) : putchar('\n');

      //~ if (c>='A' && c<='Z')
      //~ {
         //~ c += 32;
         //~ putchar(c);
      //~ }
      //~ else
      //~ if (c == '.')
         //~ return 0;
      //~ else
         //~ putchar(c);
   }
   return 0;
}
