#include "product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "products.h"


PRODUCT get_product(products ps){
    return ps->product;
}

products get_next(products ps){
    return ps->next;
}

void set_product(products ps,PRODUCT p){
    ps->product = p;
}

void set_next(products ps,products next){
    ps->next = next;
}

products create_products(){
    products new = malloc(sizeof(struct products));

    return new;
}

products new_products(PRODUCT p){
    products ps = create_products();

    ps->product = p;
    ps->next=NULL;

    return ps;
}

int insertProduct (products* l, PRODUCT x,int i) {
    products list = *l;

    if(i==0) {
        list -> product = x;
        list -> next = NULL;

        return 1;
    }

    products new = malloc(sizeof(struct products));
    new->product = x;
    new->next = NULL;

    
    if(get_id(list->product) > get_id(x)) {
        *l = new;
        new->next = list;

        return 1;
    }
    
    while(list->next) {
        products next = list->next;
        if(get_id(next->product) > get_id(x)) {
            list->next = new;
            new->next = next;
            return 1;
        }
        list = list->next;
    }
    list->next = new;

    return 0;
    
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

    return 0;
}

PRODUCT search_product(int id, products ps){

    while (get_id(ps->product)<id && ps->next != NULL) ps=ps->next;

    if(get_id(ps->product)==id) return ps->product;
    

    return NULL;
}

void build_products(char *line, products* ps,int i){
    PRODUCT p = build_product(line);
    
    insertProduct(ps, p,i);

}