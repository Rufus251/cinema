//
// Created by Admin on 11.12.2022.
//

#ifndef PROJECT_NUMBER_3_CATALOG_H
#define PROJECT_NUMBER_3_CATALOG_H


typedef struct catalog {

    char name[50];
    int year;
    char country[50];
    char genre[50];
    int rating;

} catalog;

int load();


#endif //PROJECT_NUMBER_3_CATALOG_H
