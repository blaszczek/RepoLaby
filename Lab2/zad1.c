#include<stdio.h>
int main()
{
signed int a, b, c, d, e, f
a=5&3;
b=5|3;
c=7<<2&7;
d=7<<(2&7);
e=((-1)<<8)>>16;
f=13^9;
printf("%d, %d, %d, %d, %d, %d", a, b, c, d, e, f);
return 0;
}
