#include <stdio.h>
#include <math.h>

static double f_szereg(double x, double delta, int M, int *lwsz, int *ws);
static unsigned long int factorial(unsigned long int n);
static double analityczny(double x) {return exp(x);}

int main(void) {
    double x = 1.0;

    double epsilon = 0.001;
    int M = 10;


    double a = 0.0;
    double b = 2.0;

    if (M <= 0 || epsilon <= 0) {
        printf("Nie prawidlowe parametry.");
        return 1;
    }

    int lwsz, ws;

    double wynik = f_szereg(x, epsilon, M, &lwsz, &ws);

    printf("%.4f %.6f %d %d\n", x, wynik, lwsz, ws);
    printf("x: %.4lf\tf_szereg(x): %.4lf\nliczba wyrazow szeregu: %d\twarunek stopu: %d", x, wynik, lwsz, ws);

    return 0;
}

static double f_szereg(double x, double delta, int M, int *lwsz, int *ws) {
    double suma = 0.0;
    double poprzednia_suma = 0.0;

    for (int j = 0; j < M; j++) {
        poprzednia_suma = suma;
        suma +=  pow(x, j) / factorial(j);

        *lwsz = j + 1;

        if (fabs(suma - poprzednia_suma) <= delta) {
            *ws = (j + 1 == M) ? 3 : 1;
            return suma;
        }
    }

    *ws = 2;
    return suma;
}

static unsigned long int factorial(unsigned long int n) {
    unsigned long int iloczyn = 1;

    while (n > 0) {
        iloczyn *= n;
        n--;
    }

    return iloczyn;
}