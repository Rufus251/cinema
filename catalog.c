#include "catalog.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushback(list *l, catalog *c) {
    if (l->size > 0) {
        c->next = l->tail;
        c->prev = l->head;
        l->head->prev = c;
        l->tail->next = c;
        l->tail = c;
        l->size++;
    } else {
        l->head = c;
        l->tail = c;
        c->next = c;
        c->prev = c;
        l->size++;
    }
}

list scan(FILE *in){
    list l; l.size = 0; l.head = NULL; l.tail = NULL;

    char temp[100];
    while (fgets(temp, 100, in) != NULL) {

        catalog *c = (catalog *)malloc(sizeof(catalog));
        strcpy(c->name, temp);

        fgets(temp, 100, in);
        c->year = atoi(temp);

        fgets(temp, 100, in);
        strcpy(c->country, temp);

        fgets(temp, 100, in);
        strcpy(c->genre, temp);

        fgets(temp, 100, in);
        c->rating = atof(temp);

        pushback(&l, c);
    }
    return l;
}

void filmprint(catalog c) {
    printf("%s%d\n%s%s%0.1f\n\n", c.name, c.year, c.country, c.genre, c.rating);
}

void listprint(list l) {
    catalog *current = l.head;
    int i = 0;
    while (i < l.size) {
        filmprint(*current);
        current = current->next;
        i++;
    }
}