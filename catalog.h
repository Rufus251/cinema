#ifndef PROJECT_NUMBER_3_CATALOG_H
#define PROJECT_NUMBER_3_CATALOG_H

#include <stdio.h>

typedef struct catalog {

    char name[100];
    int year;
    char country[100];
    char genre[100];
    float rating;
    struct catalog *next;
    struct catalog *prev;

} catalog;

typedef struct list {
    int size;
    catalog *head;
    catalog *tail;
} list;

extern void pushback(list *l, catalog *f);
extern list scan(FILE *in);
extern void filmprint(catalog f);
extern void listprint(list l);

#endif
