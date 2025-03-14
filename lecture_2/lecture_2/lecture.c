#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() {
  int a1 = 0;
  int a2 = 0;

  printf("Input a1 = ");
  scanf("%d", &a1);
  printf("Input a2 = ");
  scanf("%d", &a2);

  //попробовать разные варианты значений переменных, чтобы сработали все условия
  if (a1 > a2)
  {
    printf("a1=%d > a2=%d \n", a1, a2);
  }
  else if (a1 == a2 || a1 == 5) // сработает, даже если a1!=a2, но a1=5
    printf("a1 = a2 \n");
  else
    printf("a1<a2 \n");

  //терная операция
  a1 > a2 ? a1 + 1 : printf("a1<=a2\n"); //если a1 > a2, то a1 + 1, иначе printf("a1<=a2\n")

  //терная операция в тернарной операции
  a1 > a2 ? printf("a1>a2\n") : (a1 < a2 ? printf("a1<a2\n") : printf("a1 == a2\n"));

  //циклы
  int i = 15;
  while (i < 5) //цикл не выполнится, т.к. i=15
  {
    printf("Hello world\n");
    i++; //если не указать i++, будет бесконечный цикл
  }

  i = 10;
  do {
    printf("Hello world -%d\n", i); //выведется один раз, т.к. do while сначала выполняет, а потом проверяет условие
    i++;
  } while (i < 5);


  for (int j = 0; j < 5; j++)//область видимости j только внутри цикла
  {
    printf("Hello World - %d \n", j);
  }

  for (int j = 0, s = 10; j < 5, s > 3; j++, s = s - 2)//несколько условий в цикле
  {
    printf("Hello World - j=%d s=%d\n", j, s);
  }

  int k = 0;
  printf("Input k for switch-case: ");
  scanf("%d", &k);
  switch (k) //может быть целочисленный
  {
  case 1: printf("k=%i\n", k); break;
  case 2:
    k = k + 10;
    printf("k=%i\n", k);
    break;
  case 3: printf("This one if k=3 ");
  case 4: printf("And this one if k=4 because without brake\n"); break;
  default: printf("Nothing of your number in cases\n");
  }

  //распечатка символов на экран
  for (int j = 0; j < 5; j++)
  {
    printf("Press any key: ");
    int key = _getch();
    printf("Your (int)key is %d, char(key) is '%c', there are %d attempts left\n", key, key, 4 - j);
  }

  short flag = 1;
  while (flag) //бесконечный цикл
  {
    printf("\nInput Key, Q or q for exit: ");
    int key = _getch();   // Прочитать клавишу.
    printf("%c", key);
    switch (key)
    {                    // Определение команды...
    case 'f':
    case 'F':
      printf("\n\"File\" command selected.\n");
      printf("i*10 = %d", i * 10);
      break;
    case 'm':
    case 'M':
      //int f; //нельзя создавать переменные в case
      printf("\n\"Message\" command selected.\n");
      break;
    case 'q':
    case 'Q':
      printf("\n\"Quit\" command selected.\n");
      printf("\nPress a key to Exit...\n");
      _getch();
      flag = 0;
      break;
      //return 0;                      // Возврат в Windows,
    default:
      printf("\nlnvalid command!\n");
    }
  }
  
  
  
  //одномерные массивы
  float arrF[10]; //массив на 10 элементов float
  //int K = 10;
  //int arrI[K]; //ошибка, т.к. нужно заранее знать количество памяти на стеке, с C99 и выше можно использовать const int K
  arrF[0] = 5.3;
  //arrF[10] = 10.1; //ошибка, т.к. счет идет с нуля
  
  int arr1[] = { 100,31,4,52,26, 18, 91 }; //объявление 

  for (int j = 0; j < 5; j++)
  {
    arr1[j] = arr1[j] * 10; //изменение значений переменной
  }

  for (int j = 0; j < 5; j++) //вывод массива на экран
  {
    printf("arr1[%d] = %d\n", j, arr1[j]);
  }

  int min = arr1[0];
  int indexMin = 0;
  for (int j = 1; j < 5; j++) //поиск минимального элемента в массиве
  {
    if (arr1[j] < min) {
      min = arr1[j];
      indexMin = j;
    }
  }
  printf("Min in arr1 is %d on index %d\n", min, indexMin);

  //многомерные массивы
  int arr2[3][4];
  for (int i = 0; i < 3; i++)
  {
    printf("\n");
    for (int j = 0; j < 4; j++) {
      arr2[i][j] = i + j;
      printf("%d", arr2[i][j]);
    }
  }
  printf("\n");

  
  int matrix[5][5] = {// Задаем двумерный массив 5x5
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25}
  };

  int sum = 0;  
  for (int i = 0; i < 5; i++) {// Подсчет суммы элементов по главной диагонали
    sum += matrix[i][i];
  }
  printf("Sum of elements along the main diagonal: %d\n", sum);
    
  srand(time(NULL)); // Инициализация генератора случайных чисел
  int array[5][3][4];// Объявляем трехмерный массив 5x3x4

  for (int i = 0; i < 5; i++) { // Заполняем массив случайными числами от 0 до 9
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        array[i][j][k] = ((int)rand() % 10); // случайное число от 0 до 9
      }
    }
  }
    
  int target;
  printf("\nInput float number for search from 0 to 9: ");
  scanf("%d", &target); // Ввод пользователем числа для поиска

  int countNumInArr = 0;
  for (int i = 0; i < 5; i++) { // Поиск количества элементов, равных введенному числу
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        if (array[i][j][k] == target) {
          countNumInArr++;
        }
      }
    }
  }
  
  printf("\nArray:\n"); // Вывод массива
  for (int i = 0; i < 5; i++) {
    printf("Layer %d:\n", i + 1);
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        printf("%d\t", array[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  printf("Sum elements of numbers equal %d: %d\n", target, countNumInArr);

  // binary search
  int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 }; //массив должен быть отсортирован
  int find;
  printf("\nInput number for search: ");
  scanf("%d", &find);
  int low = 0;
  int hight = sizeof(arr) / sizeof(int);
  int mid = 0;
  int count = 0;
  while (low <= hight)
  {
    //mid = (hight + low) / 2;
    mid = low + (hight - low) / 2; //защита от переполнения
    if (arr[mid] == find)
    {
      printf("Your item in arr[%d]=%d", mid, arr[mid]);
      break;
    }
    if (arr[mid] > find)
      hight = mid - 1; //смещаемся влево
    else
      low = mid + 1; //смещаемся вправо
    count++;
  }

  if (low > hight)
    printf("\nNo element");

  printf("\ncount=%d\n", count);

  _getch();


  return 0;
}