typedef char ElemType;
#define StackSize 100        /*˳��ջ�ĳ�ʼ����ռ�*/
typedef struct 
{    
    ElemType data[StackSize];    /*����ջ��Ԫ��*/
    int top;                    /*ջָ��*/
} SqStack;

typedef struct lsnode 
{    
    ElemType data;            /*�洢�������*/
    struct lsnode *next;    /*ָ����*/
} LinkStack;