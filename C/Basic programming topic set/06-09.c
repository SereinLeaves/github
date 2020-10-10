/*
统计个位数字 (15分)
本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。
其中N和D都是用户传入的参数。N的值不超过int的范围；D是[0, 9]区间内的个位数。函数须返回N中D出现的次数。

*/
#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D ){
    int a[10]={0};
    int p=N;
    if(p<0){
        p=-p;
    }else if(N==0&&D==0){
        return 1;
    }
    while(p!=0){
        a[p%10]++;
        p=p/10;
    }
    return a[D];
}