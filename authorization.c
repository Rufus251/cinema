#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "functions.h"
#include "registration.h"

#define skip fgets(temp, 27, USER_DATA)

int start();
int login();

int start() {
    char input_str[25];
    for (;;) {
        printf(
               "░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░\n"
               "░░░░░░░░░░░░░░░░░▄████▄░░░░░░░░░░░░░░░░░\n"
               "░░░░░░░░░░░░░░░░▄██████▄░░░░░░░░░░░░░░░░\n"
               "░░░░░░████▄▄▄▄▄▄████████▄▄▄▄▄▄████░░░░░░\n"
               "░░░░░░████████████████████████████░░░░░░\n"
               "░░░░░░████████████████████████████░░░░░░\n"
               "░░░░░░██████▀▀░░▄▄▀▀▀▀▄▄░▀▀███████░░░░░░\n"
               "░░░▄▄██████░░░░▀▀░░░░░░▀▀░░░░██████▄▄░░░\n"
               "▄▄█████▀████▄█████▄░░▄█████▄████▀█████▄▄\n"
               "▀██████▄░░██▀░░░░░▀██▀░░░░░▀█▀░░▄██████▀\n"
               "░░▀█████░░██░░░░░██████░░░░░██░░▀████▀░░\n"
               "░░░░▀███░░▀█▄░░░░▀████▀░░░░▄█▀░░░██▀░░░░\n"
               "░░░░░░▀█░░░▀██▄▄▄██████▄▄▄██▀░░░▄▀░░░░░░\n"
               "░░░░░░░██░░░░░▀▀▀░░██░░▀▀▀░░░░░░█░░░░░░░\n"
               "░░░░░░░███▄░░░░░░░▀██▀░░░░░░░░░▄█░░░░░░░\n"
               "░░░░░▄▀░███▄░░░░░░░░░░░░░░░░░░▄█░▀▄░░░░░\n"
               "░░░░░█░░█░▀███▄▄░░░░░░░░░░░░▄▀░█░░█░░░░░\n"
               "░░░░░█░░▀▄░░▀██████▄▄▄▄▄▄██▀░░▄▀░░█░░░░░\n"
               "░░░░░░▀▄▄▀░░░░░▀███▀▀███▀░░░░░▀▄▄▀░░░░░░\n"
               "░░░░░░░░░░░░░░▄▀░░█░░█░░▀▄░░░░░░░░░░░░░░\n"
               "░░░░░░░░░░░░░░▀▀▀▀▀░░▀▀▀▀▀░░░░░░░░░░░░░░\n"
               "\n");
        puts("Вход / Регистрация\nВведите 1, чтобы зайти в уже существующий аккаунт или 2, чтобы зарегестрироваться");
        scanf("%25s", input_str); fflush(stdin);
        if (strcmp(input_str, "1") == 0) {
            system("cls"); return login();
        } else if (strcmp(input_str, "2") == 0) {
            system("cls"); registration();
        } else {
            system("cls"); puts("Некорректный ответ");
        }
    }
}


int user_login_check(char str[27]) {
    FILE *USER_DATA = fopen("../users.txt", "r");
    char temp[27]; strcat(str, "\n");
    while (fgets(temp, 27, USER_DATA) != NULL) { //login
        if (strcmp(temp, str) == 0) {
            skip; skip; skip;
            fgets(temp, 27, USER_DATA);
            if (strcmp(temp, "1\n") == 0) {
                fclose(USER_DATA); return 1; //admin user
            } else return 0;
        } else {
            skip; skip; skip; skip; skip;
        }
    }
    fclose(USER_DATA); return -1; // cant find user login
}

int user_pass_check(char str[27], char *login) {
    FILE *USER_DATA = fopen("../users.txt", "r");
    char temp[27]; strcat(str, "\n");
    while (fgets(temp, 27, USER_DATA) != NULL) { //found parsed login
        if (strcmp(temp, login) == 0) {
            fgets(temp, 27, USER_DATA);
            if (strcmp(temp, str) == 0) {
                fclose(USER_DATA); return 1;
            } else continue;
        } else {
            skip; skip; skip; skip; skip;
        }

    }
    fclose(USER_DATA); return -1;
}


int login() {
    char input_str[25], name[25];
    for (;;) {
        color_switch_white; puts("Введите логин:"); color_switch_green;
        scanf("%25s", input_str); fflush(stdin);
        int login_check = user_login_check(input_str);
        if (login_check == -1) {
            color_switch_white; puts("Пользователь не найден. Введите любой символ чтобы продолжить");
            wait(); clear;
            continue;
        } else if (login_check == 0 || login_check == 1) {
            strncpy(name, input_str, 25);
            color_switch_white; printf("Введите пароль:\n"); color_switch_green;
            scanf("%25s", input_str); fflush(stdin); color_switch_white;
            int pass_check = user_pass_check(input_str, name);
            if (pass_check == 1) {
                //user
                if (login_check == 0) {
                    color_switch_white; printf("\nЗдарова "); color_switch_red; printf("%s", name);
                    color_switch_white; puts("Введите любой символ чтобы продолжить");
                    wait(); clear;
                    return 0;
                }
                //admin
                if (login_check == 1) {
                    color_switch_white; printf("\nЗдарова админ "); color_switch_red; printf("%s", name);
                    color_switch_white; puts("Введите любой символ чтобы продолжить");
                    wait(); clear;
                    return 1;
                }
            } else {
                printf("Неверный пароль, попробуйте снова\n"); puts("Введите любой символ чтобы продолжить");
                wait(); clear; continue;
            }
        }
    }
}
