#include "alpha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alph_printer(char **argv) {
    //Here argv would be the same as the user commandline input. 
    if(0 == strcmp(argv[2], "-a")) {
        //Than means it wants to sort the algorithm in the acending order.
        ascending(argv[1]);
    } else {
        //Else it's in decending order.
        descending(argv[1]);
    }
    return;
}

void ascending(char *file_name) {
    //First we define a file pointer
    FILE *f_lowest = fopen(file_name, "r");

    //This is the buffer to compare each of the character.   
    char buf[2] = {0, }; 

    while(1) {         
        fread(buf, sizeof(char), 1, f_lowest);
        printf("%s", buf);
        memset(buf, 0, 2);                       // Resetting buffer to null characters
        if(0 != feof(f_lowest)) { //This means its the end of the file. 
            break;
        }
    }


    fclose(f_lowest);
    return;
}

void descending(char *file_name) {

    return;
}