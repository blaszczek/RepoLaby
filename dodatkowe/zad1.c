//Rafa³ B³aszkiewicz 238133
#define N 100 // definiowanie rozmiaru tablicy
#define M 80 // ilosc znakow na imie i nazwisko
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct osoba
{
	int nr_indeksu;
	char imie[M];
	char nazwisko[M];
} osoba;
osoba studenci[N];
osoba prawie_posortowane[N];
void wyswietl();
void wyswietl_s(int);
void dodaj_osobe();
void usun_osobe();
void search();
void sort();
void menu();
int myCompare(const void *v1, const void *v2);
int main(void)

{
	int i;

	for (i = 0; i < N; i++) {
		studenci[i].nr_indeksu = -1;
		studenci[i].imie[0] = '\0';
		studenci[i].nazwisko[0] = '\0';
	}
	menu();
	_getch();
	return 0;

}
void wyswietl()
{
	int i;
	system("cls");
	printf("\t\t==> Wyswietlanie osob z bazy danych <==");
	for (i = 0; i < N; i++) {
		if ((i + 1) % 10 == 0) _getch(); // zeby dalo sie jakos czytac
		if (studenci[i].nr_indeksu == -1) {
			if (i == 0) printf("\n\n\tNie ma zadnego studenta!");
			return; //nie ma nic dalej do wyswietlania
		}
		printf("\nNr: %6d\t%s %s", studenci[i].nr_indeksu, studenci[i].imie, studenci[i].nazwisko);
	}
	return;
}
void wyswietl_s(int Podany_Rozmiar)
{
	int i;
	system("cls");
	printf("\t==> Posortowana alfabetycznie *wg nazwiska* lista osob <==");
	for (i = 0; i < Podany_Rozmiar ; i++) {
		if ((i + 1) % 10 == 0) _getch(); // zeby dalo sie jakos czytac
		if (prawie_posortowane[i].nr_indeksu == -1) {
			if (i == 0) printf("\n\n\tNie ma zadnego studenta!");
			return; //nie ma nic dalej do wyswietlania
		}
		printf("\nNr: %6d\t%s %s", prawie_posortowane[i].nr_indeksu, prawie_posortowane[i].imie, prawie_posortowane[i].nazwisko);
	}
	return;

}
void dodaj_osobe()
{
	int x;
	int flaga=0;
	system("cls");
	printf("\t\t==> Dodawanie osoby z bazy danych <==");
	for (x = 0; x < N; x++) {
		if (studenci[x].nr_indeksu == -1) break;
	}
	if (x == N) {
		printf("\n\n\tBaza danych osiagnela swoj limit!\n\n\t\t\tNie mozna dodac nowej osoby!");
		return;
	}
	printf("\n\n\tPodaj nr albumu: ");
	scanf("%d", &studenci[x].nr_indeksu);
	printf("\tPodaj imie:\t ");
	scanf("%s", &studenci[x].imie);
	printf("\tPodaj nazwisko:\t ");
	scanf("%s", studenci[x].nazwisko);

}
void usun_osobe() {
	int i;
	int index;
	int j;
	int m;
	system("cls");
	printf("\t\t==> Usuwanie osoby z bazy danych <==");
	printf("\n\n\tPodaj numer albumu: ");
	scanf("%i", &index);
	for (i = 0; i < N; i++) {
		if (studenci[i].nr_indeksu != index) continue;
		else {
			for (j = i; j < N-1;j++) {
				studenci[j].nr_indeksu = studenci[j+1].nr_indeksu;
				for (m = 0; m < M; m++) {
					studenci[j].imie[m] = studenci[j+1].imie[m];
					studenci[j].nazwisko[m] = studenci[j+1].nazwisko[m];
				}
			}
			printf("\n\n\tUsunieto osobe z bazy o indexie: %d!", index);
			studenci[N-1].nr_indeksu = -1;
			studenci[N-1].imie[0] = '\0';
			studenci[N-1].nazwisko[0] = '\0';
			return;
		}
	}
	if (i == N) {
		printf("\n\n\tBrak osoby o takim indexie!");
	}
	return;
}
void search()
{
	int index;
	int i;
	system("cls");
	printf("\t==> Wyszukiwanie osoby o podanym numerze albumu <==");
	printf("\n\n\tPodaj numer albumu: ");
	scanf("%i", &index);
	for (i = 0; i < N; i++) {
		if (studenci[i].nr_indeksu != index) continue;
		else {
			printf("\n\n\tZnaleziono:");
			printf("\nNr: %6d\t%s %s", studenci[i].nr_indeksu, studenci[i].imie, studenci[i].nazwisko);
			return;
		}
	}
	if (i == N) {
		printf("\n\n\tBrak osoby o podanym numerze albumu!");
	}
	return;

}
void sort()
{
	int i;
	int m;
	for (i = 0; i < N; i++)
	{
		if (studenci[i].nr_indeksu == -1) break;
		else {
			prawie_posortowane[i].nr_indeksu = studenci[i].nr_indeksu;
			for (m = 0; m < M; m++) {
				prawie_posortowane[i].imie[m] = studenci[i].imie[m];
				prawie_posortowane[i].nazwisko[m] = studenci[i].nazwisko[m];
			}
		}
	}
	qsort(prawie_posortowane, i, sizeof(prawie_posortowane[0]), myCompare);
	wyswietl_s(i);
	return;
}
int myCompare(const void *v1, const void *v2)
{
	osoba* o1 = (osoba*)v1;
	osoba* o2 = (osoba*)v2;
	return strcmp(o1->nazwisko,o2->nazwisko);
}
void menu()
{
	char wybor;
	int flag;
	do {
		flag = 0;
		system("cls");
		printf("Podaj operacje\
		\n Dodaj osobe - d\
		\n Usun osobe - u\
		\n Wyswietlij wszystkie osoby - a\
		\n Sortuj Alfabetycznie, wg.nazwiska - s\
		\n Wyszukaj osobê po numerze indeksu- w\
		\n Zakoncz - k\n");

		scanf("%c", &wybor);

		switch (wybor)

		{

		case 'd':
			while (getchar() != '\n');
			dodaj_osobe();
			break;

		case 'u':
			while (getchar() != '\n');
			usun_osobe();
			break;

		case 's':
			while (getchar() != '\n');
			sort();
			break;

		case 'w':
			while (getchar() != '\n');
			search();
			break;

		case 'a':
			while (getchar() != '\n');
			wyswietl();
			break;

		case 'k':
			while (getchar() != '\n');
			break;
		default:
			flag = 1;
		}
		if (flag != 1) {
			printf("\n\n\tWcisinij dowolny przycisk,aby kontynuowac\n");
			_getch();
		}
	} while (wybor != 'k');

}
