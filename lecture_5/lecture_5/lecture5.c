#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define NUM_STRINGS 3   // ���������� �����
#define MAX_LENGTH 100  // ������������ ����� ������ ������
#define FILENAME "output.txt"
#define ARRSIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define STOPPROG \
printf("\n\nStop prog\nPress any key..."); \
_getch();\
return 0

void printASKII();
void flushBuff();//������� �������
int countSymb(char symb, char str[], int* lenstr);//������� ���������� ������� �������
void printArgMain(int argc, char* argv[]); //������ ���������� �� ������� main
void DynStrArrAndWriteInFile(); //������������ ������
char* readFromFile(const char* filename); //������ �� �����
void writeToFile(const char* filename, const char* str); //������ � ����


int main(int argc, char* argv[]) {
  SetConsoleCP(1251); // intput type
  SetConsoleOutputCP(1251); //output type

  char ch[] = { 'a', 'b', 'c' };
  printf("%c ", *ch);
  printf("%c ", *(ch + 1));
  printf("%c ", *(ch + 2));
  printf("\n");
    
  char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // ����� ������� �������� � null-�����������    
  char str2[] = "Hello"; // ������������� ���������� �������� (null-���������� ����������� �������������)
  char* str3 = "World"; // ��������� �� ��������� ������� (������ �������� ����������)
  printf("str1 %s\n", str1);
  printf("str2 %s\n", str2);
  printf("str3 %s\n", str3);
  printf("str1 %c\n", *str1); //����� ������� ������� str1
  str2[0] = 'W';
  *(str2 + 1) = 'g';
  printf("str2 %c %c\n", str1[0], str2[1]);
  printf("str3 %c\n", *str3); //����� ������� ������� str3
  //*str3 = 'R'; //������, ��� ������ ��������� �� ������, ���������� � ������� ��������, � � ��������� ������� � �������������� ���������
  //printf("str3 %c\n", *str3);


  //..................���� ��������
  char c1, c2;
  printf("Input first symbol ");
  scanf(" %c", &c1); // ������ ����� %c ��������, ����� �� �������������, ����� ��������� ������ ����� ������ � ��������� scanf
  printf("Input second symbol ");
  scanf(" %c", &c2);
  printf("(char)c1=%c (char)c2=%c (int)c1=%i (int)c2=%i\n", c1, c2, c1, c2);
  flushBuff();//������� �������, �������� ������� enter

  //.......................�������� � ������
  char testArr1[5];
  printf("������� ������ �������� �� ������ %d\n", (int)(ARRSIZE(testArr1) - 1));
  gets(testArr1);//���� ������ ������ ��������, �� ����� ������, �������� sizeof(arr) - 1, �.�. ��������� ������ '\0' - ������� ����� ������
  printf("%s\n", testArr1);
  
  printf("������� ������ �������� �� ������ %d\n", (int)ARRSIZE(testArr1) - 1);
  fgets(testArr1, sizeof(testArr1), stdin);//�������� ����� ������, ���� ������ ������, �� ��� ����� ok
  printf("%s\n", testArr1);
  
  //fflush(stdin); //������������� ������� ��� ������� ������ ����� � �������� ��������
  flushBuff(); //������� ������� ����� ����� \n
  printf("������� ������ �������� �� ������ %d\n", (int)ARRSIZE(testArr1) - 1);
  gets_s(testArr1, (ARRSIZE(testArr1) - 1));
  printf("%s\n", testArr1);
  printf("1-%c, 2-%c \n", testArr1[0], testArr1[1]);

  char mas[] = { "hello" }; // ������ ����� ������
  printf("strlen mas=%d\n", strlen(mas)); //5
  printf("sizeof(mas)=% d\n", sizeof(mas));//6
 
  printf("������� ������ ��� ������ ��� ���-�� � ������ \"%s\" ", mas);
  char sym;
  int lens = 0;
  scanf(" %c", &sym);
  printf("���������� �������� %d, ������ ������� %d\n", countSymb(sym, mas, &lens), lens);

  char src[] = "������";
  char dest[20];
  strcpy(dest, src); // �������� ������
  printf("�����: %s\n", dest);

  char str4[20] = "Hello ";
  char str5[] = "World!";
  strcat(str4, str5); // ��������� str5 � ����� str4
  printf("%s\n", str4);

  ///.................................������ �����
  char* name[] = { "Vanv", "test" };
  char* first = "test";
  char* second = "tast";

  if (strcmp(first, second) == 0)//���������� ���� �����
    printf("hello\n");

  char* str[] = { "Hello","My", "New" };//������ �����
  printf("%s ", *str);//����� ������� �������
  printf("%s ", *(str + 1));//����� ������� �������
  printf("%s ", *(str + 2));//����� �������� �������

  printf("\n\n");
  printf("%c ", **str);//����� ������� ������� ������� �������
  printf("%c ", **(str + 1));//����� ������� ������� ������� �������
  printf("%c ", **(str + 2));//����� ������� ������� �������� �������

  printf("\n\n"); //����� H e l l o
  printf("%c ", **str);
  printf("%c ", *(*str + 1));
  printf("%c ", *(*str + 2));
  printf("%c ", *(*str + 3));
  printf("%c ", *(*str + 4));

  DynStrArrAndWriteInFile();

  printArgMain(argc, argv);//������ ���������� main()

  STOPPROG;
}

void flushBuff() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);// ������� �������� ������
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
  
  // �������� ������ ��� ������� ���������� �� ������
  char** strings = (char**)malloc(NUM_STRINGS * sizeof(char*));
  if (strings == NULL) {
    printf("������ ��������� ������\n");
    return;
  }
  // �������� ������ ��� ������ ������
  for (int i = 0; i < NUM_STRINGS; i++) {
    strings[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
    if (strings[i] == NULL) {
      printf("������ ��������� ������ ��� ������ %d\n", i);
      return;
    }
  }
  // ���� �����
  printf("������� ��� ������:\n");
  for (int i = 0; i < NUM_STRINGS; i++) {
    printf("������ %d: ", i + 1);
    fgets(strings[i], MAX_LENGTH, stdin);
    strings[i][strcspn(strings[i], "\n")] = '\0'; // ������� ������ ����� ������
  }

  // ����� �����
  printf("\n�� �����:\n");
  for (int i = 0; i < NUM_STRINGS; i++) {
    printf("%s\n", strings[i]);
  }

  // ������ ������ ������ � ����
  writeToFile(FILENAME, strings[0]);
  printf("������ �������� � ����: %s\n", strings[0]);

  // ������ ������ �� �����
  char* fileContent = readFromFile(FILENAME);
  if (fileContent != NULL) {
    printf("����������� ������ �� �����: %s\n", fileContent);
    free(fileContent);
  }

  // ������������ ������
  for (int i = 0; i < NUM_STRINGS; i++) {
    free(strings[i]);
  }
  free(strings);
}

char* readFromFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("������ �������� ����� ��� ������\n");
    return NULL;
  }

  char* buffer = (char*)malloc(MAX_LENGTH * sizeof(char));
  if (buffer == NULL) {
    printf("������ ��������� ������\n");
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
    printf("������ �������� ����� ��� ������\n");
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
