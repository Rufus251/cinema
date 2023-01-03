//
// Created by Admin on 11.12.2022.
//
#ifndef PROJECT_NUMBER_3_REGISTRATION_H
#define PROJECT_NUMBER_3_REGISTRATION_H

typedef struct user_data {
    char login[20];
    char password[20];
    char card[16];
    int favorites_size;
    int is_admin;
} user_data;

void registration();
void user_data_to_file(user_data user_data);
void user_data_from_file(user_data user_data);

#endif //PROJECT_NUMBER_3_REGISTRATION_H
