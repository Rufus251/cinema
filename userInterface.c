#include <stdio.h>
#include <windows.h>


#include "userInterface.h"
#include "favorites.h"
#include "catalog.h"
#include "addFilm.h"
#include "authorization.h"

#define skip fgets(temp, 27, USER_DATA)

int check_if_admin(int is_admin) {

    int check;
    while(1){
        system("cls");
        if (is_admin == 0) {
            puts("Введите 1, чтобы перейти в каталог\nВведите 2, чтобы перейти в избранное");
        }
        if (is_admin == 1) {
            puts("Введите 1, чтобы перейти в каталог\nВведите 2, чтобы перейти в избранное\nВведите 3, чтобы перейти в добавление");
        }

        scanf("%d", &check); fflush(stdin);
        if (check == 1 || check == 2 || (check == 3 && is_admin == 1)){
            break;
        }
    }
    return check;
}



void change_user_data(char login[27]) {
    user_sctruct user;
    strcpy(user.login, login);
    printf("%s", user.login);
    wait();
}