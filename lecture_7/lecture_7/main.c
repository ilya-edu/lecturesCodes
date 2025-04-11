#include "main.h"
#include < string.h >
#include <crtdbg.h>

int main(int argc, char* argv[])
{
  //printf("sizeRect = %zd\n", sizeof(Rect));
  //printf("sizeTrian = %zd\n", sizeof(Triangle));
  //printf("sizeCyrc = %zd\n", sizeof(Cyrcle));

  ////передача структур в функцию
  //Figures kindStrt = rect;
  //Rect myRect = { kindStrt, 10, 20 };
  //printRect(myRect); //передается копия структуры
  //printf("Rect: %d %.2f %.2f\n", myRect.kind, myRect.x, myRect.y);
  //printRectPtr(&myRect); //передается адрес структуры
  //printf("RectPtr: %d %.2f %.2f\n", myRect.kind, myRect.x, myRect.y);

  //Rect arrRects[3] = {
  //  {kindStrt, 10, 20},
  //  {kindStrt, 100, 2000},
  //  {kindStrt, 1000, 2000},
  //};
  //printRectArr(arrRects, 3); //передача массив структур в функцию
  //_getch();
  //указатели на функцию
  myAddSub foo = myAdd;
  printf("10+9 = %d\n", foo(10, 9));//вернет сумму
  foo = mySub;
  printf("10-9 = %d\n", foo(10, 9));//вернет разность

  //работа со структурами
  void* ppAddObj[] = { NULL, NULL, NULL }; //массив указателей
  ppAddObj[0] = CreateRect(); //создаем объъекты структуры и записываем указатели на них в массив
  ppAddObj[1] = CreateCyrcle();
  ppAddObj[2] = CreateTriangle();
  
  ((Triangle*)(ppAddObj[0]))->x = 10.1; //запоняем поля объектов, todo - так плохо, т.к. непонятно, где какой объект находится
  ((Rect*)(ppAddObj[0]))->y = 20.2;
  ((Cyrcle*)(ppAddObj[1]))->radius = 15;
  ((Triangle*)(ppAddObj[2]))->x = 3.0;
  ((Triangle*)(ppAddObj[2]))->y = 4.0;
  ((Triangle*)(ppAddObj[2]))->z = 5.0;
  _getch();
  //myFoo func = printInsideObj;
  int i = 0;
  size_t sizeArr = sizeof(ppAddObj) / sizeof(ppAddObj[0]);
  while (i < sizeArr) //печатаем, что содержат поля объектов
  {
    if (ppAddObj[i] == NULL)
      continue;

    printInsideObj(ppAddObj, i);
    i++;
  }

  free(ppAddObj[0]);
  free(ppAddObj[1]);
  free(ppAddObj[2]);
  _CrtDumpMemoryLeaks();
  _getch();
  return 0;
}