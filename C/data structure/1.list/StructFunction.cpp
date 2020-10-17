#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 /*顺序表的容量*/

typedef char ElemType;

//顺序存储结构
typedef struct
{
    ElemType data[MAXSIZE]; /*存放顺序表的元素*/
    int length;             /*顺序表的实际长度*/
} SqList;

//链式存储结构
//单链表
typedef struct node
{
    ElemType data;     /*数据域*/
    struct node *next; /*指针域*/
} SLink;

//双链表
typedef struct node
{
    ElemType data;             /*数据域*/
    struct node *prior, *next; /*分别指向前驱结点和后继结点的指针*/
} DLink;

void InitList(SqList sq);                  /*初始化线性表*/

int GetLength(SqList sq);                  /*求线性表长度*/

int GetElem(SqList sq, int i, ElemType *e);    /*求线性表中第i个元素,需要通过指针保存的数据用*e*/

int Locate(SqList sq, ElemType x);         /*按值查找,不需要保存的数据用x*/

int InsElem(SqList sq, ElemType x, int i); /*插入元素*/

int DelElem(SqList sq, int i);             /*删除元素*/

void DispList(SqList sq);                  /*输出线性表*/
