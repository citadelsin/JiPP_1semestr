#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

// Zadanie 9

/*
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803


static void kolo(double r, double *w1, double *w2);

int main(void) {
    double r;
    double pole = 0;
    double obwod = 0;

    printf("Podaj promien kola: ");
    scanf("%lf", &r);

    kolo(r, &pole, &obwod);

    printf("Promien: %.2lf\nPole %.2lf\nObwod: %.2lf", r, pole, obwod);

    return 0;
}

static void kolo(double r, double *w1, double *w2) {
    *w1 = PI * pow(r, 2);
    *w2 = 2 * PI * r;
}
*/

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

// Zadanie 10

/*
static void zamien(int *x, int *y);

int main(void) {
    int a, b;

    printf("Podaj dwie liczby calkowite:");
    scanf("%d %d", &a, &b);
    printf("\n1. a: %d | b: %d", a, b);
    zamien(&a, &b);
    printf("\n2. a: %d | b: %d", a, b);

    return 0;
}

static void zamien(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
*/

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

// Zadaine 11

/*
static double z(double x, double y);

int main(void) {
    double a, b;
    printf("Podaj X i Y > ");
    scanf("%lf %lf", &a, &b);

    z(a, b);

    return 0;
}

static double z(double x, double y) {
    int numer_wzoru;
    double result = 1;

    if (pow(x, 2) + pow(y, 2) <= 1) {
        numer_wzoru = 1;
        result = pow(x, 2) + y;
    } else if (y > x + 5) {
        numer_wzoru = 2;
        result = 2 * x + pow(y, 2);
    } else if (pow(x, 2) + pow(y, 2) > 1 && y <= x + 5) {
        numer_wzoru = 3;
        result = 0.5 * pow(x, 2) + y;
    }
    printf("x: %.2lf | y: %.2lf\nNumer wzoru: %d\nWynik: %.2lf", x, y, numer_wzoru, result);

    return result;
}
*/

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

// Zadanie 12
/*
static unsigned long int suma_kolejnych_n_naturalnych(unsigned long int n);

int main(void) {
    unsigned long int n;

    printf("Sume ile kolejnych liczb naturalnych chcesz obliczyc > ");
    scanf("%lu", &n);
    printf("\nSuma %lu liczb calkowitych to %lu", n, suma_kolejnych_n_naturalnych(n));

    return 0;
}

static unsigned long int suma_kolejnych_n_naturalnych(unsigned long int n) {
    if (n == 0) {
        return 0;
    }

    return n + suma_kolejnych_n_naturalnych(n - 1);
}
*/

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

// Zadanie 13

/*
static void hanoi(int N, char A, char B, char C);

int main(void) {
    hanoi(5, 'A', 'B', 'C');

    return 0;
}

static void hanoi(int N, char A, char B, char C) {
    if (N == 1) {
        printf("%c -> %c\n", A, B);
        return;
    }

    hanoi(N - 1, A, C, B);
    printf("%c -> %c\n", A, B);
    hanoi(N - 1, C, B, A);
}
*/
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------