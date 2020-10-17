/**
 * @file LinkList.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-17
 * 
 * @copyright Copyright (c) 2020
 * ������
 */
#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;
typedef struct node
{
    Elemtype data;     /*������*/
    struct node *next; /*ָ����*/
} SLinkList;

void InitList(SLinkList *&L) /*L��Ϊ�����Ͳ���*/
{
    L = (SLinkList *)malloc(sizeof(SLinkList)); /*����ͷ���*L*/
    L->next = NULL;
}

int GetLength(SLinkList *L) /*�����Ա�ĳ���*/
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

int GetElem(SLinkList *L, int i, Elemtype &e) /*�����Ա��е�i��Ԫ��*/
{
    int j = 1;
    SLinkList *p = L->next;
    if (i < 1 || i > GetLength(L))
    {
        return 0; /*i��������ȷ,����0*/
    }
    while (j < i) /*�ӵ�1����㿪ʼ��,���ҵ�i�����*/
    {
        p = p->next;
        j++;
    }
    e = p->data;
    return 1; /*����1*/
}

int Locate(SLinkList *L, Elemtype x) /*��ֵ����*/
{
    int i = 1;
    SLinkList *p = L->next;
    while (p != NULL && p->data != x) /*�ӵ�1����㿪ʼ����data��Ϊx�Ľ��*/
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

int InsElem(SLinkList *L, Elemtype x, int i) /*������*/
{
    int j = 1;
    SLinkList *p = L, *s;
    s = (SLinkList *)malloc(sizeof(SLinkList)); /*����data��Ϊx�Ľ��*/
    s->data = x;
    s->next = NULL;
    if (i < 1 || i > GetLength(L) + 1) //Ϊʲô��i>GetLength(L)+1������i>GetLength(L)��
    {
        return 0; /*i��������ȷ,����ʧ��,����0*/
    }
    /***
     * ����������д��ˣ���Ϊ����Ҫ�����㣬�������һ��λ�õĻ��Ͳ岻��ȥ
     */
    while (j < i) /*��ͷ��㿪ʼ��,���ҵ�i-1�����,��pָ����*/
    {
        p = p->next;
        j++;
    }
    s->next = p->next; /*��*s��next��ָ��*p����һ�����(����i�����)*/
    p->next = s;       /*��*p��next��ָ��*s,����*s��ɵ�i�����*/
    return 1;          /*��������ɹ�,����1*/
}

int DelElem(SLinkList *L, int i) /*ɾ�����*/
{
    int j = 1;
    SLinkList *p = L, *q;
    if (i < 1 || i > GetLength(L)) //�жϽ���Ƿ����
    {
        return 0; /*i��������ȷ,����ʧ��,����0*/
    }
    while (j < i) /*��ͷ��㿪ʼ,���ҵ�i-1�����,��pָ����*/
    {
        p = p->next;
        j++;
    }
    q = p->next;       //��qָ���i�����
    p->next = q->next; /*��*p��nextָ��*q֮����,����������ɾ����i�����*/
    free(q);           /*�ͷŵ�i�����ռ�õĿռ䣬ɾ��q*/
    return 1;          /*ɾ������ɹ�,����1*/
}
void DispList(SLinkList *L) //��ӡ���������
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
    InitList(L);        /*��ʼ��������L*/
    InsElem(L, 'a', 1); /*����Ԫ��*/
    // InsElem(L, 'c', 2);
    // InsElem(L, 'a', 3);
    // InsElem(L, 'e', 4);
    // InsElem(L, 'd', 5);
    // InsElem(L, 'b', 6);
    printf("���Ա�");
    DispList(L);
    printf("���ȣ�%d\n", GetLength(L));
    i = 3;
    GetElem(L, i, e);
    printf("��%d��Ԫ��:%c\n", i, e);
    e = 'a';
    printf("Ԫ��%c�ǵ�%d��Ԫ��\n", e, Locate(L, e));
    i = 1;
    printf("ɾ����%d��Ԫ��\n", i);
    DelElem(L, i);
    printf("���Ա�:");
    DispList(L);
    printf("���ȣ�%d\n", GetLength(L));

    system("pause");
    return 0;
}
