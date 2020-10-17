#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node 
{     
    ElemType data;            /*数据域*/
    struct node *next;         /*指针域*/
} CSLinkList;

void InitList(CSLinkList *&L)       /*初始化线性表,L为引用型参数*/
{
    L=(CSLinkList *)malloc(sizeof(CSLinkList));
    L->next=L;
}

int GetLength(CSLinkList *L)    /*求线性表的长度*/
{
    int i=0;
    CSLinkList *p=L->next;
    while (p!=L) 
    {
        i++;p=p->next;
    }
    return i;
}

int GetElem(CSLinkList *L,int i,ElemType &e)    /*求线性表中第i个元素*/
{
    int j=1;
    CSLinkList *p=L->next;  
    if (i<1 || i>GetLength(L)) 
        return(0);            /*i参数不正确,返回0*/
    while (j<i)              /*从第1个结点开始,查找第i个结点*/
    {     
        p=p->next;
        j++;
    }
    e=p->data;
    return(1);              /*返回1*/
}

int Locate(CSLinkList *L,ElemType x)    /*按值查找*/
{
    int i=1;
    CSLinkList *p=L->next;
    while (p!=L && p->data!=x)      /*从第1个结点开始查找data域为x的结点*/
    {    p=p->next;
        i++;
    }
    if (p==L)
        return(0);
    else
        return(i);
}

int InsElem(CSLinkList *L,ElemType x,int i)    /*插入结点*/
{
    int j=1;
    CSLinkList *p=L,*s;
    s=(CSLinkList *)malloc(sizeof(CSLinkList));
    s->data=x;s->next=NULL;
    if (i<1 || i>GetLength(L)+1) 
        return 0;
    while (j<i) 
    {
        p=p->next;j++;
    }
    s->next=p->next;
    p->next=s;
    return 1;
}

int DelElem(CSLinkList *L,int i)    /*删除结点*/
{
    int j=1;
    CSLinkList *p=L,*q;
    if (i<1 || i>GetLength(L)) 
        return 0;
    while (j<i) 
    {
        p=p->next;j++;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

void DispList(CSLinkList *L)    /*输出线性表*/
{
    CSLinkList *p=L->next;
    while (p!=L) 
    {
        printf("%c ",p->data);p=p->next;
    }
    printf("\n");
}

int main()
{
    int i;
    ElemType e;
    CSLinkList *L;
    InitList(L);        /*初始化单链表L*/
    InsElem(L,'a',1);    /*插入元素*/
    InsElem(L,'c',2);
    InsElem(L,'a',3);
    InsElem(L,'e',4);
    InsElem(L,'d',5);
    InsElem(L,'b',6);
    printf("线性表:");DispList(L);
    printf("长度:%d\n",GetLength(L));
    i=3;GetElem(L,i,e);
    printf("第%d个元素:%c\n",i,e);
    e='a';
    printf("元素%c是第%d个元素\n",e,Locate(L,e));
    i=4;printf("删除第%d个元素\n",i);
    DelElem(L,i);
    printf("线性表:");DispList(L);

    system("pause");
    return 0;
}