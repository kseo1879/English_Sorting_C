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
    //First we define a file pointer fp. 
    FILE *fp = fopen(file_name, "r");

    //This is the limited buffer to store the character and it's null turminator.  
    char buf[2] = {0, }; 

    //Current lowest starting location
    int lowest_byte = 0;

    //The latest lowest byte
    int last_lowest_byte = -1;

    //The location of the file cursur. 
    int cursur_byte = 0;

    //Retrun value of strcmp
    int r_val = 0;

    // int tmp_val = -1;

    //This loop will continue untill the lowest is is the same as the cursur's value. 
    while(1) {

        cursur_byte = ftell(fp);
        if(0 == strcmp(buf, "\n") || 0 == ftell(fp)) {
            if(lowest_byte == cursur_byte) {
                //This means that cursur and lowest are at the same location so we should just skip it. 
                fread(buf, sizeof(char), 1, fp);
                continue;
            }
            //File will read throught the whole file from the start of the word,
            //and it will record the lowest value
            r_val = my_strcmp(file_name, cursur_byte, lowest_byte);
            
            //We need to see if there is any previous record of the last lowest byte
            if(-1 != last_lowest_byte) { //This means it has read the whole file
                if(0 > r_val && 0 < my_strcmp(file_name, cursur_byte, last_lowest_byte)) {
                    lowest_byte = cursur_byte;
                }
            } else { //This means that it hasn't read the whole file. 
                if(0 > r_val) {
                    lowest_byte = cursur_byte;
                }
            }
        }
        //Reading the file and save it to the limited bufer. 
        fread(buf, sizeof(char), 1, fp);


        if(0 != feof(fp)) { //It means that it is the end of the file. 
            printf("%d\n", lowest_byte);
            if(last_lowest_byte == lowest_byte) {
                break;
            } else {
                last_lowest_byte = lowest_byte;
                lowest_byte = 0;
                rewind(fp);
            }
        }

        
        // fread(buf, sizeof(char), 1, fp);

        // if(0 == strcmp(buf, "\n")){
            
        //     // if(cursur_byte == lowest_byte) { //IF it's the lowest byte it should just continue;
        //     //     continue;
        //     // } 
        //     cursur_byte = ftell(fp);
        //     //my_strcmp will return 1 if cursur_byte is bigger than the lowest
        //     //It will return -1 if its lower than the lowest byte
        //     //0 if it's the same
        //     r_val = my_strcmp(file_name, cursur_byte, lowest_byte);
            
        //     if(-1 != last_lowest_byte) {
        //         tmp_val = my_strcmp(file_name, lowest_byte, last_lowest_byte);
        //         if(0 < tmp_val && 0 > r_val) {
        //             lowest_byte = cursur_byte; 
        //         }
        //     } else {//First time updating the last_lowest byte
        //         if(0 > r_val) {//This means that the lowest byte should be updated. 
        //             lowest_byte = cursur_byte;      
        //         }
        //     }
        // }

        // memset(buf, 0, 2);                       // Resetting buffer to null characters
        //  //This means its the end of the file. 
        

        // if(0 != feof(fp)) {
        //     printf("%d\n", lowest_byte);
        //     //Need to check if it has to finish executing or not. 
        //     if(0 < my_strcmp(file_name, lowest_byte, last_lowest_byte)) {
        //         break;
        //     } else {
        //         tmp_val = -1;
        //         last_lowest_byte = lowest_byte;
        //         lowest_byte = 0;
        //         rewind(fp);
        //     }
        // }
    }


    fclose(fp);
    return;
}

void descending(char *file_name) {
    
    return;
}

/**
 * @param
 * (char *file_name, int cursur, int lowest_byte)
 * It will return positive if curusr has apha-numerically bigger value than it will return positive. 
 * If not it will return negative
 * It it's the same it will return 0;
 */
int my_strcmp(char *file_name, int cursur_byte, int lowest_byte) {
    char cursur[2] = {0, };
    char lowest[2] = {0, };

    FILE *fp = fopen(file_name, "r");
    // fseek(fp, cursur_byte, SEEK_SET);

    while(1) {
        //This is to point the file pinter to each of the word and compare them accordingly. 
        fseek(fp, cursur_byte, SEEK_SET); //First we need to read the character from the file
        fread(cursur, sizeof(char), 1, fp);

        if(0 != feof(fp)) { //If cursur is at the end of the file. 
            fseek(fp, lowest_byte, SEEK_SET); 
            fread(lowest, sizeof(char), 1, fp); 
            fclose(fp);
            if(0 == strcmp(lowest, "\n")) { //This means that they both are the same word. 
                return 0;
            } else { // This means that the cursur is end but lowest did not end. 
                return -1;
            }
        }

        fseek(fp, lowest_byte, SEEK_SET); //Now We need to read the lowest byte. 
        fread(lowest, sizeof(char), 1, fp);  

        if(0 != feof(fp)) { //If cursur is at the end of the file. 
            fseek(fp, cursur_byte, SEEK_SET); 
            fread(cursur, sizeof(char), 1, fp);
            fclose(fp); 
            if(0 == strcmp(cursur, "\n")) { //This means that they both are the same word. 
                return 0;
            } else {
                return 1;
            }
        }

        //First we need to check if it's the end of the word with out it being feof;
        if(0 == strcmp(cursur, "\n") && 0 == strcmp(lowest, "\n")) {
            fclose(fp);
            return 0; //This means that they are both the same word
        } else if(0 == strcmp(cursur, "\n")) {
            fclose(fp);
            //This means that only cursur is the end of the line therefore it has lower value
            return -1;
        } else if(0 == strcmp(lowest, "\n")) {
            fclose(fp);
            return 1; //This means that the lowest has bigger value. 
        } 

        //Now we need to campare character by character.
        if(0 < strcmp(cursur, lowest)) {
            //This means that the cursur is bigger than the lowest. 
            fclose(fp);
            return 1;
        } else if(0 > strcmp(cursur, lowest)) {
            //This means that that the cursur is lower than the lowest
            fclose(fp);
            return -1;
        } else {
            //This means they have the same value
            cursur_byte++;
            lowest_byte++;
        }
    }


    fclose(fp);
    return 0;
}

//This function will print the word from the starting byte. 
void print_word(char *file_name, int starting_byte) {

    return;
}