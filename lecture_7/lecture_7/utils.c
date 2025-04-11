#include "main.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char* figureNames[] = { "None", "Rect", "Triag", "Cyrcle" };//чтобы выводить тип enum 

int myAdd(int a, int b) {
  return a + b;
}
int mySub(int a, int b) {
  return a - b;
}

Rect* CreateRect() //создание объекта Rect
{
  Rect* p = NULL;
  p = (Rect*)malloc(sizeof(Rect));
  if (p == NULL)
    return NULL;

  p->kind = rect;
  p->x = 0.0;
  p->y = 0.0;

  return p;
}

Cyrcle* CreateCyrcle() //создание объекта Cyrcle
{
  int rad = 0;
  Cyrcle* p = (Cyrcle*)malloc(sizeof(Cyrcle));
  if (p == NULL)
    return NULL;

  p->kind = cyrcle;
  p->radius = rad;

  return p;
}

Triangle* CreateTriangle() //создание объекта Triangle
{
  Triangle* p = (Triangle*)malloc(sizeof(Triangle));
  if (p == NULL)
    return NULL;

  p->kind = triag;
  p->x = 0.0;
  p->y = 0.0;
  p->z = 0.0;

  return p;
}

void printRectArr(Rect arrStrt[], int size) { //передача копии массива структур
  for (int i = 0; i < size; i++)
    printf("Rect[%d]: kind=%d, x=%.2f, y=%.2f\n", i, arrStrt[i].kind, arrStrt[i].x, arrStrt[i].y);
}

void printRect(Rect r) {
  printf("Rect: kind=%d, %.2f, %.2f\n", r.kind, r.x, r.y);
  r.y = r.y * 2; //пробуем изменить параметр, не получится
}

void printRectPtr(Rect *r) {
  printf("RectPtr: kind=%d, %.2f, %.2f\n", r->kind, r->x, r->y);
  r->y = r->y * 2; //пробуем изменить параметр, получится
}

float rectArea(void* data) {
  if (data == NULL)
    return -1;
  Rect* r = (Rect*)data;
  return r->x * r->y;
}

float cyrcleArea(void* data) {
  if (data == NULL)
    return -1;
  Cyrcle* c = (Cyrcle*)data;
  return M_PI * c->radius * c->radius;
}

float triagArea(void* data) {
  if (data == NULL)
    return -1;
  Triangle* t = (Triangle*)data;
  float s = (t->x + t->y + t->z) / 2;
  return sqrt(s * (s - t->x) * (s - t->y) * (s - t->z));
}

void printInsideObj(void** pobj, int ord)
{
  Figures kind = *((Figures*)pobj[ord]);//достаем первые 4 байта в каждом объекте, т.к. enum вначале у каждой структуры
  Shape* myShape = NULL;
  myShape = (Shape*)malloc(sizeof(Shape));  

  switch (kind)
  {
  case rect:
    printf("Rect: x=%.2f y=%.2f\n", ((Rect*)(pobj[ord]))->x, ((Rect*)(pobj[ord]))->y);
    myShape != NULL ? myShape->area = rectArea : printf("Rect Area not available");
    break;
  case cyrcle:
    printf("Cyrcle: rad=%.2f \n", ((Cyrcle*)(pobj[ord]))->radius);
    myShape != NULL ? myShape->area = cyrcleArea : printf("Cyrle Area not available");
    break;  
  case triag:
    printf("Triag: x=%.2f y=%.2f z=%.2f\n", ((Triangle*)(pobj[ord]))->x, ((Triangle*)(pobj[ord]))->y, ((Triangle*)(pobj[ord]))->z);
    myShape != NULL ? myShape->area = triagArea : printf("Triangle Area not available");
    break;    
  default:
    printf("\nNone\n");
    break;
  }
  
  if (myShape != NULL) {
    myShape->strctData = pobj[ord];
    printf("%s area: %.2f\n", figureNames[kind], myShape->area(myShape->strctData));
    free(myShape);
  } 
}
