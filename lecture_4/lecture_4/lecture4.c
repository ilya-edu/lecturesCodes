#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <crtdbg.h>// для проверки на утечки памяти
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define STOPPROG \
printf("Stop programm\n"); \
_getch();\
return 0

int Sum(int a, int b);
int SumPtr(int* a, int* b);
int findminArr(int count, int* arr);
void func1(); //функция выделения общей памяти под строки и столбцы
void func2(); //выделение памяти под массив указателей на строки и потом выделение памяти под сами строки

int main() {

	//...................введение в указатели
	int a = 10, b = 30;
	int var = 20;
	int* pvar = &var; // pointer
	int** ppvar = NULL; 
	ppvar = &pvar; // pointer to pointer

	printf("var=%d\n", sizeof(pvar)); //размер указателя (отличается от разрядности ОС, т.к. это адрес)

	printf("var=%d\n", var);
	printf("&var = %d\n", &var);
	printf("pvar = %d\n", pvar);
	printf("*pvar = %d\n", *pvar);
	printf("&pvar = %d\n", &pvar);
	printf("ppvar = %d\n", ppvar);
	printf("*ppvar = %d\n", *ppvar);
	printf("**ppvar = %d\n", **ppvar);
	printf("&ppvar = %d\n\n", &ppvar);


	//........................изменение значение переменной по указателю
	printf("var=%d\n", var);
	var = 30;
	printf("var=%d\n", var);
	*pvar = 40;
	printf("var=%d\n", var);
	**ppvar = 50;
	printf("var=%d\n\n", var);

	//..........................const переменные и указатели
	int test = 20;
	int* const pnew = &test;
	//pnew++; //error
	*pnew = 50; //ok

	const int* pnew1 = &test;
	pnew1++; //ok
	//*pnew1 = 60; //error

	const int* const pnew2 = &test;
	//pnew2++; //ok
	//*pnew2 = 60; //error
	
	//...........................массивы и указатели
	int mass[5] = { 1,2,3,4,5 };
	int var2 = *mass;
	int var1 = *(mass + 1);
	int* p = mass;
	p++;
	printf("p=%p\t*p++=%d\n", p, *p);
	p = p + 2;
	printf("p+2=%p\t*p=%d\n", p, *p);

	short massS[] = { 10, 17, 18, 31, 80 };
	//massS++;//ошибка, можем потерять начало массива
	short* pS = massS;
	pS++; //изменение значений массива по указателю
	printf("p=%p\t*p++=%hi\n", pS, *pS);
	pS += 2;
	printf("p+2=%p\t*p=%hi\n", pS, *pS);

	for (int i = 0; i < ARRAY_SIZE(massS); i++)
		*(massS + i) = *(massS + i) * 10; //изменение значений массива по через имя массива, которое является указателем на нулевой элемент
	for (int i = 0; i < ARRAY_SIZE(massS); i++)
		printf("massS[%d]=%hi ", i, *(massS + i));

	//.............................void указатели
	// void myvar; //ошибка, нельзя использовать переменную типа void
	void* pvar1 = NULL;
	int varForVoid = 20;
	int* pvarForVoid = &varForVoid;
	pvar1 = pvarForVoid;
	
	int testvoid = 6000;
	void* ptestvoid = &testvoid;
	printf("int* (ptest)=%d\n", *((int*)ptestvoid)); //достаем все 4 байта если testvoid = 6000, то это 70 17 00 00, вначале приводим тип к (int*), потом разыменовываем через *
	printf("char* (ptest)=%d\n", *((char*)ptestvoid));//достаем первый байт, это 70hex или 112int, вначале приводим тип к (char*), потом разыменовываем через *

	//...............................передача указателей в функцию
	int a1 = 10;
	int b1 = 20;
	int res = 0;

	int a11 = 50;
	int b11 = 30;
	int res1 = 0;

	res = Sum(a1, b1); //передача копий значений
	res1 = SumPtr(&a11, &b11);// передача адреса	
	printf("a1=%d b1=%d res=%d\n", a1, b1, res);
	printf("a11=%d b11=%d res1=%d\n", a11, b11, res1);

	int massForSearh[] = {10, 15, -3, 10, -5, 50, 0, 1};
	printf("Min in Array is %d \n", findminArr(ARRAY_SIZE(massForSearh), massForSearh));

	//................................динамическое выделение памяти
	//int mas[1000000]; //ошибка, stackoverflow, не получается выделить ~4MB на стеке
	int* pMass = (int*)malloc(4 * sizeof(int)); // память для 4 элементов массива
	int sizeMass = 4;
	pMass[0] = 10;
	*(pMass+1) = 15;
	*(pMass + 2) = 150;
	int res11 = ARRAY_SIZE(pMass); //нельзя пользоваться, т.к. подходит для только статических массивов 8 (x64) / 4 (int)
	for (int i = 0; i < sizeMass; i++)
		printf("pMass[%i] = %i ", i, *(pMass + i));
	free(pMass); //освобождение памяти
	
	unsigned int count = 0;
	printf("\nInput number of elements for int array ");
	scanf("%d", &count);
	double* myArrBig = NULL;
	printf("\nPress any key to alocate ");
	_getch();
	myArrBig = (double*)malloc(count * sizeof(double)); //выделяем память в heap
	if (myArrBig == NULL) {
		printf("Can't allocated");
		STOPPROG;
	}
	printf("\nPress any key to free ");
	_getch();
	free(myArrBig);


	//func1();
	//func2();

	_CrtDumpMemoryLeaks();//проверка на утечки памяти
  _getch();
  return 0;
}

int Sum(int a1, int b1) {
	a1 = a1 + 10;
	return a1 + b1;
}

int SumPtr(int *a1, int *b1) {
	*a1 = *a1 + 10;
	return *a1 + *b1;
}

int findminArr(int count, int* arr)
{
	int min = *arr;
	for (int i = 1; i < count; i++)
	{
		if (*(arr + i) < min)
			min = *(arr + i);
	}
	return min;
}

void func1() //первый способ выделения память под двумерный массив
{
	int* a; // указатель на массив
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("Введите количество строк: ");
	scanf("%d", &n);
	printf("Введите количество столбцов: ");
	scanf("%d", &m);
	// Выделение памяти
	a = (int*)malloc(n * m * sizeof(int)); //сразу выделяется память для всего массива
	// Ввод элементов массива
	for (i = 0; i < n; i++) // цикл по строкам
	{
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", (a + i * m + j)); //перемещение по массиву
		}
	}
	// Вывод элементов массива
	for (i = 0; i < n; i++) // цикл по строкам
	{
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("%5d ", *(a + i * m + j)); // 5 знакомест под элемент массива
		}
		printf("\n");
	}
	printf("\nPress any key to free ");
	_getch();
	free(a);
}

void func2() //второй способ выделения памяти под двумерный массив, более правильный с точки зрения понимания
{
	int** a; // указатель на указатель
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("Введите количество строк: ");
	scanf("%d", &n);
	printf("Введите количество столбцов: ");
	scanf("%d", &m);
	// Выделение памяти под указатели на строки
	a = (int**)malloc(n * sizeof(int*));
	// Ввод элементов массива
	for (i = 0; i < n; i++) // цикл по строкам
	{
		// Выделение памяти под хранение строк
		a[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	// Вывод элементов массива
	for (i = 0; i < n; i++) // цикл по строкам
	{
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
		}
		printf("\n");
		free(a[i]); // освобождение памяти под строку
	}
	printf("\nPress any key to free ");
	free(a);
	return 0;
}