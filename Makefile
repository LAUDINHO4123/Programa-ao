all: lprodutos

lprodutos: lprodutos


obj/lprodutos.o: lprodutos.c
	gcc -Wall -g -c lprodutos.c -o obj/lprodutos.o

obj/product.o: product.c
	gcc -Wall -g -c product.c -o obj/product.o

obj/products.o: products.c
	gcc -Wall -g -c products.c -o obj/products.o

obj/ui.o: ui.c
	gcc -Wall -g -c ui.c -o obj/ui.o

lprodutos: obj/lprodutos.o obj/product.o obj/products.o obj/ui.o
	gcc -g obj/lprodutos.o obj/product.o obj/products.o obj/ui.o -o lprodutos


clean:
	rm obj/* lprodutos