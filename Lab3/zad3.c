#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
  printf("(int)FLT_MAX:\n%e => %i\n", (int)FLT_MAX);
  printf("(int)DBL_MAX:\n%e => %i\n", (int)DBL_MAX);
  printf("(double)LDBL_MAX:\n%Le => %e\n", (double)LDBL_MAX);
  printf("(double)LLONG_MAX:\n%lli => %e\n", (double)LLONG_MAX);
  printf("(float)LLONG_MAX:\n%lli => %e\n", (float)LLONG_MAX);
  return 0;
}
