#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define NUM_STRINGS 3   // Количество строк
#define MAX_LENGTH 100  // Максимальная длина каждой строки
#define FILENAME "output.txt"
#define ARRSIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define STOPPROG \
printf("\n\nStop prog\nPress any key..."); \
_getch();\
return 0

void printASKII();
void flushBuff();//очистка буффера
int countSymb(char symb, char str[], int* lenstr);//подсчет количества нужного символа
void printArgMain(int argc, char* argv[]); //печать параметров из функции main
void DynStrArrAndWriteInFile(); //динамические строки
char* readFromFile(const char* filename); //чтение из файла
void writeToFile(const char* filename, const char* str); //запись в файл


int main(int argc, char* argv[]) {
  SetConsoleCP(1251); // intput type
  SetConsoleOutputCP(1251); //output type

  char ch[] = { 'a', 'b', 'c' };
  printf("%c ", *ch);
  printf("%c ", *(ch + 1));
  printf("%c ", *(ch + 2));
  printf("\n");
    
  char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // Явное задание символов и null-терминатора    
  char str2[] = "Hello"; // Использование строкового литерала (null-терминатор добавляется автоматически)
  char* str3 = "World"; // Указатель на строковый литерал (нельзя изменять содержимое)
  printf("str1 %s\n", str1);
  printf("str2 %s\n", str2);
  printf("str3 %s\n", str3);
  printf("str1 %c\n", *str1); //вывод первого символа str1
  str2[0] = 'W';
  *(str2 + 1) = 'g';
  printf("str2 %c %c\n", str1[0], str2[1]);
  printf("str3 %c\n", *str3); //вывод первого символа str3
  //*str3 = 'R'; //ошибка, был создан указатель на строку, хранящуюся в разделе констант, и её изменение приведёт к неопределённому поведению
  //printf("str3 %c\n", *str3);


  //..................ввод символов
  char c1, c2;
  printf("Input first symbol ");
  scanf(" %c", &c1); // пробел перед %c помогает, чтобы не перескакивало, иначе запишется символ новой строки в следующий scanf
  printf("Input second symbol ");
  scanf(" %c", &c2);
  printf("(char)c1=%c (char)c2=%c (int)c1=%i (int)c2=%i\n", c1, c2, c1, c2);
  flushBuff();//очистка буффера, ожидание нажатия enter

  //.......................введение в строки
  char testArr1[5];
  printf("Введите строку размером не больше %d\n", (int)(ARRSIZE(testArr1) - 1));
  gets(testArr1);//если ввести больше символов, то будет ошибка, максимум sizeof(arr) - 1, т.к. последний символ '\0' - признак конца строки
  printf("%s\n", testArr1);
  
  printf("Введите строку размером не больше %d\n", (int)ARRSIZE(testArr1) - 1);
  fgets(testArr1, sizeof(testArr1), stdin);//проверка длины строки, если ввести больше, то все будет ok
  printf("%s\n", testArr1);
  
  //fflush(stdin); //нестандартное решение для очистки потока ввода и невсегда работает
  flushBuff(); //очистка буффера ввода через \n
  printf("Введите строку размером не больше %d\n", (int)ARRSIZE(testArr1) - 1);
  gets_s(testArr1, (ARRSIZE(testArr1) - 1));
  printf("%s\n", testArr1);
  printf("1-%c, 2-%c \n", testArr1[0], testArr1[1]);

  char mas[] = { "hello" }; // символ конца строки
  printf("strlen mas=%d\n", strlen(mas)); //5
  printf("sizeof(mas)=% d\n", sizeof(mas));//6
 
  printf("Введите символ для  поиска его кол-ва в строке \"%s\" ", mas);
  char sym;
  int lens = 0;
  scanf(" %c", &sym);
  printf("Количество символов %d, размер массива %d\n", countSymb(sym, mas, &lens), lens);

  char src[] = "Привет";
  char dest[20];
  strcpy(dest, src); // Копируем строку
  printf("Копия: %s\n", dest);

  char str4[20] = "Hello ";
  char str5[] = "World!";
  strcat(str4, str5); // Добавляем str5 в конец str4
  printf("%s\n", str4);

  ///.................................массив строк
  char* name[] = { "Vanv", "test" };
  char* first = "test";
  char* second = "tast";

  if (strcmp(first, second) == 0)//стравнение двух строк
    printf("hello\n");

  char* str[] = { "Hello","My", "New" };//массив строк
  printf("%s ", *str);//вывод первого массива
  printf("%s ", *(str + 1));//вывод второго массива
  printf("%s ", *(str + 2));//вывод третьего массива

  printf("\n\n");
  printf("%c ", **str);//вывод первого символа первого массива
  printf("%c ", **(str + 1));//вывод первого символа второго массива
  printf("%c ", **(str + 2));//вывод первого символа третьего массива

  printf("\n\n"); //вывод H e l l o
  printf("%c ", **str);
  printf("%c ", *(*str + 1));
  printf("%c ", *(*str + 2));
  printf("%c ", *(*str + 3));
  printf("%c ", *(*str + 4));

  DynStrArrAndWriteInFile();

  printArgMain(argc, argv);//печать аргументов main()

  STOPPROG;
}

