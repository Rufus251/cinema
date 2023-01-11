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

void MishaCheck(){

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
    system("chcp 65001"); system("cls");
    login();




    return 0;
}
