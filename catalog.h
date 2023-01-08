//
// Created by Admin on 11.12.2022.
//

#ifndef PROJECT_NUMBER_3_CATALOG_H
#define PROJECT_NUMBER_3_CATALOG_H


#include <stdio.h>

typedef struct catalog {

    char name[50];
    int year;
    char country[50];
    char genre[50];
    float rating;
    struct catalog *next;
    struct catalog *prev;

} catalog;

typedef struct list {
    int size;
    catalog *head;
    catalog *tail;
} list;

extern void push(list *l, catalog *f);
extern void pushback(list *l, catalog *f);
extern void insert(list *l, catalog *f, int n);
extern catalog filmdelete(list *l, int n);
extern catalog pop(list *l);
extern void move(list *a, list *b);
extern list scan(FILE *in);
extern void filmprint(catalog f);
extern void filmfprint(FILE *out, catalog f);
extern void listprint(list l);
extern void listfprint(FILE *out, list l);

//int load();


#endif //PROJECT_NUMBER_3_CATALOG_H
