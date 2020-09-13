#ifndef num_h
#define num_h
/**
 * This header file is for sorting in numerical representation.  
 */
void num_printer(char **argv);

void num_ascending(char *file_name);

void num_descending(char *file_name);

int my_numcmp(char *file_name, int cursur_byte, int lowest_byte);


#endif