#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "addFilm.h"
#include "authorization.h"
#include "catalog.h"
#include "favorites.h"
#include "registration.h"
#include "userInterface.h"
#include "functions.h" // Кидайте туда полезные штуки которые не вписываются в другие либы

void MishaCheck() {
    start();
}


void VasyaCheck(){
    FILE *films = fopen("../films.txt", "r");
    list whole = scan(films);
    listprint(whole);
    fclose(films);
    scanf(" ");
    //Здесь заканчивается создание списка фильмов
}

void SvetaCheck(){

}

int main()
{
    system("chcp 65001"); system("cls"); // Переключает консоль на русскую кодировку и очищает её,
    // не убирайте 1 строку из мейна
    //MishaCheck();

    int is_admin = start();
    int catalog_choice = check_if_admin(is_admin);

    return 0;
    /*
    system("chcp 65001"); system("cls");

    VasyaCheck();


    return 0;
    */
    /*char input_str[25];
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
    */


}
