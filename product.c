#include "product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

struct product{
    int id;
    const char *nome;
    int preco;
    int stock;
};


int get_id(PRODUCT p){
    return p->id;
}

const char *get_nome(PRODUCT p){
    return strdup(p->nome);
}

int get_preco(PRODUCT p){
    return p->preco;
}

int get_stock(PRODUCT p){
    return p->stock;
}

void set_id(PRODUCT p, int id){
    p->id = id;
}

void set_nome(PRODUCT p, const char *nome){
    p->nome = strdup(nome);
}

void set_preco(PRODUCT p, int preco){
    p->preco = preco;
}

void set_stock(PRODUCT p, int stock){
    p->stock = stock;
}

PRODUCT build_product(char *line){
    char *idC,*nome,*precoC,*stockC;

    strsep(&line, " \n");

    if(!line) return NULL;
    idC = strdup(strsep(&line, " \n"));
    int id = atoi(idC);
    if(id<0) {
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL;
    nome = strdup(strsep(&line, " \n"));
    if(strlen(nome)==0) return NULL;


    if(!line) return NULL;
    precoC = strdup(strsep(&line, " \n"));
    int preco = atoi(precoC);
    if(preco<0) {
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL;
    stockC = strdup(strsep(&line, " \n"));
    int stock = atoi(stockC);
    if(stock<0) {
        PRODUCT p = NULL;
        return p;
    }

    PRODUCT p = malloc(sizeof(struct product));

    p->id = id;
    p->nome = nome;
    p->preco = preco;
    p->stock = stock;

    perror("product built");
    

    return p;
}

