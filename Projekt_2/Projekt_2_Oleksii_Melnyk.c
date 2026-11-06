// Temat 2
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MORSE 36

static const char *find_morse(char letter);
static char find_letter(char *code);
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

static const char *find_morse(char letter) {
    for (size_t i = 0; i < SIZE_MORSE; i++) {
        if (morse[i].letter == letter) {
            return morse[i].code;
        }
    }

    return NULL;
}

static char find_letter(char *code) {
    for (size_t i = 0; i < SIZE_MORSE; i++) {
        if (strcmp(morse[i].code, code) == 0) {
            return morse[i].letter;
        }
    }

    return '\0';
}

static const char *encode(const char *message) {
    size_t memory_needed = 1;

    for (size_t i = 0; message[i] != '\0'; i++) {
        char letter = (char)toupper(((unsigned char)message[i]));
        char *found_code = find_morse(letter);

        size_t additional = 0;

        if (found_code == NULL) {
            if (message[i] == ' ') {
                additional += 2;
                continue;
            } else if (message[i] == '.' || message[i] == '-') {
                continue;
            } else {
                additional += 1;
                continue;
            }


        } else {
            additional = strlen(found_code) + 1;
        }

        if (additional > SIZE_MAX - memory_needed) {
            return NULL;
        }

        memory_needed += additional;
    }

    char *result = malloc(memory_needed);

    if (result == NULL) {
        return NULL;
    }

    result[0] = '\0';

    for (size_t j; message[j] != '\0'; j++) {
        char letter = (char)toupper((unsigned char)message[j]);
        const char *found_code = find_morse(letter);

        if (found_code != NULL) {
            strcat(result, found_code);
            strcat(result, " ");
        } else if (letter = ' ') {
            strcat(result, "/ ");
        } else if (letter == '.' || letter == '-') {
            continue;
        } else {
            size_t pos = strlen(result);
            result[pos] = message[j];
            result[pos + 1] = '\0';
        }
    }

    return result;
}

static const char *decode(const char *message) {
    size_t length = strlen(message);

    char *result = malloc(length + 1);

    if (result == NULL) {
        return NULL;
    }

    size_t pos = 0;
    size_t i = 0;

    while (message[i] != '\0') {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        if (message[i] == '/') {
            result[pos++] = ' ';
            i++;
            continue;
        }

        char code[6];
        size_t j = 0;

        while (message[i] == '.' || message[i] == '-') {
            if (j > sizeof(code) - 1) {
                free(result);
                return NULL;
            }

            code[j++] = message[i++];
        }

        code[j] = '\0';

        if (j == 0) {
            free(result);
            return NULL;
        }

        char letter = find_letter(code);

        if (letter == '\0') {
            free(result);
            return NULL;
        }

        result[pos++] = letter;
    }
    result[pos] = '\0';

    return result;
}

static void start(void) {
    clear_terminal();

    char choice[10];
    char message[1024];

    printf("Do you want to encode or decode the message?\n\n");
    printf("(e / d) > ");

    if (fgets(choice, sizeof(choice), stdin) == NULL) {
        return;
    }

    printf("\nType message to encode / decode > ");

    if (fgets(message, sizeof(message), stdin) == NULL) {
        return;
    }

    message[strcspn(message, "\n")] = '\0';

    if (choice[0] == 'e') {
        char *encoded = encode(message);

        if (encoded != NULL) {
            printf("Encoded message > \n%s", encoded);
            free(encoded);
        }
    } else if (choice[0] == 'd') {
        char *decoded = decode(message);

        if (decoded != NULL) {
            printf("Decoded message > \n%s", decoded);
            free(decoded);
        }
    }
}