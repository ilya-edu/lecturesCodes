#pragma once // ���������, ����� �� ���� ��������� �����������
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> 
//#pragma pack(1) //�� ���������� �� 1 �����, �� ����� ����� ���������

typedef long double myType; // �������� ������������ ����

typedef enum _figures { //������������� ���
  none = 6, // ���� �� ������ ��������, �� �� ��������� � 0, ��� ��������� +1
  rect,
  cyrcle
} Figures;

//32 �����
typedef struct _mydata
{
  char c_char; //1 ����, �� ��� +3 ����� ������������
  int a_int; // 4 �����
  double v_double; //8 ����
  char mass[10]; //10 ����, �� ��� +2 ����� ������������
} MyData;

typedef struct _mydataSize
{
  char mass[10];
  char c_char;  
  int a_int;  
  double v_double;    
} MyDataSize;

struct _mydataWithoutTypedef
{
  char a;
  int b;
};

typedef union _dataun { //���� union �������� � ����� � ��� �� ������� ������
  int i;
  float f;
  char str[20];
} myUnion;

typedef struct _rectangle {
  Figures kind;
  int x;
  int y;
} Rect;

typedef struct _cyrle {
  Figures kind;
  int radius;
} Cyrcle;


int Sum(int a, int b);
Rect* CreateRect();
Cyrcle* CreateCyrcle();