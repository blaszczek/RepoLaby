#include <stdio.h>
int main()
{
  int a=2, b=4;
  if ((a=2) & (b=4)) printf("TAK\n");
  else printf("NIE\n");
  return 0;
}
// Program wypisze slowo "NIE".
