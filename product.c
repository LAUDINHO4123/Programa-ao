#include "product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

PRODUCT build_product(char *line){
    char *idC,*nome,*precoC,*stockC;

    if(!line) return NULL;
    idC = strdup(strsep(&line, ";\n"));
    int id = valid_string(idC);
    if(id<0) {
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL;
    nome = strdup(strsep(&line, ";\n"));
    if(strlen(nome)==0) return NULL;


    if(!line) return NULL;
    precoC = strdup(strsep(&line, ";\n"));
    int preco = valid_string(precoC);
    if(preco<0) {
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL;
    stockC = strdup(strsep(&line, ";\n"));
    int stock = valid_string(stockC);
    if(stock<0) {
        PRODUCT p = NULL;
        return p;
    }

    PRODUCT p = malloc(sizeof(struct product));

    p->id = id;
    p->nome = strdup(nome);
    p->preco = preco;
    p->stock = stock;
    

    return p;
}

PRODUCT *build_products(char *path) {

    int file_fd = open(path,O_RDWR);

    int arr_fst_len = 40;

    char buf[4096];

    PRODUCT *array = malloc (arr_fst_len * sizeof(PRODUCT));

    int read = 0,
            len_arr = arr_fst_len;

    fgets(buf, 20, file_fd);

    while (read_ln(file_fd,buf,4096)) {

        if (read == len_arr - 2) {

            len_arr += arr_fst_len;

            array = realloc (array, len_arr * sizeof(PRODUCT));
        }

        array[read] = build_product(buf);

        if (array[read] != NULL)

            read++;
    }

    array[read] = NULL;

    close(file_fd);

    return array;
}