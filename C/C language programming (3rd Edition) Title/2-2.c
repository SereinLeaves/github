#include<stdio.h>

int main(){
    double cost,power;
    scanf("%lf",&power);
    //printf("刚开始power=%lf\n",power);
    if(power<0){
        printf("Invalid Value!");
        return 0;
    }else if(power<50)
    {
        cost = 0.53*power;
        //printf("执行了power<50的函数,此时power=%lf,cost=%lf\n",power,cost);
    }else
    {
        cost = 0.53*50+0.58*(power-50);
        //printf("执行了power>50的函数。\n");
    }
    printf("cost = %.2lf",cost);
    return 0;
}