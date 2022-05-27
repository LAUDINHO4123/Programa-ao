#include "product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "products.h"

products new_products(PRODUCT p){
    products ps = malloc(sizeof(struct products));

    ps->product = p;
    ps->next=NULL;

    return ps;
}

void insertProduct (products* l, PRODUCT x) {
    products list = *l;
    products new = malloc(sizeof(struct products));
    new->product = x;
    new->next = NULL;
    if(get_id(list->product) > get_id(x)) {
        *l = new;
        new->next = list;
    }
    else {
        while(list->next) {
            products next = list->next;
            if(get_id(next->product) > get_id(x)) {
                list->next = new;
                new->next = next;
                break;
            }
            list = list->next;
        }
        list->next = new;
    }
}

int remove_products(int id, products* ps){
    products p = *ps,b;

    while(get_id(p->next->product)!=id && p->next->next){
        p=p->next;
    }
    if(!p->next->next) return -1;
    if(p){
        b=p->next;
        p->next=b->next;
        return 1;
    }
}

PRODUCT search_product(int id, products ps){

    while (get_id(ps->product)<id && ps->next != NULL) ps=ps->next;

    if(get_id(ps->product==id)) return ps->product;
    

    return NULL;
}

void build_products(char *line, products* ps){
    products products = *ps;
    PRODUCT p = build_product(line);
    if(products==NULL){
        products = new_products(p);
    }

    else insertProduct(ps, p);

}