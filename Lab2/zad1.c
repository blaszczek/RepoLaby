#include <stdio.h>
void dec_bin(int x)
{
  int tab[10];
  int l=0;
  while(x!=0)
  {
    tab[l]=x%2;
    x=x/2;
    l++;
  }
  while(l>0)
  {
    l--;
    printf("%i", tab[l]);
  }
  printf("\n");
}
int main()
{
  char z;
  z=getchar();
  while(z!=EOF)
  {
    if(z!='\n') dec_bin(z);
    z=getchar();
  }
  return 0;
}
