#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <crtdbg.h>// ��� �������� �� ������ ������
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define STOPPROG \
printf("Stop programm\n"); \
_getch();\
return 0

int Sum(int a, int b);
int SumPtr(int* a, int* b);
int findminArr(int count, int* arr);
void func1(); //������� ��������� ����� ������ ��� ������ � �������
void func2(); //��������� ������ ��� ������ ���������� �� ������ � ����� ��������� ������ ��� ���� ������

int main() {

	//...................�������� � ���������
	int a = 10, b = 30;
	int var = 20;
	int* pvar = &var; // pointer
	int** ppvar = NULL; 
	ppvar = &pvar; // pointer to pointer

	printf("var=%d\n", sizeof(pvar)); //������ ��������� (���������� �� ����������� ��, �.�. ��� �����)

	printf("var=%d\n", var);
	printf("&var = %d\n", &var);
	printf("pvar = %d\n", pvar);
	printf("*pvar = %d\n", *pvar);
	printf("&pvar = %d\n", &pvar);
	printf("ppvar = %d\n", ppvar);
	printf("*ppvar = %d\n", *ppvar);
	printf("**ppvar = %d\n", **ppvar);
	printf("&ppvar = %d\n\n", &ppvar);


	//........................��������� �������� ���������� �� ���������
	printf("var=%d\n", var);
	var = 30;
	printf("var=%d\n", var);
	*pvar = 40;
	printf("var=%d\n", var);
	**ppvar = 50;
	printf("var=%d\n\n", var);

	//..........................const ���������� � ���������
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
	
	//...........................������� � ���������
	int mass[5] = { 1,2,3,4,5 };
	int var2 = *mass;
	int var1 = *(mass + 1);
	int* p = mass;
	p++;
	printf("p=%p\t*p++=%d\n", p, *p);
	p = p + 2;
	printf("p+2=%p\t*p=%d\n", p, *p);

	short massS[] = { 10, 17, 18, 31, 80 };
	//massS++;//������, ����� �������� ������ �������
	short* pS = massS;
	pS++; //��������� �������� ������� �� ���������
	printf("p=%p\t*p++=%hi\n", pS, *pS);
	pS += 2;
	printf("p+2=%p\t*p=%hi\n", pS, *pS);

	for (int i = 0; i < ARRAY_SIZE(massS); i++)
		*(massS + i) = *(massS + i) * 10; //��������� �������� ������� �� ����� ��� �������, ������� �������� ���������� �� ������� �������
	for (int i = 0; i < ARRAY_SIZE(massS); i++)
		printf("massS[%d]=%hi ", i, *(massS + i));

	//.............................void ���������
	// void myvar; //������, ������ ������������ ���������� ���� void
	void* pvar1 = NULL;
	int varForVoid = 20;
	int* pvarForVoid = &varForVoid;
	pvar1 = pvarForVoid;
	
	int testvoid = 6000;
	void* ptestvoid = &testvoid;
	printf("int* (ptest)=%d\n", *((int*)ptestvoid)); //������� ��� 4 ����� ���� testvoid = 6000, �� ��� 70 17 00 00, ������� �������� ��� � (int*), ����� �������������� ����� *
	printf("char* (ptest)=%d\n", *((char*)ptestvoid));//������� ������ ����, ��� 70hex ��� 112int, ������� �������� ��� � (char*), ����� �������������� ����� *

	//...............................�������� ���������� � �������
	int a1 = 10;
	int b1 = 20;
	int res = 0;

	int a11 = 50;
	int b11 = 30;
	int res1 = 0;

	res = Sum(a1, b1); //�������� ����� ��������
	res1 = SumPtr(&a11, &b11);// �������� ������	
	printf("a1=%d b1=%d res=%d\n", a1, b1, res);
	printf("a11=%d b11=%d res1=%d\n", a11, b11, res1);

	int massForSearh[] = {10, 15, -3, 10, -5, 50, 0, 1};
	printf("Min in Array is %d \n", findminArr(ARRAY_SIZE(massForSearh), massForSearh));

	//................................������������ ��������� ������
	//int mas[1000000]; //������, stackoverflow, �� ���������� �������� ~4MB �� �����
	int* pMass = (int*)malloc(4 * sizeof(int)); // ������ ��� 4 ��������� �������
	int sizeMass = 4;
	pMass[0] = 10;
	*(pMass+1) = 15;
	*(pMass + 2) = 150;
	int res11 = ARRAY_SIZE(pMass); //������ ������������, �.�. �������� ��� ������ ����������� �������� 8 (x64) / 4 (int)
	for (int i = 0; i < sizeMass; i++)
		printf("pMass[%i] = %i ", i, *(pMass + i));
	free(pMass); //������������ ������
	
	unsigned int count = 0;
	printf("\nInput number of elements for int array ");
	scanf("%d", &count);
	double* myArrBig = NULL;
	printf("\nPress any key to alocate ");
	_getch();
	myArrBig = (double*)malloc(count * sizeof(double)); //�������� ������ � heap
	if (myArrBig == NULL) {
		printf("Can't allocated");
		STOPPROG;
	}
	printf("\nPress any key to free ");
	_getch();
	free(myArrBig);


	//func1();
	//func2();

	_CrtDumpMemoryLeaks();//�������� �� ������ ������
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

void func1() //������ ������ ��������� ������ ��� ��������� ������
{
	int* a; // ��������� �� ������
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("������� ���������� �����: ");
	scanf("%d", &n);
	printf("������� ���������� ��������: ");
	scanf("%d", &m);
	// ��������� ������
	a = (int*)malloc(n * m * sizeof(int)); //����� ���������� ������ ��� ����� �������
	// ���� ��������� �������
	for (i = 0; i < n; i++) // ���� �� �������
	{
		for (j = 0; j < m; j++) // ���� �� ��������
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", (a + i * m + j)); //����������� �� �������
		}
	}
	// ����� ��������� �������
	for (i = 0; i < n; i++) // ���� �� �������
	{
		for (j = 0; j < m; j++) // ���� �� ��������
		{
			printf("%5d ", *(a + i * m + j)); // 5 ��������� ��� ������� �������
		}
		printf("\n");
	}
	printf("\nPress any key to free ");
	_getch();
	free(a);
}

void func2() //������ ������ ��������� ������ ��� ��������� ������, ����� ���������� � ����� ������ ���������
{
	int** a; // ��������� �� ���������
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("������� ���������� �����: ");
	scanf("%d", &n);
	printf("������� ���������� ��������: ");
	scanf("%d", &m);
	// ��������� ������ ��� ��������� �� ������
	a = (int**)malloc(n * sizeof(int*));
	// ���� ��������� �������
	for (i = 0; i < n; i++) // ���� �� �������
	{
		// ��������� ������ ��� �������� �����
		a[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++) // ���� �� ��������
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	// ����� ��������� �������
	for (i = 0; i < n; i++) // ���� �� �������
	{
		for (j = 0; j < m; j++) // ���� �� ��������
		{
			printf("%5d ", a[i][j]); // 5 ��������� ��� ������� �������
		}
		printf("\n");
		free(a[i]); // ������������ ������ ��� ������
	}
	printf("\nPress any key to free ");
	free(a);
	return 0;
}