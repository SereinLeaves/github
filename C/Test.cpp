#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node 
{     
    ElemType data;            /*������*/
    struct node *next;         /*ָ����*/
} CSLinkList;

void InitList(CSLinkList *&L)       /*��ʼ�����Ա�,LΪ�����Ͳ���*/
{
    L=(CSLinkList *)malloc(sizeof(CSLinkList));
    L->next=L;
}

int GetLength(CSLinkList *L)    /*�����Ա�ĳ���*/
{
    int i=0;
    CSLinkList *p=L->next;
    while (p!=L) 
    {
        i++;p=p->next;
    }
    return i;
}

int GetElem(CSLinkList *L,int i,ElemType &e)    /*�����Ա��е�i��Ԫ��*/
{
    int j=1;
    CSLinkList *p=L->next;  
    if (i<1 || i>GetLength(L)) 
        return(0);            /*i��������ȷ,����0*/
    while (j<i)              /*�ӵ�1����㿪ʼ,���ҵ�i�����*/
    {     
        p=p->next;
        j++;
    }
    e=p->data;
    return(1);              /*����1*/
}

int Locate(CSLinkList *L,ElemType x)    /*��ֵ����*/
{
    int i=1;
    CSLinkList *p=L->next;
    while (p!=L && p->data!=x)      /*�ӵ�1����㿪ʼ����data��Ϊx�Ľ��*/
    {    p=p->next;
        i++;
    }
    if (p==L)
        return(0);
    else
        return(i);
}

int InsElem(CSLinkList *L,ElemType x,int i)    /*������*/
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

int DelElem(CSLinkList *L,int i)    /*ɾ�����*/
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

void DispList(CSLinkList *L)    /*������Ա�*/
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
    InitList(L);        /*��ʼ��������L*/
    InsElem(L,'a',1);    /*����Ԫ��*/
    InsElem(L,'c',2);
    InsElem(L,'a',3);
    InsElem(L,'e',4);
    InsElem(L,'d',5);
    InsElem(L,'b',6);
    printf("���Ա�:");DispList(L);
    printf("����:%d\n",GetLength(L));
    i=3;GetElem(L,i,e);
    printf("��%d��Ԫ��:%c\n",i,e);
    e='a';
    printf("Ԫ��%c�ǵ�%d��Ԫ��\n",e,Locate(L,e));
    i=4;printf("ɾ����%d��Ԫ��\n",i);
    DelElem(L,i);
    printf("���Ա�:");DispList(L);

    system("pause");
    return 0;
}