#include "helper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//This function will print the word from the starting byte. 
void print_word(char *file_name, int starting_byte) {
    FILE *fp = fopen(file_name, "r");
    fseek(fp, starting_byte, SEEK_SET);

    char buf[2] = {0, };

    while(0 == feof(fp)) {
        fread(buf, sizeof(char), 1, fp);  
        if(0 == strcmp(buf, "\n")) {
            break;
        }
        printf("%s", buf);             
        memset(buf, 0, 2);               
    }
    printf("\n");

    return;
}

//my is alpha function. This function will return if the character is alphabet for not.
int is_alpha(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch < 'Z')) {
        return 1;
    }
    return 0;
}

//This is a function that compares if it's both alpha.
//Assuming that character is alpha it will compare if it's upper case or not.  
int is_upper(char ch) {
    if((ch >= 'A' && ch < 'Z')) {
        return 1;
    }
    return 0;
}