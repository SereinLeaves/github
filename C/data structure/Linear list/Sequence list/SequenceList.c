#include <stdio.h>
#define MAXSIZE 100 /*顺序表的容量*/
typedef char ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; /*存放顺序表的元素*/
    int length;                /*顺序表的实际长度*/
} SqList;