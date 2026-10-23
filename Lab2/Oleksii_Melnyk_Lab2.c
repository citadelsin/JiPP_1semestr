#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926

static void my_exit();
static void my_return();

void raiseError(const char *message) {
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}   

void my_exit() {
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while((ch = getchar()) != EOF)
    ;
    exit(1);
}

void my_return() {
    int ch;
    printf("Zakoncz - ctrl+Z Enter\n");
    while((ch = getchar()) != EOF)
    ;
    exit(0);
}

// Zadanie 8
/*
int main(void) {
    double x = 3.14, y = 12.56, z = 7, k = 2, m = 4;

    double w1, w2, w3, w4, w5;

    w1 = cbrt(x / (y * z)) * log(pow(x, 2) + pow(y, 2));
    w2 = sin(k * (x / 2)) * cos(m * y) + (y * pow(exp(1), 2 * x - 1));
    w3 = abs(x / (2 * pow(y, 2) + 1)) + sqrt(y / (pow(z, 2) + 3)) + 5 * pow(y + z, 3);
    w4 = (x / (y * z)) * cbrt(z + 1) + pow(pow(x, 2) + pow(z, 2) + 1, 1 / k) - abs(y);
    w5 = (1 / (sqrt(pow(x, 2) + pow(y, 2) + pow(k, 2)))) + (1 / x) * sin(k * y);

    printf("w1 %lf\nw2 %lf\nw3 %lf\nw4 %lf\nw5 %lf", w1, w2, w3, w4, w5);

    return 0;
}
*/

// -------------------------------------------------------
// -------------------------------------------------------
// -------------------------------------------------------

// Zadanie 9

/*
int main(void) {
    double a = 0.0, b = 0.0, c = 0.0;
    int ret = -1;

    printf("Program obliczenia rzeczywistych pierwiastkow rownania kwadratowego\n");
    printf("-------------------- a*x^2+b*x+c = 0 ------------------------------\n\n");
    printf("Podaj a,b,c\n");
    
    ret = scanf("%le%le%le", &a, &b, &c);
    
    if(ret != 3) {
    printf("Blad przy wczytaniu\n");
    printf("Wczytane: a = %e b = %e c = %e\n", a, b, c);

    my_exit();
    }

    if (a == 0.0) {
    printf("To nie jest rownanie kwadratowe: a = 0.\n");
    my_exit();
    }

    double D = -1.0;
    double r, u;
    D = pow(b, 2) -4.0 * a * c;

    if(D < 0.0) {
        r = (-1.0 * b) / (2 * a);
        u = sqrt(-D) / fabs(2.0 * a);
    }

    double p1, p2, x1, x2;
    p1 = -b/(2.0*a);
    p2 = sqrt(D)/(2.0*a);
    x1 = p1+p2;
    x2 = p1-p2;
    printf("Rownanie kwadratowe: %.1lf *X*X + %.1lf *X + %.1lf = 0\n\n", a, b, c);

    if (D > 0.0) {
        printf("Pierwiastki: x1 = %e x2 = %e\n", x1, x2);
    } else {
        printf("Pierwiastki: x1 = %.1lf + %.1lfi : x2 = %.1lf - %.1lf\n\n", r, u, r, u);
    }
    printf("---------------------------------------------------------");

    my_return();

    return 0;
}
*/

// -------------------------------------------------------
// -------------------------------------------------------
// -------------------------------------------------------

// Zadanie 10
/*
int main(void) {
    double a, b, c;
    printf("Podaj trzy strony trojkata: ");
    scanf(" %lf %lf %lf", &a, &b, &c);

    double p = (a + b + c) / 2;
    double pole = sqrt(p * (p-a) * (p-b) * (p-c));
    double promien = pole / p;

    printf("\n\np = %lf\npole = %lf\npromien = %lf", p, pole, promien);
    return 0;
}
*/

// -------------------------------------------------------
// -------------------------------------------------------
// -------------------------------------------------------

// Zadanie 11

/*
int main(void) {
    int a, b, c, d;
    printf("Podaj cztery liczby calkowite: ");
    scanf(" %d %d %d %d", &a, &b, &c, &d);

    int max, pozycja;

    max = a;
    pozycja = 1;

    if (b > max) {
        max = b;
        pozycja = 2;
    }

    if (c > max) {
        max = c;
        pozycja = 3;
    }

    if (d > max) {
        max = d;
        pozycja = 4;
    }

    printf("\n\nNajwieksza liczba to {%d} pozycja %d", max, pozycja);

    return 0;
}
*/

// -------------------------------------------------------
// -------------------------------------------------------
// -------------------------------------------------------

// Zadanie 12

/*
void poleTrojkata(double a, double b, double c) {
    if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2;
        double pole = sqrt(p * (p-a) * (p-b) * (p-c));
        double obwod = a + b + c;

        printf("\n\nPole trojkata: %.2lf\nObwod trojkata: %.2lf", pole, obwod);
    } else {
        raiseError("Jeden z bokow ktory podales jest mniejszy lub rowny zero lub nie moze istniec.");
    }
}

void poleKwadratu(double a) {
    if (a <= 0) {
        raiseError("Dlugosc boku kwadratu nie moze byc mniejsza lub rowna zeru.");
    }

    printf("\n\nPole Kwadratu: %.2lf\nObwod kwadratu: %.2lf", pow(a, 2), a * 4);
}

void poleProstokata(double a, double b) {
    if (a <= 0 || b <= 0) {
        raiseError("Boki prostokata maja byc wieksze od zera.");
    }

    printf("\n\nPole prostokata: %.2lf\nObwod prostokata: %.2lf", a * b, (2 * a) + (2 * b));
}

void poleKola(double a) {
    if (a <= 0) {
        raiseError("Promien ma byc wiekszy od zera.");
    }

    printf("\n\nPole kola: %.4lfpi = %.4lf\nObwod kola: %.4lfpi = %.4lf", pow(a, 2), pow(a, 2) * PI, 2 * a, 2 * a * PI);
}

int main(void) {
    int wybor;
    double a, b, c, d;

    printf("Pole i obwod czego chcesz obliczyc?\n1. Trojkat\n2. Kwadrat\n3. Prostokat\n4. Kolo\n> ");
    scanf("%d", &wybor);

    if (wybor == 1) {
        printf("Podaj trzy boki trojkata > ");
        scanf("%lf %lf %lf", &a, &b, &c);
        poleTrojkata(a, b, c);
    } else if (wybor == 2) {
        printf("Podaj dlugosc boku kwadratu > ");
        scanf("%lf", &a);
        poleKwadratu(a);
    } else if (wybor == 3) {
        printf("Podaj dwa boki prostokata > ");
        scanf("%lf %lf", &a, &b);
        poleProstokata(a, b);
    } else if (wybor == 4) {
        printf("Podaj promien kola > ");
        scanf("%lf", &a);
        poleKola(a);
    }

    return 0;
}
*/