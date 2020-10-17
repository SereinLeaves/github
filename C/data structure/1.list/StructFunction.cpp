#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 /*˳��������*/

typedef char ElemType;

//˳��洢�ṹ
typedef struct
{
    ElemType data[MAXSIZE]; /*���˳����Ԫ��*/
    int length;             /*˳����ʵ�ʳ���*/
} SqList;

//��ʽ�洢�ṹ
//������
typedef struct node
{
    ElemType data;     /*������*/
    struct node *next; /*ָ����*/
} SLink;

//˫����
typedef struct node
{
    ElemType data;             /*������*/
    struct node *prior, *next; /*�ֱ�ָ��ǰ�����ͺ�̽���ָ��*/
} DLink;

void InitList(SqList sq);                  /*��ʼ�����Ա�*/

int GetLength(SqList sq);                  /*�����Ա���*/

int GetElem(SqList sq, int i, ElemType *e);    /*�����Ա��е�i��Ԫ��,��Ҫͨ��ָ�뱣���������*e*/

int Locate(SqList sq, ElemType x);         /*��ֵ����,����Ҫ�����������x*/

int InsElem(SqList sq, ElemType x, int i); /*����Ԫ��*/

int DelElem(SqList sq, int i);             /*ɾ��Ԫ��*/

void DispList(SqList sq);                  /*������Ա�*/
