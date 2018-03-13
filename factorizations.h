#ifndef FACTORIZATIONS_H_
#define FACTORIZATIONS_H_

typedef struct node {
    char *factor;
    struct node *prev;
} node_t;

int index_in_alphabet(char t, char typ_alphabet_list[]);
void print_list(node_t *node);
char * substring(char word[], int x, int y);
node_t * CFL(char word[]);
node_t * CFL_for_alphabet(char word[], char list_alphabet[]);

#endif /* FACTORIZATIONS_H_ */
