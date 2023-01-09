#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "functions.h"
#include "registration.h"

#define skip fgets(temp, 27, USER_DATA)

void start();
int user_check(char *str);
int login();

void start() {
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
}


int user_login_check(char str[27]) {
    FILE *USER_DATA = fopen("../users.txt", "r");
    char temp[27]; strcat(str, "\n");
    while (fgets(temp, 27, USER_DATA) != NULL) { //login
        if (strcmp(temp, str) == 0) {
            skip; skip;
            fgets(temp, 27, USER_DATA);
            if (strcmp(temp, "1\n") == 0) {
                fclose(USER_DATA); return 1; //admin user
            } else if (strcmp(temp, "0\n") == 0) {
                fclose(USER_DATA); return 0; //common user
            }
        } else {
            skip; skip; skip; skip;
        }

    }
    fclose(USER_DATA); return -1; // cant find user login
}

int user_pass_check(char str[27]) {
    FILE *USER_DATA = fopen("../users.txt", "r");
    char temp[27]; strcat(str, "\n");
    while (fgets(temp, 27, USER_DATA) != NULL) {
        skip;
        if (strcmp(temp, str) == 0) {
            fclose(USER_DATA); return 1;
        } else {
            skip; skip; skip;
        }
    }
    fclose(USER_DATA); return -1;
}


int login() {
    char input_str[25];
    for (;;) {
        color_switch_white; puts("Введите логин:"); color_switch_green;
        scanf("%25s", input_str); fflush(stdin);
        int login_check = user_login_check(input_str);
        if (login_check == -1) {
            color_switch_white; puts("Пользователь не найден. Нажмите любую КНОПКУ БЛЯДЬ ЧТОБЫ ПОПРОБОВАТЬ СНОВА АААА НАУХУЙ!");
            wait(); clear;
            continue;
        } else if (login_check == 0 || login_check == 1) {
            color_switch_white; printf("Введите пароль:\n"); color_switch_green;
            scanf("%25s", input_str); fflush(stdin); color_switch_white;
            int pass_check = user_pass_check(input_str);
            if (pass_check == 1) {
                //user
                if (login_check == 0) {
                    color_switch_white; printf("Здарова "); color_switch_red; printf("%s\n", input_str);
                    color_switch_white; puts("Нажми любую хуйню чтобы продолжить");
                    wait(); clear;
                    return 0;
                }
                //admin
                if (login_check == 1) {
                    color_switch_white; printf("Здарова админ "); color_switch_red; printf("%s\n", input_str);
                    color_switch_white; puts("Нажми любую хуйню чтобы продолжить");
                    wait(); clear;
                    return 1;
                }
            } else {
                printf("Неверный пароль"); wait();
                puts("Введите любую хуйню чтобы продолжить");
                clear; continue;
            }
        }
    }
}
