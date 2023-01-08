#include "catalog.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(list *l, catalog *f) {
    if (l->size > 0) {
        f->next = l->head;
        f->prev = l->tail;
        l->head->prev = f;
        l->tail->next = f;
        l->head = f;
        l->size++;
    } else {
        l->head = f;
        l->tail = f;
        f->next = f;
        f->prev = f;
        l->size++;
    }
}

//добавление фильма в конец
void pushback(list *l, catalog *f) {
    if (l->size > 0) {
        f->next = l->tail;
        f->prev = l->head;
        l->head->prev = f;
        l->tail->next = f;
        l->tail = f;
        l->size++;
    } else {
        l->head = f;
        l->tail = f;
        f->next = f;
        f->prev = f;
        l->size++;
    }
}

//добавление фильма перед фильмом n
void insert(list *l, catalog *f, int n) {
    if (n == 0)
        push(l, f);
    else if (n > 0 && n <= l->size) {

        catalog *current = l->head;
        int i = 0;
        while (i < n - 1) {
            current = current->next;
            i++;
        }
        f->next = current->next;
        f->prev = current;
        current->next = f;
        l->size++;
    }
}

//удаление фильма n с возвратом
catalog filmdelete(list *l, int n) {
    catalog f;
    if (n < l->size && n > 0) {
        catalog *current = l->head;
        int i = 0;
        while (i < n - 1) {
            current = current->next;
            i++;
        }
        f = *current->next;
        catalog *temp = current->next->next;
        free(current->next);
        current->next = temp;
        current->next->prev = current;
        l->size--;
    } else if (n == 0) {
        f = *l->head;
        catalog *temp1 = l->head->next;
        catalog *temp2 = l->head->prev;
        free(l->head);
        l->head = temp1;
        l->head->prev = temp2;
        l->size--;
    }
    return f;
}

//удаление фильма с начала с возвратом
catalog pop(list *l) {
    catalog f;
    if (l->size < 1) {

    } else if (l->size == 1) {
        f = *l->head;
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    } else {
        f = filmdelete(l, 0);
    }
    return f;
}

//перемещение фильма из a в b
void move(list *a, list *b) {
    catalog *f = (catalog *)malloc(sizeof(catalog));
    *f = pop(a);
    push(b, f);
}

list scan(FILE *in){
    list l;
    l.size = 0;
    l.head = NULL;
    l.tail = NULL;

    char temp[100];
    while (fgets(temp, 100, in) != NULL) {

        catalog *f = (catalog *)malloc(sizeof(catalog));

        strcpy(f->name, temp);

        fgets(temp, 100, in);
        f->year = atoi(temp);

        fgets(temp, 100, in);
        strcpy(f->country, temp);

        fgets(temp, 100, in);
        strcpy(f->genre, temp);

        fgets(temp, 100, in);
        f->rating = atof(temp);

        pushback(&l, f);
    }
    return l;
}

void filmprint(catalog f) {
    printf("%s", f.name);
    printf("%d\n", f.year);
    printf("%s", f.country);
    printf("%s", f.genre);
    printf("%.1f\n", f.rating);
}

void filmfprint(FILE *out, catalog f) {
    fprintf(out, "%s", f.name);
    fprintf(out, "%d\n", f.year);
    fprintf(out, "%s", f.country);
    fprintf(out, "%s", f.genre);
    fprintf(out, "%.1f\n", f.rating);
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

void listfprint(FILE *out, list l) {
    catalog *current = l.head;
    int i = 0;
    while (i < l.size) {
        filmfprint(out, *current);
        current = current->next;
        i++;
    }
}


/*
int load(char * filename)
{
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;

    // выделяем память для количества данных
    int *pti = (int *)malloc(m);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
    }
    // считываем количество структур
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;

    // выделяем память для считанного массива структур
    struct catalog * ptr = (struct catalog *) malloc(n * sizeof(struct catalog));
    c = (char *)ptr;
    // после записи считываем посимвольно из файла

    while ((i= getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }

    // перебор загруженных элементов и вывод на консоль
    printf("%d people in the file stored\n\n", n);

    for (int k = 0; k<n; k++)
    {

        printf("%d %s %d %s %s %d\n", k + 1, (ptr + k)->name, (ptr + k)->year, (ptr + k)->country, (ptr + k)->genre, (ptr + k)->rating);
        c = 0;
    }

    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}*/

