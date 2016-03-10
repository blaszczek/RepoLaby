#include<stdio.h>
#include<float.h>
#include<limits.h>

int main()
{
  FILE *fp;
    if ((fp=fopen("zapisanie.txt", "w"))==NULL)
	{
       printf ("blad\n");
       return;
    }



    fprintf(fp,"|typ        |                  min|                  max|    ziarno| prec\t\t\t|we/wy|\n");
    fprintf(fp,"|-----------------------------------------------------------------------------------------------|-----|\n");

    fprintf(fp,"|short      | %20i| %20i|          |     \t\t\t| i   |\n",SHRT_MIN, SHRT_MAX);
    fprintf(fp,"|int        | %20d| %20d|          |     \t\t\t| d   |\n",INT_MIN, INT_MAX);
    fprintf(fp,"|long       | %20li| %20li|          |     \t\t\t| li  |\n",LONG_MIN,LONG_MAX);
    fprintf(fp,"|long long  | %20lli| %20lli|          |     \t\t\t| lli |\n",LONG_LONG_MIN,LONG_LONG_MAX);
    fprintf(fp,"|float      |              3.4E-38|              3.4E+38|       %d  |   %d \t\t| f   |\n",FLT_EPSILON,FLT_DIG);
    fprintf(fp,"|double     |             1.7E-308|             1.7E+308|       %d  |  %d \t\t| lf  |\n",DBL_EPSILON,DBL_EPSILON);
    fprintf(fp,"|long double|             1.7E-308|             1.7E+308|       %d  |  %d \t\t| Lf  |\n",LDBL_EPSILON,LDBL_DIG);
    fprintf(fp,"|-----------------------------------------------------------------------------------------------------|\n");
    fclose (fp);


return 0;
}
