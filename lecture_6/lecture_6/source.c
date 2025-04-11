#include "main.h"
// в этом файле реализации функций

int Sum(int a, int b)
{
  return a + b;
}

Rect* CreateRect() {
  Rect* p = NULL;
  p = (Rect*)malloc(sizeof(Rect));
  if (p == NULL)
    return NULL;
  p->x = 20;// в С нет конструкторов для структур, поэтому можно необходимые переменные инициализировать в функции
  p->kind = rect;
  return p;
}

Cyrcle* CreateCyrcle() {
  Cyrcle* p = NULL;
  p = (Cyrcle*)malloc(sizeof(Cyrcle));
  if (p == NULL)
    return NULL;
  p->kind = cyrcle;
  return p;
}