#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
} SLink;

void InitList(SLink *&L)
{
    L = (SLink *)malloc(sizeof(SLink));
    L->next = NULL;
}

int GetLength(SLink *L)
{
    int i = 0;
    SLink *p = L->next;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

int GetElem(SLink *L, int i, Elemtype &e)
{
    int j = 1;
    SLink *p = L->next;
    if (i < 1 || i > GetLength(L))
    {
        return 0;
    }
    while (j<i)
    {
        p=p->next;
        j++;
    }
    e=p->data;
    return 1;
}

int Locate(SLink *L,Elemtype x)
{
    int i=1;
    SLink *p=L->next;
    while (p!=NULL&&p->data!=x)
    {
        p=p->next;
        i++;
    }
    if (p==NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

int InsElem(SLink *L,Elemtype x,int i)
{
    int j=1;
    SLink *p=L,*s;
    s=(SLink *)malloc(sizeof(SLink));
    s->data=x;
    s->next=NULL;
    if (i<1||i>GetLength(L)+1)//为什么是i>GetLength(L)+1而不是i>GetLength(L)？
    {
        return 0;
    }
    /***
     * 上面的问题有答案了：因为我们要插入结点，如果不多一个位置的话就插不进去
     */
    while (j<i)
    {
        p=p->next;
        j++;
    }
    s->next=p->next;    
    p->next=s;
    return 1;
}

















int main()
{

    system("pause");
    return 0;
}
