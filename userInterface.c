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


void add_film(){
    FILE *FILMS = fopen("../films.txt", "r");
    char temp[100]; char str[100]; int flag = 0;
    printf("Введите фильм\n");
    SetConsoleCP(1251);
    gets(str); fflush(stdin);
    SetConsoleCP(866);
    while(fgets(temp, 100, FILMS) != NULL){
        if(strcmp(temp, str) == 0){
            flag = 1;

        }
        else (flag = 0);
    }

    if(flag == 1){
        printf("Фильм уже добавлен");
    }
    else{
        fclose(FILMS);

        FILE *FILM = fopen("../films.txt", "a");
        printf("Добавь меня полностью папочка\n");
        fprintf(FILM, "\n%s", str); fflush(stdin);
    }
    fclose(FILMS);
    wait();
};


void change_user_data(char login[27]) {
    user_sctruct user;
    strcpy(user.login, login);
    printf("%s", user.login);
    wait();
}