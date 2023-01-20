// Created by Admin on 11.12.2022.
#include "authorization.h"
#include "functions.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>


//доделать регулярные выражения (спец символы), карта

int card_check(char card[17]) {
    if (luhn(card) == 1 && card_check(card) == 1) return 1;
    else return 0;
}

int luhn(char card[17]) {
    int digit = 0, check_digit = 0;
    for (int i = 15; i >= 0; --i) {
        digit = card[i] - 48;
        if (i % 2 == 0) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        check_digit += digit;
    }
    if (check_digit % 10 != 0) {
        return 0;
    } else return 1;
}

void user_data_to_file(user_data user_data) {
    FILE *USER_DATA = fopen("../users.txt", "a");
    fprintf(USER_DATA, "%s\n", user_data.login);
    fprintf(USER_DATA, "%s\n", user_data.password);
    fprintf(USER_DATA, "%d\n", user_data.favorites_size);
    fprintf(USER_DATA, "%d\n\n", user_data.is_admin);
    fflush(USER_DATA);
}

void registration() {
    user_data user_data; char input_str[25], valid_check[25];
    for (;;) {
        color_switch_white; puts("Введите логин (От 3 до 20 символов):"); color_switch_green;

        scanf("%25s", input_str); fflush(stdin);
        if (strlen(input_str) < 3 || strlen(input_str) > 20) {
            color_switch_white;
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
                puts("Несовпадающие пароли, введите пароли еще раз");
                continue;
            }
        }

    }
    for (;;) {
        color_switch_white; puts("Теперь отдай мне свою банковкскую карту (Ровно 16 символов):"); color_switch_green;
        char input_str[17];
        scanf("%20s", input_str); fflush(stdin);
        if (strlen(input_str) != 16) {
            color_switch_white;
            puts("Некорректный номер карты, попробуйте снова");
            continue;
        } else {
            for (int i = 0; i < 16; ++i) {
                printf("%c", input_str[i]);
                user_data.card[i] = input_str[i];
            }
            break;
        }
    }
    clear;
    color_switch_white; puts("Ваши данные:"); printf("Логин: ");
    color_switch_red; printf("%s\n", user_data.login);
    color_switch_white; printf("Пароль: ");
    color_switch_red; printf("%s\n", user_data.password);
    color_switch_white; printf("Краденая карта: ");
    color_switch_red; printf("%s\n", user_data.card);
    color_switch_white; puts("Подтвердить регистрацию? y / n");

    for (;;) {
        scanf("%2s", input_str); fflush(stdin);
        to_lower(input_str);

        if (strcmp(input_str, "y") == 0) {
            user_data.favorites_size = 0;
            user_data.is_admin = 0;
            user_data_to_file(user_data);
            system("cls"); puts("Регистрация успешно завершена, введите любой символ чтобы продолжить");
            start();

        } else if (strcmp(input_str, "n") == 0) {
            system("cls"); puts("Регистрация отменена, введите любой символ чтобы продолжить");
            wait(); clear; start();
        } else {
            puts("Некорректный ответ, попробуйте снова");
        }
    }
}

