/**
 * This header file is when the option is alpha-numerica representation
 * It has it's own helper function and it will print out the sorted order of the text file 
 * to the command lind.   
 */
#ifndef alpha_h
#define alpha_h

void alph_printer(char **argv);

void ascending(char *file_name);

void descending(char *file_name);

int my_strcmp(char *file_name, int cursur_byte, int lowest_byte);

void print_word(char *file_name, int starting_byte);

#endif