// Temat 2
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *encode(const char *message);
static const char *decode(const char *message);
static void start();

typedef struct {
    char letter;
    const char *code;
} MorseEntry;

const MorseEntry morse[] = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},
    {'D', "-.."},   {'E', "."},     {'F', "..-."},
    {'G', "--."},   {'H', "...."},  {'I', ".."},
    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},
    {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},
    {'S', "..."},   {'T', "-"},     {'U', "..-"},
    {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},

    {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}
};

// default value
char choice = 'e';

int main(void) {
    start();
}

void clear_terminal(void) {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

static const char *encode(const char *message) {
    size_t length = strlen(message);

    // Sprawdzenie czy mamy wystarczajaco pamieci
    if (length > (SIZE_MAX - 1) / 6) {
        return NULL;
    }

    char *result = malloc(6 * length + 1);

    if (result == NULL) {
        return NULL;
    }

    size_t pos = 0;

    for (size_t i = 0; i < length; i++) {
        char letter = (char)toupper((unsigned char)message[i]);

        if (letter == ' ') {
            result[pos++] = '/';
            result[pos++] = ' ';
            continue;
        }
    }


    return result;
}

static void start() {
    clear_terminal();
    printf("Do you want to encode or decode the message?\n\n(e / d) > ");
    scanf("%s", &choice);
    printf("\n\n");

    if (choice == "d")  {
        printf("Decoded message %s");
    }
}