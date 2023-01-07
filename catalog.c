#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

typedef struct catalog {

    char name[50];
    int year;
    char country[50];
    char genre[50];
    int rating;

} catalog;

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

    // перебор загруженных элементов и вывод на консоль
    printf("%d people in the file stored\n\n", n);

    for (int k = 0; k<n; k++)
    {
        while ((i= getc(fp))!="\n")
        {
            *c = i;
            c++;
        }
        printf("%d %s %d %s %s %d\n", k + 1, (ptr + k)->name, (ptr + k)->year, (ptr + k)->country, (ptr + k)->genre, (ptr + k)->rating);
        c = 0;
    }

    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}
