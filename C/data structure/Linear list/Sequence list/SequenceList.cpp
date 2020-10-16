#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 /*顺序表的容量*/
typedef char ElemType;

typedef struct
{
    ElemType data[MAXSIZE]; /*存放顺序表的元素*/
    int length;             /*顺序表的实际长度*/
} SqList;

void InitList(SqList &sq) /*初始化线性表*/
{
    sq.length = 0;
}

int GetLength(SqList sq) /*求线性表长度*/
{
    return sq.length;
}

int GetElem(SqList sq, int i, ElemType &e) /*求线性表中第i个元素*/
{
    if (i < 1 || i > sq.length) /*无效的i值*/
        return 0;
    else
    {
        e = sq.data[i - 1];
        return 1;
    }
}

int Locate(SqList sq, ElemType x) /*按值查找*/
{
    int i = 0;
    while (sq.data[i] != x) /*查找值为x的第1个结点*/
        i++;
    if (i > sq.length)
        return (0); /*未找到*/
    else
        return (i + 1);
}

int InsElem(SqList &sq, ElemType x, int i) /*插入元素*/
{
    int j;
    if (i < 1 || i > sq.length + 1) /*无效的参数i*/
        return 0;
    for (j = sq.length; j > i; j--) /*将位置为i的结点及之后的结点后移*/
        sq.data[j] = sq.data[j - 1];
    sq.data[i - 1] = x; /*在位置i处放入x*/
    sq.length++;        /*线性表长度增1*/
    return 1;
}

int DelElem(SqList &sq, int i) /*删除元素*/
{
    int j;
    if (i < 1 || i > sq.length) /*无效的参数i*/
        return 0;
    for (j = i; j < sq.length; j++) /*将位置为i的结点之后的结点前移*/
        sq.data[j - 1] = sq.data[j];
    sq.length--; /*线性表长度减1*/
    return 1;
}

void DispList(SqList sq) /*输出线性表*/
{
    int i;
    for (i = 1; i <= sq.length; i++)
        printf("%c ", sq.data[i - 1]);
    printf("\n");
}

int main()
{
    int i;
    ElemType e;
    SqList sq;
    InitList(sq);        /*初始化顺序表sq*/
    InsElem(sq, 'a', 1); /*插入元素*/
    InsElem(sq, 'c', 2);
    InsElem(sq, 'a', 3);
    InsElem(sq, 'e', 4);
    InsElem(sq, 'd', 5);
    InsElem(sq, 'b', 6);
    printf("线性表:");
    DispList(sq);
    printf("长度:%d\n", GetLength(sq));
    i = 3;
    GetElem(sq, i, e);
    printf("第%d个元素:%c\n", i, e);
    e = 'a';
    printf("元素%c是第%d个元素\n", e, Locate(sq, e));
    i = 4;
    printf("删除第%d个元素\n", i);
    DelElem(sq, i);
    printf("线性表:");
    DispList(sq);
    system("pause");
    return 0;
}










/**
 * 走的弯路
 * int main(int argc, char const *argv[])
{
     SqList sq;
     sq = (SqList)malloc(sizeof(SequenceList));
    sq->Data[0]=0;
    sq->length=1;知道了，结构体指针需要malloc函数分配空间
    sq->length=0;出问题了，这样定义的结构体不能直接赋值
    SequenceList sql;
    sql.length=1;
    SequenceList *sq=NUL·L;
    sq->Data[0]=1;
    printf("sql.length=%d\n",sql.length);
    printf("sq->Data[0]=%d , length=%d\n",sq->Data[0],sq->length);
    system("pause");
    return 0;
 * 
*/
