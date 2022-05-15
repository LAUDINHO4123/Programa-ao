#ifndef PRODUCT_H
#define PRODUCT_H

struct product{
    int id;
    char nome[16];
    int preco;
    int stock;
};

typedef struct product *PRODUCT;

PRODUCT *build_products(char *path);

#endif