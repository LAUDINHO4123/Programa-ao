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

products create_products(){ //cria uma lista de produtos vazia
    products new = malloc(sizeof(struct products)); //aloca o espaço

    return new;
}

products new_products(PRODUCT p){ //cria uma lista de produtos so com um produto
    products ps = create_products();

    ps->product = p; 
    ps->next=NULL;

    return ps;
}

int insertProduct (products* l, PRODUCT x,int i) { // insere um produto ordenado,ver se e maior se n for avança e coloca la
    products list = *l;

    if(i==0) { //insere um produto se a lista tiver vazia
        list -> product = x;
        list -> next = NULL;

        return 1;
    }

    products new = malloc(sizeof(struct products)); //aloca espaço,cria uma lista so com um produto e vai ser inserido na ordem dele
    new->product = x;
    new->next = NULL;

    
    if(get_id(list->product) > get_id(x)) { //vai ser inserido na ordem dele,ta a procura da ordem
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

int remove_products(int id, products* ps, int i){ //remover um produto
    products p = *ps,b;

    if(get_id(get_product(p))==id){ 
        if(i==1) p = NULL;
        if(i==2) {
            p=p->next;
            p->next = NULL;
            
            return 1;
        }
        b=p->next;
        p->next=b->next;

        return 1;
    }

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

PRODUCT search_product(int id, products ps,int i){ //  procura um produto

    while (get_id(ps->product)<id && ps->next != NULL) ps=ps->next; //ta a avançar enquanto o indice for maior 

    if(get_id(ps->product)==id) return ps->product;  //ver se igual,se n for da return
    

    return NULL;
}

void build_products(char *line, products* ps,int i){ 
    PRODUCT p = build_product(line); //  constroi um produto dado a linha
    
    insertProduct(ps, p,i);//  insere o produto na lista

}
