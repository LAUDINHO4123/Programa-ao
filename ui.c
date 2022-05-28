#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "products.h"
#include "product.h"

void print_menu(){
    printf("--------------------------------\n");  //  so da printf
    printf("|Bem vindo ao sistema de stocks|\n");
    printf("|  -i insere um novo produto   |\n");
    printf("|       -r remove produto      |\n");
    printf("|      -g imprime produto      |\n");
    printf("| -p imprime todos os produtos |\n");
    printf("|           -h help            |\n");
    printf("|      -q sai do programa      |\n");
    printf("--------------------------------\n");
    
}


void print_product(PRODUCT p){   //imprime um produto

    if(!p) {  //  se n existir o produto ele imprimi que n foi encontrado o produto
        printf("product not found\n");  
    }

    else{   // se for encontrado imprime
        int id,preco,stock;
        char *nome;

        id  = get_id(p);
        nome = get_nome(p);
        preco = get_preco(p);
        stock = get_stock(p);

        printf("|produto: %s, id: %i, preco: %i, quantidade em stock:%i|\n",nome,id,preco,stock);
    }
} 

void print_all(products ps, int i){ // imprime os produtos todos
    while(get_next(ps)!=NULL && i>0) {  //enquanto existir um produto diferente do vazio e o numero do produto ser maior que zero imprime um produto
        print_product(get_product(ps));
        ps=get_next(ps); //avançar na lista de produtos
        i--;
    }
    print_product(get_product(ps));
}

int ui(){          
    
    char buf[32];   // o que eu escrevo na consola user input
    int i=0;        //  i=numero de produtos atuais

    products ps = create_products();  //  cria a lista vazia 

    print_menu();//  imprime o menu que esta no inicio    

    while(fgets(buf, 32, stdin) && strncmp(buf,"-q",2)!=0){  //  ciclo infinito ate fazer -q na consola e vai lendo os comandos que o utilizador 

        if(strncmp(buf,"-i",2)==0){  // insert na lista de produtos

            printf("inserting product...\n"); 

            build_products(buf,&ps,i); 

            perror("product inserted");
            i++;
        }

        if(strncmp(buf,"-r",2)==0){ // remove o produto

            printf("removing product...\n");

            char * token = strtok(buf, " "); // ta a separar a string, o -r do numero 
            token = strtok(NULL, " \n");  //  guarda a string separada


            int id = atoi(token); 
            
            remove_products(id, &ps,i);  
            i--; 

            perror("product removed");
        }

        if(strncmp(buf,"-g",2)==0){ // imprime um produto
            printf("searching product...\n");

            char * token = strtok(buf, " "); 
            token = strtok(NULL, " \n");


            int id = atoi(token);

            print_product(search_product(id,ps,i)); // imprime o produto e dentro esta a procurar o produto
        }

        if(strncmp(buf,"-p",2)==0) {  // imprime todos os produtos
            print_all(ps,i);
        }

        if(strncmp(buf,"-h",2)==0){ // um help que imprime o menu caso tenha esquecido dos comandos
            print_menu();
        }

   }

   return 1;
}
