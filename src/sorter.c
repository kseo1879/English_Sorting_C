#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helper/alpha.h"
#include "helper/num.h"

/** 
 * This main function will first of all check for the validity of the command line input and
 * will assign to a each appropariate function that is defined in the helper forder under src. 
 */
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
        if(0 != strcmp(argv[3], "-alph") && 0 != strcmp(argv[3], "-num")) {
            perror("It is not either numerical or alphabetical representation\n");
            return -1;
        }
    }
    
    //Now we know that there is no error with the command line input, we need to check if the option is 
    //alphabetical representation. We use functions declared at helper/alpha.h
    if(3 == argc) {
        //This by default it means that it should compare by alphabetical representation
        alph_printer(argv);
        return 0;
    } else if(0 == strcmp(argv[3], "-alph")) { 
        // This means that is should also be written in alphabetical representation. 
        alph_printer(argv);
        return 0;
    } else { 
        //Here it means that the file is should compare in the numerical representation.
        num_printer(argv);
        return 0;
    }

    return 0;
}
