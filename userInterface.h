#ifndef PROJECT_NUMBER_3_USERINTERFACE_H
#define PROJECT_NUMBER_3_USERINTERFACE_H
#include "authorization.h"

typedef struct user_struct{
    char login[27];
    char password[27];
    char card[27];
}user_sctruct;

typedef struct user_list {
    int size;
    struct user_struct *head;
}user_list;

int check_if_admin(int user_data);
void add_film();
void change_user_data(char login[27]);

#endif //PROJECT_NUMBER_3_USERINTERFACE_H
