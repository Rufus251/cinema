#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "functions.h"
#include "registration.h"


int user_check(user_data user_data) {
    FILE *fin = fopen("../users.txt", "r");
    char user_buf[19], password_buf[19];
    int n;
    fscanf(fin, "%d", &n);
    fgets(user_buf, 19, fin); fflush(stdin);
    for (int i = 0; i < n; i++) {
        fgets(user_buf, 19, fin); fflush(stdin);
        fgets(password_buf, 19, fin); fflush(stdin);
        printf("Логин: %sПароль: %s", user_buf, password_buf);

        if (strcmp(user_buf, user_data.login) || strcmp(password_buf, user_data.password)){
            printf("неНайдена учётная запись\n");
        }
        else{
            printf("Найдена учётная запись\n");
            return 1;
        }

        fgets(user_buf, 19, fin); fflush(stdin);
        fgets(user_buf, 19, fin); fflush(stdin);
        fgets(user_buf, 19, fin); fflush(stdin);
    }
    return 0;
}


int login() {
    user_data user;
    char input_str[20];
    char password_str[20];
    for (;;) {
        color_switch_white; puts("Введите ваш логин:"); color_switch_green;
        scanf("%19s", user.login); fflush(stdin);
        strcat(user.login, "\n");
        color_switch_white; puts("Введите ваш пароль:"); color_switch_green;
        scanf("%19s", user.password); fflush(stdin);
        strcat(user.password, "\n");
        user_check(user);
        //return user_check(user);
    }
}
