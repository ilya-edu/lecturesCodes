#include "main.h" // ���������� ����
#include <crtdbg.h> // �������� �� ������ ������

int main(int argc, char* argv[])
{
  //�������� � ���������
  myType myVar; //���������� ����� ����
  MyData myStrtData; //������� ��������� ���������
  myStrtData.a_int = 10;
  myStrtData.v_double = 10.13;
  myStrtData.mass[0] = 100;
  struct _mydataWithoutTypedef strWthTpdf; //������� ��������� ���������, ������� ��� �������� ��� typedef
  strWthTpdf.a = 'a';
  MyData myStrtData1; //������ ��������� ���������
  myStrtData1.a_int = 20;
  
  printf("Struct myStrtData a_int=%d v_double=%.2lf mass[0]=%d\n\
          \rStruct strWthTpdf a=%c\n\
          \rStruct myStrtData1 a_int=%d\n", myStrtData.a_int, myStrtData.v_double, myStrtData.mass[0], strWthTpdf.a, myStrtData1.a_int);
  
  MyData myStrtData2 = {'c', 20, 50.3, "Hello"};//�������� � ���������� ���������� ���������
  printf("myStrtData2 = '%c', %d, %.2lf, %s\n", myStrtData2.c_char, myStrtData2.a_int, myStrtData2.v_double, myStrtData2.mass);

  //������ ��������
  printf("sizeof(MyData) = %d\n", sizeof(MyData));//���������� ����, �� ������ �������
  printf("sizeof(MyDataSize) = %d\n", sizeof(MyDataSize));//�.�. ������ ������������������

  //������������ ��� ������
  Figures kind;
  kind = rect;
  printf("kind %d \n", kind);

  //union
  myUnion myUnvar; //������ ������ ���� ��������, ��� ������ ������ ��������, ���������� ���� ������ ������
  myUnvar.i = 10;
  printf("myUnvar i=%d f=%f\n", myUnvar.i, myUnvar.f); //��������� i
  myUnvar.f = 5.3;
  printf("myUnvar i=%d f=%f\n", myUnvar.i, myUnvar.f); //��������� f

  //������������ ��������� ������ ��� ���������
  Rect newRect;
  Rect* pR = CreateRect();
  printf("pR->x=%d \n", pR->x);
  free(pR);

  void* ppAddObj1 = CreateRect();
  void* ppAddObj2 = CreateCyrcle();

  Figures kindStrc = *((Figures*)ppAddObj1); //��������� � �����
  Figures kindStrc1 = ((Rect*)ppAddObj2)->kind; //��������� � �����

  free(ppAddObj1); //������������ ������
  free(ppAddObj2); //������������ ������

  _CrtDumpMemoryLeaks(); //�������� �� ������
  _getch();
  return 0;
}