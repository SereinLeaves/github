#include<stdio.h>

int main(){
    double cost,power;
    scanf("%lf",&power);
    //printf("�տ�ʼpower=%lf\n",power);
    if(power<0){
        printf("Invalid Value!");
        return 0;
    }else if(power<50)
    {
        cost = 0.53*power;
        //printf("ִ����power<50�ĺ���,��ʱpower=%lf,cost=%lf\n",power,cost);
    }else
    {
        cost = 0.53*50+0.58*(power-50);
        //printf("ִ����power>50�ĺ�����\n");
    }
    printf("cost = %.2lf",cost);
    return 0;
}