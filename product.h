#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct product *PRODUCT;

int get_id(PRODUCT p);
const char *get_nome(PRODUCT p);
int get_preco(PRODUCT p);
int get_stock(PRODUCT p);

void set_id(PRODUCT p, int id);
void set_nome(PRODUCT p, const char *nome);
void set_preco(PRODUCT p, int preco);
void set_stock(PRODUCT p, int stock);

PRODUCT build_product(char *line);

#endif