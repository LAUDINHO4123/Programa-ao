#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "products.h"
#include "product.h"

void print_menu(){
    printf("--------------------------------\n");
    printf("|Bem vindo ao sistema de stocks|\n");
    printf("|  -i insere um novo produto   |\n");
    printf("|       -r remove produto      |\n");
    printf("|      -g imprime produto      |\n");
    printf("| -p imprime todos os produtos |\n");
    printf("|           -h help            |\n");
    printf("|      -q sai do programa      |\n");
    printf("--------------------------------\n");
    
}


void print_product(PRODUCT p){
    int id,preco,stock;
    char *nome;

    id  = get_id(p);
    nome = get_nome(p);
    preco = get_preco(p);
    stock = get_stock(p);

    printf("|produto:%s, id:%i,preco:%i,quantidade em stock:%i\n|",nome,id,preco,stock);

}

void print_all(products ps){
    while(get_next(ps)!=NULL) {
        print_product(get_product(ps));
        ps=get_next(ps);
    }
}

int ui(){
    
    char buf[32];
    int i=0;

    products ps = create_products();

    print_menu();    

    while(fgets(buf, 32, stdin) && strncmp(buf,"-q",2)!=0){

        if(strncmp(buf,"-i",2)==0){

            printf("inserting product...\n");

            build_products(buf,&ps,i);

            perror("product inserted");
            i++;
        }

        if(strncmp(buf,"-r",2)==0){
            strsep(&buf, " \n");
            int id = atoi(buf);
            remove_products(id, &ps);
            i--;

            printf("product removed\n");
        }

        if(strncmp(buf,"-g",2)==0){
            strsep(&buf, " \n");
            int id = atoi(buf);
            printf("id:%i\n",id);

            print_product(search_product(id,ps));
        }

        if(strncmp(buf,"-p",2)==0) {
            print_all(ps);
        }

        if(strncmp(buf,"-h",2)==0){
            print_menu();
        }

   }

   return 1;
}