
#include <stdio.h>
#include <math.h>

#define N 4

// Funkcja obliczajaca srednia geometryczna
double srednia_geometryczna(const double wektor[], int rozmiar) {
    double iloczyn = 1.0;
    int licznik = 0;

    for (int i = 0; i < rozmiar; i++) {
        if (wektor[i] > 0) {
            iloczyn *= wektor[i];
            licznik++;
        }
    }

    if (licznik == 0) {
        return NAN;
    }

    return pow(iloczyn, 1.0 / licznik);
}

// Funkcja wyswietlajaca wynik
void wypisz_wynik(const char *opis, const double wektor[], int ile) {
    double wynik = srednia_geometryczna(wektor, ile);

    if (isnan(wynik)) {
        printf("%s: brak dodatnich elementow\n", opis);
    } else {
        printf("%s: %.4f\n", opis, wynik);
    }
}

int main(void) {
    double macierz[16] = {
         2.0, -4.0,  6.0,  8.0,
         0.0,  3.0, -2.0,  5.0,
         7.0,  1.0,  9.0, -3.0,
        -1.0,  4.0,  2.0, 10.0
    };

    double wektor[16];
    int ile = 0;
    int k, l;

    // Wyswietlenie macierzy
    printf("Macierz 4x4:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.1f ", macierz[i * N + j]);
        }
        printf("\n");
    }

    // Wybor wiersza i kolumny
    printf("\nPodaj numer wiersza (1-4): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > N) {
        printf("Niepoprawny numer wiersza.\n");
        return 1;
    }

    printf("Podaj numer kolumny (1-4): ");
    if (scanf("%d", &l) != 1 || l < 1 || l > N) {
        printf("Niepoprawny numer kolumny.\n");
        return 1;
    }

    // Zamiana na indeksy od 0
    k--;
    l--;

    // 1. Wybrany wiersz
    ile = 0;
    for (int j = 0; j < N; j++) {
        wektor[ile++] = macierz[k * N + j];
    }
    wypisz_wynik("Wybrany wiersz", wektor, ile);

    // 2. Wybrana kolumna
    ile = 0;
    for (int i = 0; i < N; i++) {
        wektor[ile++] = macierz[i * N + l];
    }
    wypisz_wynik("Wybrana kolumna", wektor, ile);

    // 3. Glowna przekatna
    ile = 0;
    for (int i = 0; i < N; i++) {
        wektor[ile++] = macierz[i * N + i];
    }
    wypisz_wynik("Glowna przekatna", wektor, ile);

    // 4. Elementy pod glowna przekatna
    ile = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            wektor[ile++] = macierz[i * N + j];
        }
    }
    wypisz_wynik("Pod przekatna", wektor, ile);

    // 5. Druga przekatna
    ile = 0;
    for (int i = 0; i < N; i++) {
        wektor[ile++] = macierz[i * N + (N - 1 - i)];
    }
    wypisz_wynik("Druga przekatna", wektor, ile);

    return 0;
}
