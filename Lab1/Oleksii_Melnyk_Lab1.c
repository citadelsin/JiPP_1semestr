#include <stdio.h>
#include <time.h>

// Zadanie 10 i 11

#define Y 5
#define ADD(a, b) (a + b)
#define VER 2


int main(void) {
    int x,y;

    y = 5;
    x = y;
    x += 3;
    x *= 2;

    #if VER == 2
        y = Y;
        x = y;
        x = ADD(x, 3);
        x *= 2;
    #else
        y = 5;
        x = y;
        x += 3;
        x *= 2;
    #endif
    return 0;
}


// Zadanie 12


int main(void) {
    unsigned int rok_urodzenia;

    printf("Podaj date urodzenia: ");
    scanf(" %u", &rok_urodzenia);

    printf("\nMasz %u lat", 2026 - rok_urodzenia);

    return 0;
}