void flushBuff() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);// Очистка входного буфера
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

int countSymb(char symb, char str[], int* lenstr)
{
  int i = 0;
  int count = 0;
  while (str[i] != '\0')
  {
    if (str[i] == symb)
      count++;
    i++;
  }
  *lenstr = i;
  return count;
}

void DynStrArrAndWriteInFile() {
  
  // Выделяем память для массива указателей на строки
  char** strings = (char**)malloc(NUM_STRINGS * sizeof(char*));
  if (strings == NULL) {
    printf("Ошибка выделения памяти\n");
    return;
  }
  // Выделяем память для каждой строки
  for (int i = 0; i < NUM_STRINGS; i++) {
    strings[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
    if (strings[i] == NULL) {
      printf("Ошибка выделения памяти для строки %d\n", i);
      return;
    }
  }
  // Ввод строк
  printf("Введите три строки:\n");
  for (int i = 0; i < NUM_STRINGS; i++) {
    printf("Строка %d: ", i + 1);
    fgets(strings[i], MAX_LENGTH, stdin);
    strings[i][strcspn(strings[i], "\n")] = '\0'; // Удаляем символ новой строки
  }

  // Вывод строк
  printf("\nВы ввели:\n");
  for (int i = 0; i < NUM_STRINGS; i++) {
    printf("%s\n", strings[i]);
  }

  // Запись первой строки в файл
  writeToFile(FILENAME, strings[0]);
  printf("Строка записана в файл: %s\n", strings[0]);

  // Чтение строки из файла
  char* fileContent = readFromFile(FILENAME);
  if (fileContent != NULL) {
    printf("Прочитанная строка из файла: %s\n", fileContent);
    free(fileContent);
  }

  // Освобождение памяти
  for (int i = 0; i < NUM_STRINGS; i++) {
    free(strings[i]);
  }
  free(strings);
}

char* readFromFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Ошибка открытия файла для чтения\n");
    return NULL;
  }

  char* buffer = (char*)malloc(MAX_LENGTH * sizeof(char));
  if (buffer == NULL) {
    printf("Ошибка выделения памяти\n");
    fclose(file);
    return NULL;
  }

  if (fgets(buffer, MAX_LENGTH, file) == NULL) {
    free(buffer);
    fclose(file);
    return NULL;
  }

  fclose(file);
  return buffer;
}

void writeToFile(const char* filename, const char* str) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("Ошибка открытия файла для записи\n");
    return;
  }
  fprintf(file, "%s", str);
  fclose(file);
}

void printArgMain(int argc, char* argv[]) {
  if (argc < 1)
  {
    printf("No arguments");
  }
  else
  {
    for (int i = 0; i < argc; i++)
    {
      printf("\nArg number %d is %s", i, argv[i]); 
      if (strcmp(argv[i], "param1") == 0)
        printf(" Str %i is same", i);
    }
  }
}
