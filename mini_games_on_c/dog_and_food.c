#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char mas[10][21];
  int i = 0;
  int x = 10, y = 5;
  int ox, oy;
  char key;
  int ay = 5, ax = 3;
  int by = 3, bx = 5;
  int count = 0;
  int flag = 0;
  int flagBad = 0;

  srand(time(NULL));

  do
  {
    printf("\n");
    sprintf(mas[0], "####################");
    for (int i = 1; i < 9; i++)
      sprintf(mas[i], "#                  #");
    sprintf(mas[9], "####################");

    mas[y][x] = '@';
    mas[ay][ax] = '*';
    mas[by][bx] = '&';
    system("cls");
    for (int i = 0; i < 10; i++)
      printf("%s\n", mas[i]);

    printf("\ncount = %d", count);
    key = getch();

    ox = x;
    oy = y;

    if (key == 'w') y--;
    if (key == 's') y++;
    if (key == 'a') x--;
    if (key == 'd') x++;

    if (mas[y][x] == '#')
    {
      x = ox;
      y = oy;
    }
    if (x == ax && y == ay)
    {
      ax = rand() * 1.0 / RAND_MAX * 18 + 1;
      ay = rand() * 1.0 / RAND_MAX * 8 + 1;
      count++;

      bx = rand() * 1.0 / RAND_MAX * 18 + 1;
      by = rand() * 1.0 / RAND_MAX * 8 + 1;
    }

    if (x == bx && y == by)
    {
      flagBad = 1;
      break;
    }

    if (count == 5)
      flag = 1;
  } while (key != 'q' && flag != 1);

  if (flagBad == 1) // если попали на &
  {
    system("cls");
    printf("  ___   ___  ___  ___  ____      ___   __ __  ____ ____\n");
    printf(" // \\\\ // \\\\ ||\\\\//|| ||        // \\\\  || || ||    || \\\\\n");
    printf("(( ___ ||=|| || \\/ || ||==     ((   )) \\\\ // ||==  ||_//\n");
    printf(" \\\\_|| || || ||    || ||___     \\\\_//   \\V/  ||___ || \\\\\n");

    printf("\n");
    printf("\ncount = %d\n", count);
    system("pause");
  }

  if (flag == 1) // собрали все *
  {
    // https://patorjk.com/software/taag/#p=display&f=Basic&t=You%20WIN
    system("cls");

    printf("db    db  .d88b.  db    db      db   d8b   db d888888b d8b   db\n");
    printf("`8b  d8' .8P  Y8. 88    88      88   I8I   88   `88'   888o  88\n");
    printf(" `8bd8'  88    88 88    88      88   I8I   88    88    88V8o 88\n");
    printf("   88    88    88 88    88      Y8   I8I   88    88    88 V8o88\n");
    printf("   88    `8b  d8' 88b  d88      `8b d8'8b d8'   .88.   88  V888\n");
    printf("   YP     `Y88P'  ~Y8888P'       `8b8' `8d8'  Y888888P VP   V8P\n");

    printf("\n");
    printf("\ncount = %d\n", count);
    system("pause");
  }

  return 0;
}