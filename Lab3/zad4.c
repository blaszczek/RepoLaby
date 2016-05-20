/*
Eksperymentalnie zbadać ,,ziarno'' w różnych typach rzeczywistych. W tym celu należy wykonać pętlę postaci podobnej do poniższej:
    x = 1.0;
    while (1.0+x > 1.0)
      x = x/2.0;
dla zmiennej x zadeklarowanej kolejno jako float, double i long double.
*/
#include <stdio.h>
int main()
{
  int l=1;
  printf("Float:\n");
  float x=1.0;
  while(1.0+x>1.0)
  {
    x=x/2.0;
    printf("%i. %f => %e\n", l, x, x);
    l++;
  }
  l=1;
  printf("Double:\n");
  double x1=1.0;
  while(1.0+x1>1.0)
  {
    x1=x1/2.0;
    printf("%i. %f => %e\n", l, x1, x1);
    l++;
  }
  l=1;
  printf("Long double:\n");
  long double x2=1.0;
  while(1.0+x2>1.0)
  {
    x2=x2/2.0;
    printf("%i. %Lf => %Le\n", l, x2, x2);
    l++;
  }

}
