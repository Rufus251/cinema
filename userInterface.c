#include <stdio.h>
#include <windows.h>


#include "userInterface.h"
#include "favorites.h"
#include "catalog.h"
#include "addFilm.h"
#include "authorization.h"


user_data check_if_admin(int is_admin){

    if( is_admin == 0){
        puts("Введите 1, чтобы перейти в каталог\nВведите 2, чтобы перейти в избранное");
    }
    if( is_admin == 1){
        puts("Введите 3, чтобы перейти в добавление");
    }

}

void add_film(){

};