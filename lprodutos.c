#include "ui.h"
#include <stdio.h>

int main(int argc, char* agrv[]){
    int i = ui();

    if(i==0) perror("ui error");

    return 0;
}