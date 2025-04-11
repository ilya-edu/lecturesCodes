#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime> //С библиотека


void change(int& a) {
  a = 10;
}

int main()
{
  SetConsoleCP(1251);   // Кодировка ввода
  SetConsoleOutputCP(1251); // Кодировка вывода
  
  std::cout << "Hello World!\n";
  int x;
  std::cout << "Введите число: ";
  std::cin >> x;
  std::cout << "Вы ввели: " << x << std::endl;

  std::string name;
  std::cout << "Введите имя ";
  std::cin >> name;
  std::cout << "Привет, " << name << std::endl;

  std::cin.clear();   // Сброс ошибок ввода
  std::cin.ignore(10000, '\n');  // Очистка буфера до перевода строки

  std::string fullName;
  std::cout << "Введите полное имя ";
  std::getline(std::cin, fullName); //ввод с пробелами
  std::cout << "Привет, " << fullName << std::endl;

  bool isReady = true;
  std::cout << std::boolalpha << isReady << std::endl;
  
  auto x1 = 10;    // x - это int  
  auto y1 = 3.14;  // y - это double  
  auto s1 = "Hello"; // s - это const char*  

  auto var = 5.7; // Удобно, но использовать с осторожностью!
  std::cout << "var is " << var << std::endl;
  std::cout << typeid(var).name() << std::endl;
  std::cout << "input new var " << std::endl;
  std::cin >> var;
  std::cout << "var is " << var << std::endl;
  std::cout << typeid(var).name() << std::endl;

  int varChange = 5;
  std::cout << "varChange = " << varChange << std::endl;
  change(varChange); //Ссылки проще и безопаснее указателей.
  std::cout << "varChange = " << varChange << std::endl;
  

  int* p = new int(42);
  std::cout << *p << std::endl;
  delete p;

  int* arr = new int[5];
  delete[] arr;
  
  std::vector<int> numbers = { 5, 2, 8, 1, 4, 9 }; // Исходный массив
  int min = numbers[0];
  for (size_t i = 1; i < numbers.size(); i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  std::cout << "Минимальное значение: " << min << std::endl;
  //std::sort(numbers, numbers.size());

  std::srand(std::time(nullptr)); // Инициализируем генератор случайных чисел
  std::vector<int> numbersNew(10); // Создаем вектор на 10 элементов
  for (int& num : numbersNew) {
    num = std::rand() % 101; // Генерация числа от 0 до 100
  }
  // Выводим массив
  std::cout << "Массив: ";
  for (int num : numbersNew) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  // Находим минимальный элемент
  auto minIt = std::min_element(numbersNew.begin(), numbersNew.end());


  // Выводим минимальное значение
  if (minIt != numbersNew.end()) {
    std::cout << "Минимальный элемент: " << *minIt << std::endl;
  }

  float a = 10.0;
  float b = 0.0;
  float result = 0.0;

  //std::sort(numbersNew.begin(), numbersNew.end());

  //обработка исключений
  try {
    // Пытаемся выполнить деление
    result = a/b;
    std::cout << "Результат: " << result << std::endl;
  }
  catch (const std::runtime_error& e) {
    // Обработка исключения
    std::cerr << e.what() << std::endl; // Выводим сообщение об ошибке
  }

  system("pause");
  return 0;
}
