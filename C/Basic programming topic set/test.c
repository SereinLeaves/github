#include <stdio.h>
#include <windows.h>

int main()
{
	int a=5,b=0;
	double c=0.0;
	b=1/a;
	c=1/(a*1.0);
	printf("b=%d\n",b);
	printf("c=%lf\n",c);
	system("pause");
	return 0;
}
