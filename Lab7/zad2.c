#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define IMIE_MAX 11
#define NAZW_MAX 17
#define IL_OSOB 1000
typedef struct
{
  char imie[IMIE_MAX+1];
  char nazwisko[NAZW_MAX+1];
  int pensja;
} osoba;
osoba spis[IL_OSOB];
//=======================================================
void utworz_spis(char *name, int *linie)
{
  FILE *baza = fopen(name, "r");
  if(baza == NULL) printf("\nBlad!\n\n");
  int i;
  for(i = 0; i < *linie; i++)
  {
    fscanf(baza, "%s", spis[i].imie);
    fscanf(baza, "%s", spis[i].nazwisko);
    fscanf(baza, "%i", &spis[i].pensja);
  }
  fclose(baza);
}
//=======================================================
int lines(char *name)
{
  int linie = 0;
  FILE* plik;
  plik = fopen(name, "r");
  int w;
  do
  {
    fscanf(plik, "%s", spis[linie].imie);
    fscanf(plik, "%s", spis[linie].nazwisko);
    w = fscanf(plik, "%i", &spis[linie].pensja);
    linie++;
  } while(w != EOF);
  fclose(plik);
  return linie-1;
}
//=======================================================
int compare(const void *a, const void *b)
{
  osoba *osoba_a, *osoba_b;
  osoba_a = (osoba *) a;
  osoba_b = (osoba *) b;
  return strcmp(osoba_a->nazwisko, osoba_b->nazwisko);
}
//=======================================================
void sort_qsort(int *linie)
{
  qsort(spis, *linie, sizeof(osoba), compare);
  FILE *baza_q = fopen("qsort.txt", "w");
  int i;
  for(i = 0; i < *linie; i++)
  {
    fprintf(baza_q, "%20s ", spis[i].imie);
    fprintf(baza_q, "%20s ", spis[i].nazwisko);
    fprintf(baza_q, "%20i\n", spis[i].pensja);
  }
  fclose(baza_q);
}
//=======================================================
void sort_bubble(int *linie)
{
  int i, j;
  char temp[NAZW_MAX+1];
  for(i = 1; i <= *linie; i++)
  {
    for(j = i;j < *linie; j++)
    {
      if(strcmp(spis[j-1].nazwisko, spis[j].nazwisko) > 0)
      {
        strcpy(temp, spis[j-1].nazwisko);
        strcpy(spis[j-1].nazwisko, spis[j].nazwisko);
        strcpy(spis[j].nazwisko, temp);
      }
      else if(strcmp(spis[j-1].nazwisko, spis[j].nazwisko) == 0)
      {
        strcpy(temp, spis[j-1].imie);
        strcpy(spis[j-1].imie, spis[j].imie);
        strcpy(spis[j].imie, temp);
      }
    }
  }
  FILE* baza_b = fopen("bubblesort.txt", "w");
  for(i = 0; i < *linie; i++)
  {
    fprintf(baza_b, "%20s ", spis[i].imie);
    fprintf(baza_b, "%20s ", spis[i].nazwisko);
    fprintf(baza_b, "%20i\n", spis[i].pensja);
  }
  fclose(baza_b);
}
//=======================================================
int main(int args, char* arg[])
{
  if(args == 2)
  {
    char name[100];
    sscanf(arg[1], "%s", name);
    int l;
    l = lines(name);
    if(l > IL_OSOB)
    {
      printf("Za duzo osob! Nie dam rady!\n");
      return 0;
    }
    printf("Zeskanowalem %i linii z pliku %s\n", l, arg[1]);
    utworz_spis(name, &l);
    clock_t begin = clock();
    sort_qsort(&l);
    clock_t end = clock();
    printf("\nCzas wykonania qsorta: %lf sek.\n\n", (double)(end-begin)/CLOCKS_PER_SEC);
    clock_t begin2 = clock();
    sort_bubble(&l);
    clock_t end2 = clock();
    printf("\nCzas wykonania bubble: %lf sek.\n\n", (double)(end2-begin2)/CLOCKS_PER_SEC);
    printf("\nPosortowane!\n\n");
    return 0;
  } else printf("\nNiepoprawne wywolanie programu!\n");
  printf("Wywolanie programu wymaga argumentu!\n");
  printf("./zad2 nazwapliku(lub lokalizacja pliku)!\n");
  return 0;
}
