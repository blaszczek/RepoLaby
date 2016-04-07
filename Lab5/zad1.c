#include <stdio.h>

void funkcja(int n, int k, int *q, int *r)
{
*q=n/k;
*r=n%k;
}
int main()
{
int o, p, iloraz, reszta;
printf("podaj o\n");
scanf("%d", &o);
printf("podaj p\n");
scanf("%d", &p);
funkcja(o, p, &iloraz, &reszta);
printf("%d, %d", o, p);
return 0;
}
