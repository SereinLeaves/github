//本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。
#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
/*这个解法太妙了！！！*/
int IsTheNumber ( const int N )
{
    int p=N;
    int num[10]={0};
    int n=sqrt(N);
    if(n*n==N)
    {
        while(p!=0)
        {
            num[p%10]++;//奇妙小统计
            p=p/10; 
        }
        for(int i=0;i<10;i++)
        {
            if(num[i]>=2)//只要碰到有重复的，所属位置必定大于等于2
            {
                return 1;
            }
        }
        return 0;
     } 
    else{
        return 0;
    }
}