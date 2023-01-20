#include "userInterface.h"
#include "catalog.h"
#include "addFilm.h"
#include "authorization.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



list scan(FILE *in){
    list l; l.size = 0; l.head = NULL; l.tail = NULL;

    char temp[100];
    while (fgets(temp, 100, in) != NULL) {

        catalog *c = (catalog *)malloc(sizeof(catalog));
        temp[strcspn(temp, "\n")] = 0;
        strcpy(c->name, temp);

        fgets(temp, 100, in);
        temp[strcspn(temp, "\n")] = 0;
        c->year = atoi(temp);

        fgets(temp, 100, in);
        temp[strcspn(temp, "\n")] = 0;
        strcpy(c->country, temp);

        fgets(temp, 100, in);
        temp[strcspn(temp, "\n")] = 0;
        strcpy(c->genre, temp);

        fgets(temp, 100, in);
        temp[strcspn(temp, "\n")] = 0;
        c->rating = atof(temp);

        pushback(&l, c);
    }
    return l;
}


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


/*void filmprint(catalog *c) {
    printf("%s%d\n%s%s%0.1f\n\n", c->name, c->year, c->country, c->genre, c->rating);
}*/

void print_list() {
    FILE *films = fopen("../films.txt", "r");
    list whole = scan(films);
    catalog *current = whole.head;
    int i = 0;
    while (i < whole.size) {
        print_film(current);
        current = current->next;
        i++;
    }
    fclose(films);
}

void print_film(catalog *c) {
    printf("                                 ┌──────────────────────────────────────────────┐\n");
    printf("┌────────────────────────────────┘                                              └────────────────────────────────┐\n");
    printf("                                                  %s\n", c->name);
    printf("    %s                                                                           %s", c->prev->name, c->next->name);
    printf("                                                                  %s      \n", c->genre);
    printf("    %s                                                                           %s", c->prev->genre, c->next->genre);
    printf("                                                                  %s      \n", c->country);
    printf("    %s                                                                           %s\n", c->prev->country, c->next->country);
    printf("                                                      %.1f+                     \n", c->rating);
    printf("    %.1f+                                                                                      %.1f+ \n", c->prev->rating, c->next->rating);
    printf("                                                    %d                     \n", c->year);
    printf("└────────────────────────────────┐                                              ┌────────────────────────────────┘\n");
    printf("                                 └──────────────────────────────────────────────┘\n");
}
