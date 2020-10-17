#define QueueSize 100
typedef char ElemType;
typedef struct  
{    
    ElemType data[QueueSize];    /*保存队中元素*/
    int front,rear;                /*队头和队尾指针*/
} SqQueue;

typedef char ElemType;
typedef struct QNode 
{
    ElemType data;
    struct QNode *next;
} QType;                /*链队中结点的类型*/
typedef struct qptr        
{
    QType *front,*rear;
} LinkQueue;            /*链队类型*/