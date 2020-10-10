#include<stdio.h>

int main(){
    int a,b,c,d,Sum;
    double Average;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    Sum=a+b+c+d;
    Average=(Sum*1.0)/4;
    printf("Sum = %d; Average = %.1lf",Sum,Average);
    return 0;
}