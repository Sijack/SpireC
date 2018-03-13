#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char *factor;
    struct node *prev;
} node_t;

int index_in_alphabet(char t, char typ_alphabet_list[]) {
    int i;
    for (i = 0; i < strlen(typ_alphabet_list); i++) {
        if (typ_alphabet_list[i] == t)
            return i;
    }
    return -1;
}

void print_list(node_t *node) {
	if (node->prev != NULL) {
		print_list(node->prev);
	}
	printf("%s ", node->factor);
}

char * substring(char word[], int x, int y) {
	int k = 0, i;
	char *sub = (char *) malloc((y-x + 1));

	for (i = x; i < y; i++) {
		sub[k++] = word[i];
	}
	sub[k] = '\0';

	return sub;
}

// —---------------------- CFL —-------------------------------------------------------------------
// CFL - Lyndon factorization - Duval's algorithm
node_t * CFL(char word[]) {

    //CFL Duval's algorithm.

	node_t * current_pointer = NULL;

    int k = 0, i, j;
    int word_len = strlen(word);

    while (k < word_len) {
        i = k + 1;
        j = k + 2;
        while (1) {
            if (j == word_len + 1 || word[j - 1] < word[i - 1]) {
                while (k < i) {
                	node_t *node = (node_t *) malloc(sizeof(node_t) + j - i);
                	node->factor = substring(word, k, k + j - i);
                	node->prev = current_pointer;
                	current_pointer = node;
                    k = k + j - i;
                }
                break;
            } else {
                if (word[j - 1] > word[i - 1]) {
                    i = k + 1;
                } else {
                    i = i + 1;
                }
                j = j + 1;
            }
        }
    }
    return current_pointer;
}


// CFL - Lyndon factorization - Duval's algorithm - on a specific alphabet
node_t * CFL_for_alphabet(char word[], char list_alphabet[]) {

    //CFL Duval's algorithm.

	node_t * current_pointer = NULL;

    int k = 0, i, j;
    int word_len = strlen(word);

    while (k < word_len) {
        i = k + 1;
        j = k + 2;
        while (1) {
            if (j == word_len + 1 || index_in_alphabet(word[j - 1], list_alphabet) < index_in_alphabet(word[i - 1], list_alphabet)) {
                while (k < i) {
                	node_t *node = (node_t *) malloc(sizeof(node_t) + j - i);
                	node->factor = substring(word, k, k + j - i);
                	node->prev = current_pointer;
                	current_pointer = node;
                    k = k + j - i;
                }
                break;
            } else {
                if (index_in_alphabet(word[j - 1], list_alphabet) > index_in_alphabet(word[i - 1], list_alphabet)) {
                    i = k + 1;
                } else {
                    i = i + 1;
                }
                j = j + 1;
            }
        }
    }
    return current_pointer;
}
