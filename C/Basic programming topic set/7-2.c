/* #include <stdio.h>

int main()
{
    int nowTime, midTime, resultTime;
    int hour, min;
    int tmp;
    //printf("这是tmp1:%d",tmp);
    //这里出问题了,scanf没输入数据
    scanf("%d%d", &nowTime, &midTime);
    if (nowTime < 100)
    {
        return 0;
    }

    tmp = nowTime;
    hour = tmp / 100;
    min = tmp % 100;

    //开始添加时间
    min = min + midTime;

    if (min < 0)
    { //分钟小于0
        min = -min;
        hour = hour - 1 - min / 60;
        min = 60 - min;
    }
    else
    { //分钟大于0
        hour = hour + min / 60;
        min = min % 60;
    }

    printf("%2d%02d", hour, min);

    return 0;
}
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  int hour = a / 100;
  int min = a % 100;
  if (b > 0)
  {
    int inHour = (min + b) / 60;
    int inMin = (min + b) % 60;
    printf("%02d%02d\n", hour + inHour, inMin);
  }
  else
  {
    hour = hour - (-b) / 60 - 1;
    int inMin = (60 - (-b) % 60 + min) % 60;
    hour = hour + (60 - (-b) % 60 + min) / 60;
    printf("%d%02d\n", hour, inMin);
  }
  system("pause");
  return 0;
}