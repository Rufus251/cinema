#include <string.h>
#include <ctype.h>
#include "stdio.h"

void to_lower(char *string) {
    for(int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

void wait() {
    char c;
    scanf("%c", &c);
    fflush(stdin);
}
