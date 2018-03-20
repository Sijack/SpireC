#ifndef UTILS_H_
#define UTILS_H_

typedef struct node {
    char *factor;
    struct node *next;
} node_t;

int check_word_and_alphabet(char word[], char list_alphabet[]);
void free_list(node_t* head);
void print_list_reverse(node_t *node);
void print_list(node_t *node);
char * substring(char word[], int x, int y);

#endif /* UTILS_H_ */
