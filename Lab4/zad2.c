#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <complex.h>
//LICZBA EULERA
#define E 2.71828182845904523536;
#define M_PI 3.14159265358979323846
/****************************************************************/
// DEFINICJA TYPU LICZB ZESPOLONYCH:
typedef struct
{
  double rea, ima;
} zespol;
/****************************************************************/
// POMOCNICZE:
void err(char s[])
{
  // -- sygnalizacja bledu wejscia
  printf("\n!!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}
/****************************************************************/
// INICJALIZACJE oraz WEJSCIE-WYJSCIE:
zespol zesp_zestawic(double r, double i)
{
  // zestawienie liczby zespolonej z dwoch rzeczywistych
  zespol z;
  z.rea=r;
  z.ima=i;
  return z;
}
zespol zesp_get(void)
{
  /* wczytanie liczby zespolonej; powinna skladac sie z dwoch
  rzeczywistych, oraz plusa lub minusa miedzy nimi, zaczynac sie od
  nawiasu otwierajacego, konczyc sie litera ,,i'' oraz nawiasem
  zamykajacym;
  np. (123.45 + 67.89i) */
  char ch;
  zespol z;
  int znak_im;
  do
  {
    ch=getchar();
  } while(isspace(ch));
  if(ch=='(')
  {
    if(scanf("%lf", &(z.rea))==1)
    {
      do
      {
        ch = getchar();
      } while(isspace(ch));
      if(ch=='+' || ch=='-')
      {
        if(ch=='+') znak_im=1;
        else znak_im=-1;
        if(scanf("%lf", &(z.ima))==1)
        {
          do
          {
            ch=getchar();
          } while(isspace(ch));
          if(ch=='i')
          {
            do
            {
              ch=getchar();
            } while(isspace(ch));
            if(ch==')')
            {
              if(znak_im==-1) z.ima=-z.ima;
            } else err("brak koncowego nawiasu");
          } else err("brak 'i' na koncu czesci urojonej");
        } else err("niepoprawna czesc urojona");
      } else err("po czesci rzeczywistej brak znaku '+' lub '-'");
    } else err("niepoprawna czesc rzeczywista");
  } else err("brak rozpoczynajacego nawiasu");
  return z;
}
void zesp_print(zespol z)
{
  // drukowanie liczby zespolonej
  if(z.ima>=0) printf("(%.2lf+%.2lfi)", z.rea, z.ima);
  else printf("(%.2lf-%.2lfi)", z.rea, -z.ima);
}
/****************************************************************/
// DZIALANIA:
zespol zesp_dodac(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea+z2.rea;
  wyn.ima=z1.ima+z2.ima;
  return wyn;
}
// dodawanie liczb zespolonych
zespol zesp_odjac(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea-z2.rea;
  wyn.ima=z2.ima-z2.ima;
  return wyn;
}
// odejmowanie liczb zespolonych
zespol zesp_razy(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea*z2.rea-z1.ima*z2.ima;
  wyn.ima=z1.rea*z2.ima+z1.ima*z2.rea;
  return wyn;
}
// mnozenie liczb zespolonych
zespol zesp_dziel(zespol z1, int dzielnik)
{
  zespol wyn;
  wyn.rea=z1.rea/dzielnik;
  wyn.ima=z1.ima/dzielnik;
  return wyn;
}
// dzielenie liczb zespolonych
zespol zesp_sprzez(zespol z)
{
  zespol wyn;
  wyn.ima=-z.ima;
  return wyn;
}
// liczba sprzezona do danej zespolonej
double zesp_abs(zespol z)
{
  double wyn;
  wyn=sqrt(z.rea*z.rea+z.ima*z.ima);
  return wyn;
}
// wartosc bezwzgledna liczby zespolonej
/****************************************************************/
zespol euler()
{
  zespol z;
  z.rea=cos(M_PI);
  z.ima=sin(M_PI);
  return z;
}
zespol jeden()
{
  zespol one;
  one.rea=1;
  one.ima=0;
  return one;
}
zespol zero()
{
  zespol zero;
  zero.rea=0;
  zero.ima=0;
  return zero;
}
zespol zesp_exp(zespol z)
{
  zespol wyn=zero();
  zespol temp=jeden();
  int i;
  for(i=1;i<1000000;i++)
  {
    wyn=zesp_dodac(wyn, temp);
    temp=zesp_dziel(zesp_razy(temp, z), i);
  }
  return wyn;
}
// Funkcje Eulera
int main()
{
  zespol z1, z2;
  zespol Eul=euler();
  zespol O=jeden();
  zespol PII={0.0, M_PI};
  zespol left=zesp_dodac(zesp_exp(PII), O);
  printf("Z1 == "); z1 = zesp_get();
  printf("Z2 == "); z2 = zesp_get();
  printf("\nZ1+Z2 == "); zesp_print(zesp_dodac(z1, z2));
  printf("\nZ1-Z2 == "); zesp_print(zesp_odjac(z1, z2));
  printf("\nZ1*Z2 == "); zesp_print(zesp_razy(z1, z2));
  printf("\n|Z1+Z2| == %.4lf\n", zesp_abs(zesp_dodac(z1, z2)));
  printf("Tozsamosc Eulera: \n");
  zesp_print(Eul);
  printf(" + ");
  zesp_print(O);
  printf(" = ");
  zesp_print(zesp_dodac(Eul, O));
  printf("\n");
  zesp_print(zesp_exp(Eul));
  printf("\n");
  zesp_print(left);
  printf("\n");
  
}
