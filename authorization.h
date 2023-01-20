#include "functions.h"
#include "registration.h"

#ifndef PROJECT_NUMBER_3_AUTHORIZATION_H
#define PROJECT_NUMBER_3_AUTHORIZATION_H


int start();
int user_login_check(char *str);
int login();
int user_pass_check(char str[27], char *login);

#endif //PROJECT_NUMBER_3_AUTHORIZATION_H