#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define IMIE_MAX 10
#define NAZW_MAX 15
#define IL_OSOB 10000

typedef struct {
  char imie[IMIE_MAX+1];
  char nazwisko[NAZW_MAX+1];
  int pensja;
} osoba;

osoba spis[IL_OSOB];

//=======================================================

void  utworz_spis(void) {
  FILE* baza =
    fopen("mBaza","r");
  if (baza == NULL) printf("\n ZLE\n\n");
  for (int i=0; i<IL_OSOB; i++) {
    fscanf(baza, "%s", spis[i].imie);
    fscanf(baza, "%s", spis[i].nazwisko);
    fscanf(baza, "%i", &spis[i].pensja);
  }
  fclose(baza);
}

//=======================================================

int compare(const void *s1, const void *s2, void *arg)
  {
    osoba *o1 = (osoba *)s1;
    osoba *o2 = (osoba *)s2;
    int *n = (int *)arg;
    switch ( *n ) {
      case 1:
        return strcmp(o1 -> nazwisko, o2 -> nazwisko);
        break;
      case 2:
        return strcmp(o1 -> imie, o2 -> imie);
        break;
      case 3:
        if ( o1 -> pensja > o2 -> pensja) {
          return -1;
        }
        break;
      default:
      break;
    }
}
// powyzsza funkcja generuje ostrzerzenie -Wreturn-type
//=======================================================


void  sortuj_spis() {
  int opcja;
  printf("Jak chcesz posortować spis? : \n");
  scanf("%d",&opcja);
  qsort_r ( spis, IL_OSOB, sizeof(osoba), compare, &opcja);
}

//=======================================================
void spis_do_pliku() {


  FILE *fp = fopen("posortowany", "w");

  if( !fp ) {
    printf("Błąd odczytu pliku");
  }
    for( int i = 0; i < IL_OSOB; ++i) {
      if(spis[i].pensja)
        fprintf(fp,"%s %s %i\n",spis[i].imie, spis[i].nazwisko, spis[i].pensja);
      else continue;
    }
  fclose(fp);
}
//=======================================================
int  znajdz_nazwisko (char *na, char *im, int *p)
{

	for(int i = 0; i < IL_OSOB; ++i){
		if(strcmp( spis[i].nazwisko, na) == 0){
		strcpy( im, spis[i].imie );
		*p = spis[i].pensja;
		return 1;
		}
	}
	return 0;
}

//=======================================================
//połaczyć znajdz nazwisko i znajdz imie
int  znajdz_imie (char *im, char *na, int *p)
{

	for( int i = 0; i < IL_OSOB; ++i ){
		if( strcmp( spis[i].imie, im) == 0 ){
		strcpy( na, spis[i].nazwisko );
		*p = spis[i].pensja;
		return 1;
		}
	}
	return 0;
}

//=======================================================

int main () {
  char odpowiedz, im[NAZW_MAX+1], na[IMIE_MAX+1];
  int p;

  utworz_spis(); sortuj_spis();spis_do_pliku();

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
      else  printf(" nie ma nazwiska %s\n", im);
      break;
    case 'q' : break;
    default :
      printf(" Poprawne odpowiedzi: N, I, Q.\n");
    }
  }  while (tolower(odpowiedz) != 'q');

  printf("\n DZIEKUJE.\n\n");
}
