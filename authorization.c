#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "functions.h"
#include "registration.h"


int user_check(user_data user_data) {

}


int login() {
    user_data user_data;
    char input_str[25];
    for (;;) {
        color_switch_white; puts("Введите ваш логин:"); color_switch_green;
        scanf("%25s", input_str); fflush(stdin);
    }
}
