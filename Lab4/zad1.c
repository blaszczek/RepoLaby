#include <stdio.h>
#include <complex.h>

// definicja typu liczb zespolonych

typedef struct {
  double rea, ima;
}  zespol;

int main () {

    double x,y,k,l;
    printf("Podaj Re(z1) : \n");
    scanf("%lf", &x);
    printf("Podaj Im(z1) : \n");
    scanf("%lf", &y);
    printf("Podaj Re(z2) : \n");
    scanf("%lf", &k);
    printf("Podaj Im(z2) : \n");
    scanf("%lf", &l);

    double complex z1 = x + y * I;
    double complex z2 = k - l * I;

    printf("Dzialania na liczbach zespolonych:\n\v");

    printf("Wartosci poczatkowe : Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n\v", creal(z1), cimag(z1), creal(z2), cimag(z2));
    double complex sum = z1 + z2;
    printf("Z1+Z2=%.2f %+.2fi\n", creal(sum), cimag(sum));
    
    double complex minus = z1 - z2;
    printf("Z1 - Z2 = %.2f %+.2fi\n\v", creal(minus), cimag(minus));

    double complex mnoz = z1 * z2;
    printf("Z1 x Z2 = %.2f %+.2fi\n\v", creal(mnoz), cimag(mnoz));

    double complex dziel = z1 / z2;
    printf("Z1 / Z2 = %.2f %+.2fi\n\v", creal(dziel), cimag(dziel));

    double complex spr = conj(z1);
    printf("Sprzezenie Z1 = %.2f %+.2fi\n\v", creal(spr), cimag(spr));

}
