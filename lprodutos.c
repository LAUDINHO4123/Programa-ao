#include "ui.h"  
#include <stdio.h>

int main(int argc, char* agrv[]){
    int i = ui();  //user interface

    if(i==0) perror("ui error"); //ver se deu erro

    return 0;
}


