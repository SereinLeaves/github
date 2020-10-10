//简单阶乘计算 (10分)
#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int Factorial( const int N ){
    int sum=1;
if(N<0){
    return 0;
}else{
    for(int i=1;i<=N;i++){
        sum=sum*i;
    }
    return sum;
}
}