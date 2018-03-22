#ifndef FACTORIZATIONS_H_
#define FACTORIZATIONS_H_

#include "utils.h"

int index_in_alphabet(char t, char typ_alphabet_list[]);
node_t * CFL(char word[]);
node_t * CFL_for_alphabet(char word[], char list_alphabet[]);
node_t *find_pre(char word[]);
node_t *find_pre_for_alphabet(char word[], char list_alphabet[]);
void border(char p[], int **pi);
node_t *find_bre(char *w, char *v);
node_t *find_bre_for_alphabet(char *w, char *v, char list_alphabet[]);
void compute_icfl_recursive(char word[], node_t **curr_pointer_icfl);
void compute_icfl_recursive_for_alphabet(char word[], node_t **curr_pointer_icfl, char list_alphabet[]);
node_t *ICFL_recursive(char word[]);
node_t *ICFL_recursive_for_alphabet(char word[], char list_alphabet[]);

#endif /* FACTORIZATIONS_H_ */
