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
    char card[20]; //4111111111100031
    scanf("%s", card); fflush(stdin);
    printf("\n%d", another_check(card));
    wait();
}


void VasyaCheck(){
    FILE *films = fopen("../films.txt", "r");
    list whole = scan(films);
    print_list(whole);
    fclose(films);



    /*while (1) {
        printLeftRight(new -> prev -> card);
        printDitailedCurrent(new -> card);
        printLeftRight(new -> next -> card);
    }*/


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
    //return 0;

    int is_admin = start();
    int catalog_choice = check_if_admin(is_admin);

    return 0;
    /*
    system("chcp 65001"); system("cls");

    VasyaCheck();


    return 0;
    */
}
