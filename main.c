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
    print_list();
    scanf(" ");
    //Здесь заканчивается создание списка фильмов


    return 0;
}
