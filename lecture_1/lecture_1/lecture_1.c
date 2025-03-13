#define _CRT_SECURE_NO_WARNINGS // for scanf VS 2022 Windows
#include <locale.h> // поддержка €зыка, в данном примере дл€ вывода на русском
#include <stdio.h> // стандартный ввод/вывод
#include <conio.h> // в данном примере дл€ _getch()
#include <inttypes.h> //в данном случае дл€ вывода min и max значений в типах данных
#include <windows.h>
#define PI 3.14159 //можно задать константу, которую потом использовать в коде

void printSizeVar(); //output min и max in datatypes

int main() {

  //простой пример
  printf("Hello world\n");
  printf("ѕривет ћир!\n"); // выведетс€ непон€тно  
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251); // intput type
  SetConsoleOutputCP(1251); //output type
  printf("Hello world\n");
  printf("ѕривет ћир!\n\n"); //выведетс€ пон€тно

  //типы данных
  // ÷елочисленные типы
  int i = -10;
  short s = -5;
  long l = -100000L;
  long long ll = -10000000000LL;
  unsigned int ui = 10U;
  unsigned short us = 5U;
  unsigned long ul = 100000UL;
  unsigned long long ull = 10000000000ULL;

  // „исла с плавающей зап€той
  float f = 3.14f;
  double d = 3.1415926535;
  long double ld = 3.141592653589793238L;

  // —имвольный тип
  char c = 'A';
  unsigned char uc = 255;
  signed char sc = -128;

  // ¬ывод значений
  printf("int: %d\n", i);
  printf("short: %hd\n", s);
  printf("long: %ld\n", l);
  printf("long long: %lld\n", ll);
  printf("unsigned int: %u\n", ui);
  printf("unsigned short: %hu\n", us);
  printf("unsigned long: %lu\n", ul);
  printf("unsigned long long: %llu\n", ull);

  printf("float: %f\n", f);
  printf("double: %lf\n", d);
  printf("long double: %Lf\n", ld);

  printf("char: %c\n", c);
  printf("unsigned char: %hhu\n", uc);
  printf("signed char: %hhd\n", sc);

  //переполнение
   signed short s_short = 32767; // max 32767
   printf("ѕереполнение short: %hd\n", s_short); // 32767
   s_short = 32768; 
   printf("ѕереполнение short: %hd\n", s_short); // -32768
   s_short = 32790;
   printf("ѕереполнение short: %hd\n", s_short); // -32746
   unsigned c_char_over = 255;
   printf("ѕереполнение беззнакового char: %hhu\n", c_char_over); // 255
   c_char_over = 261;
   printf("ѕереполнение беззнакового char: %hhu\n", c_char_over); // 5
  
  //приведение типов
  int p;
  double pReal = 2.718281828;
  p = pReal; // p получает значение 2, не€вное
  pReal = p; // pReal теперь равно 2.0  
  int p1;
  double pReal1 = 2.718281828;
  printf("\npReal1=%lf ", pReal1);
  p1 = (int)pReal; // p получает значение 2, €вное
  pReal1 = p1; // pReal теперь равно 2.0
  printf("(int)pReal1=%lf\n\n", pReal1);
  
  //вывод размеров типов данных и min и max значений
  //printSizeVar(); 

  //ввод с клавиатуру и вывод на экран
  int i_int = 0;
  printf("Input i_int= ");
  scanf("%i", &i_int);

  float f_float = 0.0;
  printf("Input f_float= ");
  scanf("%f", &f_float); //важно обращать внимание на системный разделитель, может быть '.' или ','

  double d_double = 0.0;
  printf("Input d_double= ");
  scanf("%lf", &d_double);

  char c_char;
  printf("Input c_char= ");
  scanf(" %c", &c_char); //пробел перед %c проигнорирует enter от прошлого ввода, иначе в c_char запишетс€ '\n'
  printf("i_int=%i, f_float=%f, d_double=%0.1lf, c_char=%c \n", i_int, f_float, d_double, c_char);// 0.1lf - выведетс€ один знак после зап€той
 
  //битовые операции
  int b, b1, b2;
  b = b1 = b2 = 5; //l-value
  b = b + 1; //6
  b1++; //6
  ++b1; //7
  b2 = 1 + ++b1; //b1 = 8, b2  = 9, вначале увеличили b1 на 1, а потом еще прибавили 1
  b2 = 1 + b++ ; // b = 7, b2 = 7, вначале сложили 1 и b, а потом увеличили b на 1
 
  b = 7;
  b = b << 1; // 111 << 1 = 1110 -> 14 ->  7 * (2^1)
  b = b >> 2; // 1110 >> 2 = 0011 -> 3 -> 14/(2^2)
  
  b = 5, b1 = 7;
  b2 = b & b1; //5
  b2 = b | b1; //7

  printf("\nPress any key ...");
  _getch(); //ожидание нажати€ любой клавиши
  return 0;
}

void printSizeVar()
{

  printf("int8_t size is %ld\n", sizeof(int8_t));
  printf("INT8_MIN size is %ld\n", INT8_MIN);
  printf("INT8_MAX size is %ld\n", INT8_MAX);
  printf("int16_t size is %ld\n", sizeof(int16_t));
  printf("INT16_MIN size is %ld\n", INT16_MIN);
  printf("INT16_MAX size is %ld\n", INT16_MAX);
  printf("uint16_t size is %ld\n", sizeof(uint32_t));
  printf("INT16_MIN size is %ld\n", INT32_MIN);
  printf("INT16_MAX size is %ld\n\n", INT32_MAX);

  printf("char size is %ld\n", sizeof(char));
  printf("unsigned char size is %ld\n", sizeof(unsigned char));
  printf("char size is %ld\n", sizeof(unsigned char));
  printf("int size is %ld\n", sizeof(int));
  printf("unsigned size is %ld\n", sizeof(unsigned));
  printf("short size is %ld\n", sizeof(short));
  printf("long size is %ld\n", sizeof(long));
  printf("unsigned long is %ld\n\n", sizeof(unsigned long));


  printf("CHAR_BIT    :   %d\n", CHAR_BIT);
  printf("CHAR_MAX    :   %d\n", CHAR_MAX);
  printf("CHAR_MIN    :   %d\n", CHAR_MIN);
  printf("INT_MAX     :   %d\n", INT_MAX);
  printf("INT_MIN     :   %d\n", INT_MIN);
  printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
  printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
  printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
  printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
  printf("SHRT_MAX    :   %d\n", SHRT_MAX);
  printf("SHRT_MIN    :   %d\n", SHRT_MIN);
  printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
  printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
  printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
  printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
}