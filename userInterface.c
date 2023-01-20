#include <stdio.h>
#include "userInterface.h"
#include "authorization.h"


int check_if_admin(int is_admin) {
    int check;
    if (is_admin == 0) {
        puts("Введите 1, чтобы перейти в каталог\nВведите 2, чтобы перейти в избранное");
    }
    if (is_admin == 1) {
        puts("Введите 1, чтобы перейти в каталог\nВведите 2, чтобы перейти в избранное\nВведите 3, чтобы перейти в добавление");
    }
    while(check != 1 || check != 2 || (check != 3 && is_admin == 1)){
        scanf("%d", &check); fflush(stdin);
    }
    return check;
}

