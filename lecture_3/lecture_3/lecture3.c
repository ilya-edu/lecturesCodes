#define _CRT_SECURE_NO_WARNINGS //for Visual C++
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define PI 3.14159 //объявление собсветнной константы
#define ARAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0])) //макрос для определения размера массива
#define MIN(a,b) ((a) < (b) ? (a) : (b)) //макрос определение минмального числа

int Sum(int a, int b) //пример функции сложения
{
  return a + b;
}

//прототипы функций
void printArr(const int mas[], int sizeArr); // печать массива
void myExit(); // безусловный выход
int testFoo(int i); // со статичесскими переменными
void countOut(int count); //простая рекурсия
int factor(int n); //подсчет факториала числа n
int fibonacci(int n); //подсчет n-го числа Фибоначи

int bubbleSort(int arr[], int n);
int selectionSort(int arr[], int n);
int insertionSort(int arr[], int n);


int main()
{
  // передача переменных в функцию  
  int var1 = 10;
  int var2 = 15;
  int varS = 0;
  int varD = 0;

  varS = Sum(var1, var2);
  varD = var1 - var2;

  printf("Sum = %d\n", varS);
  printf("Sum = %d\n", Sum(var1, var2));
  printf("Div = %d\n", varD);
  printf("var1 = %d\n", var1); // значение не будет меняться, если менять в функции, т.к. передаются копии значений
  printf("var1 = %d var2= %d min=%d\n", var1, var2, MIN(var1, var2)); // определение минимального через макрос

  // статический параметр в функции
  int b = 10;
  int res = 0;
  res = testFoo(b);
  printf("foo=%i   b=%i\n", res, b);
  res = testFoo(b); 
  printf("foo=%i   b=%i\n", res, b);
  res = testFoo(b);
  printf("foo=%i   b=%i\n", res, b);
  printf("\n");

  //arrays in func 
  int arr1[] = { 1,3,6,3,5 };
  int arr2[3];
  for (int i = 0; i < ARAY_SIZE(arr2); i++)
    arr2[i] = 100 * i;
  char arr3[3] = { '1', 'b', 'a' };

  int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]); // size of arr, можно использлвать size_t (всегда неотрицательный), %zu — спецификатор для size_t в printf()
  int sizeArr2 = sizeof(arr2) / sizeof(arr2[0]);
  int sizeArr3 = ARAY_SIZE(arr3); //определение через макрос

  printArr(arr1, sizeArr1);
  printArr(arr2, sizeArr2);
  printArr(arr3, sizeArr3); // нет обобщённых (generic) функций, нужно использовать void, поэтому выведет неправильно

  //printf("\nmas[0] = %d", arr1[0]); //если убрать из параметров функции const, то можно в функции менять значения элементов массива
  //printf("\nmas[0] = %d", arr2[0]);
  //printf("\nmas[0] = %d", arr3[0]);

  printf("\n");

  //рекурсии
  countOut(3); //вывод простой рекурсии

  int factorVar;
  printf("\nInput number for factorial ");
  scanf("%d", &factorVar);

  int factorR = 1;
  for (int i = 1; i <= factorVar; i++)
  {
    factorR = factorR * i;
  }
  printf("%d!=%d", factorVar, factorR);
  printf("\nfunc %d!=%d", factorVar, factor(factorVar));
  printf("\n");
  printf("Fibinachi %d is %d", factorVar, fibonacci(factorVar));
  printf("\n");

  // бинарный поиск
  int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
  int sizeArr = sizeof(arr) / sizeof(int);
  int find;
  printf("\nInput num for search ");
  scanf("%d", &find);
  printf("\nCount of iteration binSearch %d", binSearch(arr, find, sizeArr));
  printf("\n");

  //сортировки
  int arrSort[] = { 4, 7, 5, 8, 1, 3, 6, 2 };
  int original[] = { 4, 7, 5, 8, 1, 3, 6, 2 };
  int sortArr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int n = sizeof(arrSort) / sizeof(arrSort[0]);
  printf("Count of iteration bubblesort %d\n", bubbleSort(arrSort, n));
  printf("Count of good %d\n", bubbleSort(sortArr, n));
  printArr(arrSort, n);
    
  memcpy(arrSort, original, sizeof(arrSort));// Восстанавливаем исходные значения
  printf("Count of iteration selectionSort %d\n", selectionSort(arrSort, n));
  printf("Count of good %d\n", selectionSort(sortArr, n));
  printArr(arrSort, n);

  memcpy(arrSort, original, sizeof(arrSort));// Восстанавливаем исходные значения
  printf("Count of iteration insertionSort %d\n", insertionSort(arrSort, n));
  printf("Count of good %d\n", insertionSort(sortArr, n));
  printArr(arrSort, n);

  _getch();
  return 0;

}

void myExit()
{
  printf("\nPress Any Key ...");
  _getch();
  exit(0);
}

int testFoo(int i)
{
  static int var = 10;
  var = var + i;
  return var;
}

void printArr(const int mas[], int sizeArr) // если без const массив изменится, т.к. раскладывается на указатели
{

  for (int i = 0; i < sizeArr; i++)
  {
    printf("%d ", mas[i]);
  }
  printf("\n");
  //mas[0] = 100; // for const error
}

int binSearch(const int mas[], int find, int sizeArr)
{
  int low = 0;
  int hight = sizeArr;
  int mid = 0;
  int count = 0;
  while (low <= hight)
  {
    count++;
    mid = low + (hight - low) / 2;
    if (mas[mid] == find)
    {
      printf("Your item in arr[%d]=%d\n", mid, mas[mid]);
      break;
    }
    if (mas[mid] > find)
      hight = mid - 1;
    else
      low = mid + 1;
  }

  if (low > hight)
    printf("\nNo element");

  return count;
}

void countOut(int count)
{
  printf("test%d\n", count);
  if (count > 1)
    countOut(count - 1);
  printf("end%d\n", count);
}

int factor(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return factor(n - 1) * n;
}

int fibonacci(int n) {
  if (n <= 0) return 0; // Базовый случай: F(0) = 0
  if (n == 1) return 1; // Базовый случай: F(1) = 1
  return fibonacci(n - 1) + fibonacci(n - 2); // Рекурсивный вызов
}

//xудший и средний случай: O(n²) (при большом n работает медленно), лучший случай (если массив уже отсортирован): O(n), но нужен вариант с флагом
int bubbleSort(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Обмен элементов
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        count++;
      }
    }
  }
  return count;
}

// Лучший, средний и худший случай : O(n²)
int selectionSort(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    count++;
    int minIndex = i; // Предполагаем, что текущий элемент - минимальный
    // Ищем минимальный элемент в оставшейся части массива
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Обмен элементов, если найден меньший
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
  return count;
}

//Лучший случай: O(n) (если массив уже отсортирован). Средний и худший случай : O(n²).
int insertionSort(int arr[], int n) {
  int count = 0;
  for (int i = 1; i < n; i++) {
    int key = arr[i]; // Текущий элемент, который будем вставлять
    int j = i - 1;

    // Сдвигаем элементы, которые больше key, вправо
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
      count++;
    }

    // Вставляем key на правильное место
    arr[j + 1] = key;
  }
  return count;
}

void printASKII()
{
  int s;
  int var = 0;
  int i = 0;

  do {
    printf("\nIf you want to exit please enter Q or q-> ");
    s = _getch();
    printf("\n The symbol is %c, symbols's code is %d\n", s, s);
  } while ((char)s != 'Q' && (char)s != 'q');
}