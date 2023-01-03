// Created by Admin on 11.12.2022.
#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "functions.h"

//доделать проверка есть ли такой пользователь в базе, регулярные выражения (спец символы), карта

typedef struct user_data {

    char login[20];
    char password[20];
    char card[16];
    int favorites_size;
    int is_admin;

} user_data;

void user_data_to_file(user_data user_data) {
    FILE *USER_DATA = fopen("../users.txt", "a");
    fprintf(USER_DATA, "%s\n", user_data.login);
    fprintf(USER_DATA, "%s\n", user_data.password);
    fprintf(USER_DATA, "%d\n", user_data.favorites_size);
    fprintf(USER_DATA, "%d\n\n", user_data.is_admin);
}

void registration() {
    user_data user_data; char input_str[25], valid_check[25];
    for (;;) {
        color_switch_white; puts("Введите логин (От 3 до 20 символов):"); color_switch_green;

        scanf("%25s", input_str); fflush(stdin);
        if (strlen(input_str) < 3 || strlen(input_str) > 20) {
            puts("Некорректный логин, попробуйте снова");
            continue;
        } else {
            for (int i = 0; i < 20; ++i) {
                user_data.login[i] = input_str[i];
            }
            break;
        }
    }

    for (;;) {
        color_switch_white; puts("Введите пароль (От 6 до 20 символов):"); color_switch_green;

        scanf("%25s", input_str); fflush(stdin);
        if (strlen(input_str) < 6 || strlen(input_str) > 20) {
            puts("Некорректный пароль, попробуйте снова");
            continue;
        } else {
            color_switch_white; puts("Подтвердите пароль:"); color_switch_green;
            scanf("%25s", valid_check); fflush(stdin);
            if (strcmp(valid_check, input_str) == 0) {
                for (int i = 0; i < 20; ++i) {
                    user_data.password[i] = input_str[i];
                }
                break;
            } else {
                color_switch_white;
                puts("Несовпадающие пароли, попробуйте снова");
                continue;
            }
        }

    }
    system("cls");
    color_switch_white; puts("Ваши данные:"); printf("Логин: ");
    color_switch_red; printf("%s\n", user_data.login);
    color_switch_white; printf("Пароль: ");
    color_switch_red; printf("%s\n", user_data.password);
    color_switch_white; puts("Подтвердить регистрацию? y / n");

    for (;;) {
        scanf("%2s", input_str); fflush(stdin);
        to_lower(input_str);

        if (strcmp(input_str, "y") == 0) {
            user_data.favorites_size = 0;
            user_data.is_admin = 0;
            user_data_to_file(user_data);
            system("cls"); puts("Регистрация успешно завершена, введите любой символ чтобы продолжить");
            return;

        } else if (strcmp(input_str, "n") == 0) {
            system("cls"); puts("Регистрация отменена, введите любой символ чтобы продолжить");
            scanf("%c", input_str);
            return;
        } else {
            puts("Некорректный ответ, попробуйте снова");

        }
    }
}

