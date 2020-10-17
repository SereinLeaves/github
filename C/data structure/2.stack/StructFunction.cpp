typedef char ElemType;
#define StackSize 100        /*顺序栈的初始分配空间*/
typedef struct 
{    
    ElemType data[StackSize];    /*保存栈中元素*/
    int top;                    /*栈指针*/
} SqStack;

typedef struct lsnode 
{    
    ElemType data;            /*存储结点数据*/
    struct lsnode *next;    /*指针域*/
} LinkStack;