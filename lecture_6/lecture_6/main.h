#pragma once // директива, чтобы не было задвоений подключения
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> 
//#pragma pack(1) //вы равнивание по 1 байту, но может стать медленнее

typedef long double myType; // создание собственного типа

typedef enum _figures { //перечисляемый тип
  none = 6, // если не задать значение, то по умолчанию с 0, все остальные +1
  rect,
  cyrcle
} Figures;

//32 байта
typedef struct _mydata
{
  char c_char; //1 байт, но еще +3 байта выравнивание
  int a_int; // 4 байта
  double v_double; //8 байт
  char mass[10]; //10 байт, но еще +2 байта выравнивание
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

typedef union _dataun { //поля union хранятся в одной и той же области памяти
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