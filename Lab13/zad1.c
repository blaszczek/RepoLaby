#include <stdio.h>
int main()
{
  int a, b;
  printf("Podaj liczbe wierszow i kolumn: \n");
  scanf("%i %i", &a, &b);
  int tab[a*b], tab2[b*a];
  int m = a*b, i, w, k;
  printf("Wpisywanie w tablce %i x %i \n",a,b);
  for(i=0; i<m; i++) scanf("%i", &tab[i]);
  printf("\nWyswietlanie tablicy tab \n");
  for(k=0; k<b; k++)
  {
    for(w=0; w<a; w++)
    {
      printf("%i ", tab[k*b+w]);
    }
    printf("\n");
  }
  printf("tab w tab2: \n");
  for(w=0; w<a; w++)
  {
    for(k=0; k<b; k++)
    {
      tab2[w*b+k] = tab[k*b+i];
    }
  }
  printf("Wyswietlanie tablicy tab2: \n");
  for(ko=0; ko<k; ko++)
  {
    for(w=0; w<a; w++)
    {
      printf("%i ",tab2[k*b+w]);
    }
    printf("\n");
  }
  return 0;
}