#define QueueSize 100
typedef char ElemType;
typedef struct  
{    
    ElemType data[QueueSize];    /*�������Ԫ��*/
    int front,rear;                /*��ͷ�Ͷ�βָ��*/
} SqQueue;

typedef char ElemType;
typedef struct QNode 
{
    ElemType data;
    struct QNode *next;
} QType;                /*�����н�������*/
typedef struct qptr        
{
    QType *front,*rear;
} LinkQueue;            /*��������*/