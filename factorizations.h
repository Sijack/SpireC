#ifndef FACTORIZATIONS_H_
#define FACTORIZATIONS_H_

typedef struct node {
    char *factor;
    struct node *next;
} node_t;

int index_in_alphabet(char t, char typ_alphabet_list[]);
void print_list_reverse(node_t *node);
void print_list(node_t *node);
char * substring(char word[], int x, int y);
node_t * CFL(char word[]);
node_t * CFL_for_alphabet(char word[], char list_alphabet[]);
node_t *find_pre(char word[]);
node_t *find_pre_for_alphabet(word,list_alphabet);
void border(char p[], int **pi);
node_t *find_bre(node_t *pre_pair);
node_t *find_bre_for_alphabet(node_t *pre_pair, char list_alphabet[]);
void compute_icfl_recursive(char word[], node_t **curr_pointer_br, node_t **curr_pointer_icfl);
//void compute_icfl_recursive_for_alphabet(word, br_list, icfl_list, list_alphabet);
node_t *ICFL_recursive(char word[]);
//node_t *ICFL_recursive_for_alphabet(char word[], char list_alphabet[]);

#endif /* FACTORIZATIONS_H_ */
