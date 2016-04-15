#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

#define IMIE_MAX 10
#define NAZW_MAX 15
#define IL_OSOB 15

typedef struct {
  char imie[IMIE_MAX+1];
  char nazwisko[NAZW_MAX+1];
  int pensja;
} osoba;

osoba spis[IL_OSOB];

//=======================================================

void utworz_spis(char *czytaj) {
  FILE* baza =fopen(czytaj,"r");
  if (baza == NULL) printf("\n ZLE\n\n");
  for (int i=0; i<IL_OSOB; i++) {
    fscanf(baza, "%s", spis[i].imie);
    fscanf(baza, "%s", spis[i].nazwisko);
    fscanf(baza, "%i", &spis[i].pensja);
  }
  fclose(baza);
}

//=======================================================

int compare(const void * _s1, const void * _s2){
  osoba *s1 = (osoba *) _s1;
  osoba *s2 = (osoba *) _s2;


  if(strcmp(s1-> nazwisko, s2-> nazwisko)==0)
  return strcmp(s1-> imie, s2-> imie);
  else
  return strcmp(s1-> nazwisko, s2-> nazwisko);
}

void  sortuj_spis(char *niew) {
  /* sortuje  spis  alfabetycznie wg nazwisk,
     a w przypadku rownych nazwisk wg imion
  */
  FILE* baza2 =fopen(niew, "w");
  qsort(spis, IL_OSOB, sizeof(osoba), compare);
    int i;
    for (i = 0; i < IL_OSOB; i++) {
	       fprintf(baza2, "%15s	", spis[i].imie);
	       fprintf(baza2, "%15s	", spis[i].nazwisko);
	       fprintf(baza2, "%15i\n", spis[i].pensja);
    }
  fclose(baza2);
}
//=======================================================

int  znajdz_nazwisko (char na[NAZW_MAX+1],char im[IMIE_MAX+1], int *p) {
  /* do danego nazwiska  na  znajduje w spisie
     imie  im  oraz pensje  p
     jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
  int i;
  for(i=0; i<IL_OSOB; i++)
  {
      if(strcmp(spis[i].nazwisko,na) == 0){
      strcpy(im,spis[i].imie);
      *p = spis[i].pensja;
      return 1;
    }
  }
  return 0;
}


//=======================================================

int  znajdz_imie (char im[NAZW_MAX+1], char na[IMIE_MAX+1], int *p) {
  /* do danego imienia  im  znajduje w spisie
     nazwisko  na  oraz pensje  p
     jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
  int i;
  for(i=0; i<IL_OSOB; i++)
  {
      if(strcmp(spis[i].imie,im) == 0){
      strcpy(na,spis[i].nazwisko);
      *p = spis[i].pensja;
      return 1;
    }
  }

return 0;
}

//=======================================================

int main (int argc, char *argv[]) {
  char odpowiedz, im[NAZW_MAX+1], na[IMIE_MAX+1];
  int p;

  utworz_spis(argv[1]); sortuj_spis(argv[2]);

  do {
    printf(
     "\n Znalezc wg imienia (I), nazwiska (N), czy zakonczyc (Q)? "
    );
    do { odpowiedz = getchar(); }
    while (isspace(odpowiedz));
    odpowiedz = tolower(odpowiedz);
    switch (odpowiedz) {
    case 'i' :
      printf("\n szukane imie: ");
      scanf("%s", im);
      if (znajdz_imie(im, na, &p))
	printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
      else  printf(" nie ma imienia %s\n", im);
      break;
    case 'n' :
      printf("\n szukane nazwisko: ");
      scanf("%s", na);
      if (znajdz_nazwisko(na, im, &p))
	printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
      else  printf(" nie ma nazwiska %s\n", na);
      break;
    case 'q' : break;
    default :
      printf(" Poprawne odpowiedzi: N, I, Q.\n");
    }
  }  while (tolower(odpowiedz) != 'q');

  printf("\n DZIEKUJE.\n\n");
  return 0;
}
