#include <stdio.h>
#define CZYT(zm,tp) printf("Podaj zmienna %s: ", #zm);scanf("%"#tp,&zm);
int main()
{
  double a;
  CZYT(a, lf);
  printf("\n%lf\n", a);
  return 0;
}
