#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
  printf("|%11s|%8s|%21s|%21s|%13s|%10s|\n", "TYP", "ROZMIAR", "MIN", "MAX", "ZIARNO", "PRECYZJA");
  printf("|-----------|--------|---------------------|---------------------|-------------|----------|\n");
  printf("|%11s| %7li| %20i| %20i|%13c|%10c|\n", "short", sizeof(short), (short)SHRT_MIN, (short)SHRT_MAX, ' ', ' ');
  printf("|%11s| %7li| %20d| %20d|%13c|%10c|\n", "int", sizeof(int), (int)INT_MIN, (int)INT_MAX, ' ', ' ');
  printf("|%11s| %7li| %20li| %20li|%13c|%10c|\n", "long", sizeof(long), (long)LONG_MIN, (long)LONG_MAX, ' ', ' ');
  printf("|%11s| %7li| %20lli| %20lli|%13c|%10c|\n", "long long", sizeof(long long), (long long)LLONG_MIN, (long long)LLONG_MAX, ' ', ' ');
  printf("|%11s| %7li| %20e| %20e| %e| %9d|\n", "float", sizeof(float), (float)FLT_MIN, (float)FLT_MAX, FLT_EPSILON, (int)FLT_DIG);
  printf("|%11s| %7li| %20le| %20le| %e| %9d|\n", "double", sizeof(double), (double)DBL_MIN, (double)DBL_MAX, DBL_EPSILON, (int)DBL_DIG);
  printf("|%11s| %7li| %20Le| %20Le| %Le| %9d|\n", "long double", sizeof(long double), (long double)LDBL_MIN, (long double)LDBL_MAX, LDBL_EPSILON, (int)LDBL_DIG);
 
}
