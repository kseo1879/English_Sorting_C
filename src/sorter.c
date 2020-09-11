#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    //Error Handling. Correct number of argument
    if(argc < 3 || argc > 4) {
        perror("You have a wrong number of argument\n");
        return -1;
    }

    //Error checking if the file exist. 
    FILE *f = fopen(argv[1], "r");
    if(NULL == f) {
        perror("File does not exist in the file path\n");
        return -1;
    } else {
        fclose(f);
    }
    
    //Error handling if the argument provided is correct
    if(0 != strcmp(argv[2], "-a") && 0 != strcmp(argv[2], "-d")) {
        perror("It is not either acending or desending option.\n");
        return -1;
    }

    //If there is Fourth argument provided
    if(argc == 4) {
        if( 0 != strcmp(argv[3], "-alph") && 0 != strcmp(argv[3], "-num")) {
            perror("It is not either numerical or alphabetical representation\n");
            return -1;
        }
    }
    
       

    return 0;
}
