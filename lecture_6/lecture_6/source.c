#include "main.h"
// � ���� ����� ���������� �������

int Sum(int a, int b)
{
  return a + b;
}

Rect* CreateRect() {
  Rect* p = NULL;
  p = (Rect*)malloc(sizeof(Rect));
  if (p == NULL)
    return NULL;
  p->x = 20;// � � ��� ������������� ��� ��������, ������� ����� ����������� ���������� ���������������� � �������
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