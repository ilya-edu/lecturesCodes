#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> 

typedef enum  _Figures
{
	none = 0,
	rect = 1,
	triag,
	cyrcle
} Figures;

extern const char* figureNames[]; //объ¤вл¤ем массив без выделени¤ пам¤ти, если будем использовать только в одном файле, static - будет доступен и в других файлах

// 12
typedef struct _rectanngle {
	Figures kind;
	float x;
	float y;
} Rect;

// 16
typedef struct _triangle {
	Figures kind;
	float x;
	float y;
	float z;
} Triangle;

// 8
typedef struct _cyrcle {
	Figures kind;
	float radius;
} Cyrcle;

//структура дл¤ вычислени¤ площади
typedef struct _shape{
	void* strctData; //указатель на данные 
	float (*area)(void*);//указатель на функцию
} Shape;

int myAdd(int a, int b);
int mySub(int a, int b);
Rect* CreateRect();
Cyrcle* CreateCyrcle();
Triangle* CreateTriangle();
void printRectArr(Rect[], int size);
void printRect(Rect r);
void printRectPtr(Rect* r);
void printInsideObj(void** pobj, int ord);
float rectArea(void* data);
float cyrcleArea(void* data);
float triagArea(void* data);

typedef int (*myAddSub)(int, int);
typedef void (*myFoo)(void**, int);