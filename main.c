#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "addFilm.h"
#include "authorization.h"
#include "catalog.h"
#include "favorites.h"
#include "registration.h"
#include "userInterface.h"
#include "functions.h" //кидайте туда полезные штуки которые не вписываются в другие либы


int main()
{
    system("chcp 65001"); system("cls");
    char * filename = "films.txt";
    load(filename);
    scanf("123");
    return 0;
    char input_str[25];
    for (;;) {
        puts("Вход / Регистрация\nВведите 1, чтобы зайти в уже существующий аккаунт или 2, чтобы зарегестрироваться");
        scanf("%25s", input_str); fflush(stdin);
        if (strcmp(input_str, "1") == 0) {
            system("cls"); login();
        } else if (strcmp(input_str, "2") == 0) {
            system("cls"); registration();
        } else {
            system("cls"); puts("Некорректный ответ.\nВведите 1, чтобы зайти в уже существующий аккаунт или 2, чтобы зарегестрироваться");
        }
    }
    return 0;
}
