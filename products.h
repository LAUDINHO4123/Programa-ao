#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "product.h"

typedef struct products{
    PRODUCT product;
    struct products *next;
} *products;

products *new_products(char *path);

#endif