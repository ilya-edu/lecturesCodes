#include "main.h" // собстенный файл
#include <crtdbg.h> // проверка на утечки пам¤ти

int main(int argc, char* argv[])
{
  //введение в структуры
  myType myVar; //переменна¤ новго типа
  MyData myStrtData; //создаем экземпл¤р структуры
  myStrtData.a_int = 10;
  myStrtData.v_double = 10.13;
  myStrtData.mass[0] = 100;
  struct _mydataWithoutTypedef strWthTpdf; //создаем экземпл¤р структуры, который был объ¤влен без typedef
  strWthTpdf.a = 'a';
  MyData myStrtData1; //другой экземпл¤р структуры
  myStrtData1.a_int = 20;
  
  printf("Struct myStrtData a_int=%d v_double=%.2lf mass[0]=%d\n\
          \rStruct strWthTpdf a=%c\n\
          \rStruct myStrtData1 a_int=%d\n", myStrtData.a_int, myStrtData.v_double, myStrtData.mass[0], strWthTpdf.a, myStrtData1.a_int);
  
  MyData myStrtData2 = {'c', 20, 50.3, "Hello"};//создание и заполнение экземпл¤ра структуры
  printf("myStrtData2 = '%c', %d, %.2lf, %s\n", myStrtData2.c_char, myStrtData2.a_int, myStrtData2.v_double, myStrtData2.mass);

  //размер структур
  printf("sizeof(MyData) = %d\n", sizeof(MyData));//одинаковые пол¤, но разные размеры
  printf("sizeof(MyDataSize) = %d\n", sizeof(MyDataSize));//т.к. друга¤ последовательность

  //перечисл¤мый тип данных
  Figures kind;
  kind = rect;
  printf("kind %d \n", kind);

  //union
  myUnion myUnvar; //хранит только одно значение, при записи нового значени¤, предыдущее поле тер¤ет данные
  myUnvar.i = 10;
  printf("myUnvar i=%d f=%f\n", myUnvar.i, myUnvar.f); //выведетс¤ i
  myUnvar.f = 5.3;
  printf("myUnvar i=%d f=%f\n", myUnvar.i, myUnvar.f); //выведетс¤ f

  //динамическое выделение пам¤ти под структуру
  Rect newRect;
  Rect* pR = CreateRect();
  printf("pR->x=%d \n", pR->x);
  free(pR);

  void* ppAddObj1 = CreateRect();
  void* ppAddObj2 = CreateCyrcle();

  Figures kindStrc = *((Figures*)ppAddObj1); //обращение к пол¤м
  Figures kindStrc1 = ((Rect*)ppAddObj2)->kind; //обращение к пол¤м

  free(ppAddObj1); //освобождение пам¤ти
  free(ppAddObj2); //освобождение пам¤ти

  _CrtDumpMemoryLeaks(); //проверка на утечки
  _getch();
  return 0;
}