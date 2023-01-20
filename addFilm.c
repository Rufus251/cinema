#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "addFilm.h"
#include "authorization.h"
#include "functions.h"

void add_film(){
    FILE *FILMS = fopen("../films.txt", "r");
    char temp[100]; char str[100]; int flag;
    printf("Введите фильм\n");
    SetConsoleCP(1251);
    gets(str); strcat(str, "\n"); fflush(stdin); SetConsoleCP(866);
    while(fgets(temp, 100, FILMS) != NULL) {
        if (strcmp(temp, str) == 0) {
            printf("Фильм уже добавлен");
            break;
        }
        else{
            fclose(FILMS);
            FILMS = fopen("../films.txt", "a");

            printf("Добавь меня полностью папочка");
            for (int i = 0; i < 4; ++i) {
                fputs(str, FILMS);
                gets(str);

            }
            break;
        }
    }
