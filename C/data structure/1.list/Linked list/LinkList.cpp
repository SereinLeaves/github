/**
 * @file LinkList.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-17
 * 
 * @copyright Copyright (c) 2020
 * 单链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct node
{
    Elemtype data;     /*数据域*/
    struct node *next; /*指针域*/
} SLinkList;

void InitList(SLinkList *&L) /*L作为引用型参数*/
{
    L = (SLinkList *)malloc(sizeof(SLinkList)); /*创建头结点*L*/
    L->next = NULL;
}

int GetLength(SLinkList *L) /*求线性表的长度*/
{
    int i = 0;
    SLinkList *p = L->next;
    // SLinkList *p = L;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

int GetElem(SLinkList *L, int i, Elemtype &e) /*求线性表中第i个元素*/
{
    int j = 1;
    SLinkList *p = L->next;
    if (i < 1 || i > GetLength(L))
    {
        return 0; /*i参数不正确,返回0*/
    }
    while (j < i) /*从第1个结点开始找,查找第i个结点*/
    {
        p = p->next;
        j++;
    }
    e = p->data;
    return 1; /*返回1*/
}

int Locate(SLinkList *L, Elemtype x) /*按值查找*/
{
    int i = 1;
    SLinkList *p = L->next;
    while (p != NULL && p->data != x) /*从第1个结点开始查找data域为x的结点*/
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

int InsElem(SLinkList *L, Elemtype x, int i) /*插入结点*/
{
    int j = 1;
    SLinkList *p = L, *s;
    s = (SLinkList *)malloc(sizeof(SLinkList)); /*创建data域为x的结点*/
    s->data = x;
    s->next = NULL;
    if (i < 1 || i > GetLength(L) + 1) //为什么是i>GetLength(L)+1而不是i>GetLength(L)？
    {
        return 0; /*i参数不正确,插入失败,返回0*/
    }
    /***
     * 上面的问题有答案了：因为我们要插入结点，如果不多一个位置的话就插不进去
     */
    while (j < i) /*从头结点开始找,查找第i-1个结点,由p指向它*/
    {
        p = p->next;
        j++;
    }
    s->next = p->next; /*将*s的next域指向*p的下一个结点(即第i个结点)*/
    p->next = s;       /*将*p的next域指向*s,这样*s变成第i个结点*/
    return 1;          /*插入运算成功,返回1*/
}

int DelElem(SLinkList *L, int i) /*删除结点*/
{
    int j = 1;
    SLinkList *p = L, *q;
    if (i < 1 || i > GetLength(L)) //判断结点是否存在
    {
        return 0; /*i参数不正确,插入失败,返回0*/
    }
    while (j < i) /*从头结点开始,查找第i-1个结点,由p指向它*/
    {
        p = p->next;
        j++;
    }
    q = p->next;       //由q指向第i个结点
    p->next = q->next; /*将*p的next指向*q之后结点,即从链表中删除第i个结点*/
    free(q);           /*释放第i个结点占用的空间，删除q*/
    return 1;          /*删除运算成功,返回1*/
}
void DispList(SLinkList *L) //打印输出单链表
{
    SLinkList *p = L->next;
    while (p != NULL)
    {
        printf(" %c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int i;
    Elemtype e;
    SLinkList *L;
    InitList(L);        /*初始化单链表L*/
    InsElem(L, 'a', 1); /*插入元素*/
    // InsElem(L, 'c', 2);
    // InsElem(L, 'a', 3);
    // InsElem(L, 'e', 4);
    // InsElem(L, 'd', 5);
    // InsElem(L, 'b', 6);
    printf("线性表：");
    DispList(L);
    printf("长度：%d\n", GetLength(L));
    i = 3;
    GetElem(L, i, e);
    printf("第%d个元素:%c\n", i, e);
    e = 'a';
    printf("元素%c是第%d个元素\n", e, Locate(L, e));
    i = 1;
    printf("删除第%d个元素\n", i);
    DelElem(L, i);
    printf("线性表:");
    DispList(L);
    printf("长度：%d\n", GetLength(L));

    system("pause");
    return 0;
}
