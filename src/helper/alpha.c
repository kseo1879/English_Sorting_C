#include "alpha.h"
#include "helper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    int lowest_byte = -1;

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
            
            
            //We need to see if there is any previous record of the last lowest byte
            if(-1 != last_lowest_byte) { //This means it has read the whole file
                if(0 < my_strcmp(file_name, cursur_byte, last_lowest_byte)) {
                    if(-1 == lowest_byte) {
                        lowest_byte = cursur_byte;
                    } else {
                        r_val = my_strcmp(file_name, cursur_byte, lowest_byte);
                        if(0 > r_val) {
                            lowest_byte = cursur_byte;
                        }
                    }   
                }
            } else { //This means that it hasn't read the whole file. 
                if(0 == cursur_byte) {
                    lowest_byte = 0;
                } else {
                    r_val = my_strcmp(file_name, cursur_byte, lowest_byte);
                    if(0 > r_val) {
                        lowest_byte = cursur_byte;
                    }
                }

    
            }
        }
        //Reading the file and save it to the limited bufer. 
        fread(buf, sizeof(char), 1, fp);


        if(0 != feof(fp)) { //It means that it is the end of the file. 
            if(-1 == lowest_byte || lowest_byte == last_lowest_byte) {
                break;
            } else {
                print_word(file_name, lowest_byte);
                last_lowest_byte = lowest_byte;
                lowest_byte = -1;
                rewind(fp);
            }
        }
    }


    fclose(fp);
    return;
}

void descending(char *file_name) {
    //First we define a file pointer fp. 
    FILE *fp = fopen(file_name, "r");

    //This is the limited buffer to store the character and it's null turminator.  
    char buf[2] = {0, }; 

    //Current lowest starting location
    int biggest_byte = -1;

    //The latest lowest byte
    int last_biggest_byte = -1;

    //The location of the file cursur. 
    int cursur_byte = 0;

    //Retrun value of strcmp
    int r_val = 0;

    //This loop will continue untill the lowest is is the same as the cursur's value. 
    while(1) {

        cursur_byte = ftell(fp);
        if(0 == strcmp(buf, "\n") || 0 == ftell(fp)) {
            if(biggest_byte == cursur_byte) {
                //This means that cursur and lowest are at the same location so we should just skip it. 
                fread(buf, sizeof(char), 1, fp);
                continue;
            }
            //File will read throught the whole file from the start of the word,
            //and it will record the lowest value
            
            
            //We need to see if there is any previous record of the last lowest byte
            if(-1 != last_biggest_byte) { //This means it has read the whole file
                if(0 > my_strcmp(file_name, cursur_byte, last_biggest_byte)) {
                    // printf("1st%d\n", biggest_byte);
                    if(-1 == biggest_byte) {
                        // printf("2nd%d\n", biggest_byte);
                        biggest_byte = cursur_byte;
                    } else {
                        // printf("3rd%d\n", biggest_byte);
                        r_val = my_strcmp(file_name, cursur_byte, biggest_byte);
                        if(0 < r_val && last_biggest_byte != cursur_byte) {
                            biggest_byte = cursur_byte;
                        }
                    }   
                }
            } else { //This means that it hasn't read the whole file. 
                if(0 == cursur_byte) {
                    biggest_byte = 0;
                } else {
                    r_val = my_strcmp(file_name, cursur_byte, biggest_byte);
                    if(0 < r_val) {
                        biggest_byte = cursur_byte;
                    }
                }

    
            }
        }
        //Reading the file and save it to the limited bufer. 
        fread(buf, sizeof(char), 1, fp);


        if(0 != feof(fp)) { //It means that it is the end of the file. 
            // printf("4th%d\n", biggest_byte);
            if(-1 == biggest_byte || biggest_byte == last_biggest_byte) {
                break;
            } else {
                print_word(file_name, biggest_byte);
                last_biggest_byte = biggest_byte;
                biggest_byte = -1;
                rewind(fp);
            }
        }
    }


    fclose(fp);
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
            if(0 == is_alpha(cursur[0])) { //This means that the cursur is bigger and no matter what the value is it is lower
                fclose(fp);
                return 1;
            } else if(1 == is_alpha(cursur[0]) && 1 == is_alpha(lowest[0])) {
                //If they are both alphabet
                if(0 == is_upper(cursur[0]) && 1 == is_upper(lowest[0])) { //if cursur was lower and lowest was upper
                    cursur[0] = toupper(cursur[0]);
                    if(0 < strcmp(cursur, lowest)) { //if whey are both alphabet and only cursur is upper
                        fclose(fp);
                        return 1;
                    } else if(0 > strcmp(cursur, lowest)) {
                        fclose(fp);
                        return -1;
                    } else {
                        cursur_byte++;
                        lowest_byte++;
                    }
                } else {
                    fclose(fp);
                    return 1;
                }
            } else {
                fclose(fp);
                return 1;
            }
            
        } else if(0 > strcmp(cursur, lowest)) {
            //This means that that the cursur is lower than the lowest

            if(0 == is_alpha(cursur[0])) { //This means that the cursur is bigger and no matter what the value is it is lower
                fclose(fp);
                return -1;
            } else if(1 == is_alpha(cursur[0]) && 1 == is_alpha(lowest[0])) {
                //If they are both alphabet
                if(1 == is_upper(cursur[0]) && 0 == is_upper(lowest[0])) { //if cursur was lower and lowest was upper
                    lowest[0] = toupper(lowest[0]);
                    if(0 < strcmp(cursur, lowest)) { //if whey are both alphabet and only cursur is upper
                        fclose(fp);
                        return 1;
                    } else if(0 > strcmp(cursur, lowest)) {
                        fclose(fp);
                        return -1;
                    } else {
                        cursur_byte++;
                        lowest_byte++;
                    }
                } else {
                    fclose(fp);
                    return -1;
                }
            } else {
                fclose(fp);
                return -1;
            }
        } else {
            //This means they have the same value
            cursur_byte++;
            lowest_byte++;
        }
    }


    fclose(fp);
    return 0;
}