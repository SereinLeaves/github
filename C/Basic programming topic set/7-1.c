/**
 * ¿Â√◊ªªÀ„”¢≥ﬂ”¢¥Á
*/
#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    double m,foot,inch;
    scanf("%lf",&m);
    foot=m/0.3048/100;
    inch=(foot-(int)foot)*12;
    //inch=modf((m/0.3048/100),&foot);
    printf("%d %d",(int)foot,(int)inch);
    return 0;
}
