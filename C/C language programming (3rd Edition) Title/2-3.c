#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
	 double sum=0.0;
   scanf("%d%d",&m,&n);
	for (int i = m; i <= n; i++)
	{
		sum=sum+i*i+1/(i*1.0);
	}
	
	printf("sum = %.6lf\n",sum);
	system("pause");
   return 0;
}

