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

PRODUCT build_product(char *line){ // constroi um produto dado uma linha
    char *idC,*nome,*precoC,*stockC;

    strsep(&line, " \n"); // tira o comando inicial da string,separa a flag do comando da linha de produto

    if(!line) return NULL; //ver se deu algum problema
    idC = strdup(strsep(&line, " \n"));// mete a string id no idc e transforma em inteiro
    int id = atoi(idC);
    if(id<0) { 
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL; // ve se da erro e mete o nome la
    nome = strdup(strsep(&line, " \n")); 
    if(strlen(nome)==0) return NULL;


    if(!line) return NULL;
    precoC = strdup(strsep(&line, " \n")); //mete a string id no precoc e transforma em inteiro
    int preco = atoi(precoC);
    if(preco<0) {
        PRODUCT p = NULL;
        return p;
    }


    if(!line) return NULL;
    stockC = strdup(strsep(&line, " \n")); // mete a string id no stockc e transforma em inteiro
    int stock = atoi(stockC);
    if(stock<0) {
        PRODUCT p = NULL;
        return p;
    }

    PRODUCT p = malloc(sizeof(struct product)); // aloca a memoria para o produto e coloca os dados na struct

    p->id = id;
    p->nome = nome;
    p->preco = preco;
    p->stock = stock;

    perror("product built");
    

    return p;
}

