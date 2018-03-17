#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct of any list's node, generally nodes are considered in last-first order
typedef struct node {
    char *factor;
    struct node *next;
} node_t;

int index_in_alphabet(char t, char typ_alphabet_list[]) {
    int i;
    for (i = 0; i < strlen(typ_alphabet_list); i++) {
        if (typ_alphabet_list[i] == t)
            return i;
    }
    return -1;
}

int count_for_print;
//recursive print of nodes in first-last order
void print_list_reverse(node_t *node) {
	if (node->next != NULL) {
		count_for_print++;
		print_list_reverse(node->next);
	} else {
		printf("[ ");
	}
	printf("\"%s\" ", node->factor);
	if (count_for_print == 0) {
		printf("]");
		count_for_print = 1;
	}
	count_for_print--;
}

void print_list(node_t *node) {
	printf("[ ");
	while (node != NULL) {
		printf("\"%s\" ", node->factor);
		node = node->next;
	}
	printf("]");
}

char *substring(char word[], int x, int y) {
	int k = 0, i;
	char *sub = (char *) malloc((y-x + 1));

	for (i = x; i < y; i++) {
		sub[k++] = word[i];
	}
	sub[k] = '\0';

	return sub;
}

// ---------------------- CFL -----------------------------------------------------------------
// CFL - Lyndon factorization - Duval's algorithm
node_t *CFL(char word[]) {

    //CFL Duval's algorithm.

	node_t *current_pointer = NULL;

    int k = 0, i, j;
    int word_len = strlen(word);

    while (k < word_len) {
        i = k + 1;
        j = k + 2;
        while (1) {
            if (j == word_len + 1 || word[j - 1] < word[i - 1]) {
                while (k < i) {
                	node_t *node = (node_t *) malloc(sizeof(node_t));
                	node->factor = substring(word, k, k + j - i);
                	node->next = current_pointer;
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
node_t *CFL_for_alphabet(char word[], char list_alphabet[]) {

    //CFL Duval's algorithm.

	node_t *current_pointer = NULL;

    int k = 0, i, j;
    int word_len = strlen(word);

    while (k < word_len) {
        i = k + 1;
        j = k + 2;
        while (1) {
            if (j == word_len + 1 || index_in_alphabet(word[j - 1], list_alphabet) < index_in_alphabet(word[i - 1], list_alphabet)) {
                while (k < i) {
                	node_t *node = (node_t *) malloc(sizeof(node_t));
                	node->factor = substring(word, k, k + j - i);
                	node->next = current_pointer;
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

// ----------------------- ICFL ----------------------------------------------------------------------

//returns 2 factors as a list in first-last order
node_t *find_pre(char word[]) {

	int word_len = strlen(word);
	node_t *fact1 = NULL, *fact2 = NULL;

    if (word_len == 1) {

    	fact1 = (node_t *) malloc(sizeof(node_t));

		char *new_fact;
		new_fact = (char *) malloc(word_len + 2);
		int z;
		for (z = 0; z < word_len;z++){
			new_fact[z] = word[z];
		}
		new_fact[z] = '$';
		new_fact[z+1] = '\0';

		fact1->factor = new_fact;
		//strcat(fact1->factor, word);
		//strcat(fact1->factor, "$");

    	fact2 = (node_t *) malloc(sizeof(node_t));
    	fact2->factor = "";
    	fact2->next = NULL;

    	fact1->next = fact2;

        return fact1;

    } else {
        int i = 0, j = 1;

        while ((j < word_len) && (word[j] <= word[i])) {
            if (word[j] < word[i])
                i = 0;
            else
                i = i + 1;

            j = j + 1;
        }

        if (j == word_len) {

        	fact1 = (node_t *) malloc(sizeof(node_t));

        	char *new_fact;
        	new_fact = (char *) malloc(word_len + 2);
        	int z;
        	for (z = 0; z < word_len;z++){
        		new_fact[z] = word[z];
        	}
        	new_fact[z] = '$';
        	new_fact[z+1] = '\0';

        	fact1->factor = new_fact;
        	//strcat(fact1->factor, word);
        	//strcat(fact1->factor, "$");

			fact2 = (node_t *) malloc(sizeof(node_t));
			fact2->factor = "";
			fact2->next = NULL;

			fact1->next = fact2;

			return fact1;

        } else {

        	fact1 = (node_t *) malloc(sizeof(node_t));
        	fact1->factor = substring(word, 0, j + 1);

        	fact2 = (node_t *) malloc(sizeof(node_t));
        	fact2->factor = substring(word, j + 1, word_len);
        	fact2->next = NULL;

        	fact1->next = fact2;

            return fact1;
        }
    }
}

//returns 2 factors as a list in first-last order
node_t *find_pre_for_alphabet(char word[], char list_alphabet[]) {

	int word_len = strlen(word);
	node_t *fact1 = NULL, *fact2 = NULL;

    if (word_len == 1) {

    	fact1 = (node_t *) malloc(sizeof(node_t));

    	char *new_fact;
		new_fact = (char *) malloc(word_len + 2);
		int z;
		for (z = 0; z < word_len;z++){
			new_fact[z] = word[z];
		}
		new_fact[z] = '$';
		new_fact[z+1] = '\0';

		fact1->factor = new_fact;
		//strcat(fact1->factor, word);
		//strcat(fact1->factor, "$");

    	fact2 = (node_t *) malloc(sizeof(node_t));
    	fact2->factor = "";
    	fact2->next = NULL;

    	fact1->next = fact2;

        return fact1;

    } else {
        int i = 0, j = 1;
        while ((j < word_len) && (index_in_alphabet(word[j], list_alphabet) <= index_in_alphabet(word[i],list_alphabet))) {
            if (index_in_alphabet(word[j], list_alphabet) < index_in_alphabet(word[i],list_alphabet))
                i = 0;
            else
                i = i + 1;

            j = j + 1;
        }

        if (j == word_len) {

        	fact1 = (node_t *) malloc(sizeof(node_t));

        	char *new_fact;
			new_fact = (char *) malloc(word_len + 2);
			int z;
			for (z = 0; z < word_len;z++){
				new_fact[z] = word[z];
			}
			new_fact[z] = '$';
			new_fact[z+1] = '\0';

			fact1->factor = new_fact;
			//strcat(fact1->factor, word);
			//strcat(fact1->factor, "$");

			fact2 = (node_t *) malloc(sizeof(node_t));
			fact2->factor = "";
			fact2->next = NULL;

			fact1->next = fact2;

			return fact1;

        } else {

        	fact1 = (node_t *) malloc(sizeof(node_t));
        	fact1->factor = substring(word, 0, j + 1);

        	fact2 = (node_t *) malloc(sizeof(node_t));
        	fact2->factor = substring(word, j + 1, word_len);
        	fact2->next = NULL;

        	fact1->next = fact2;

            return fact1;
        }
    }
}

void border(char p[], int **pi) {
    int l = strlen(p);
    *pi = (int *) malloc(sizeof(int) * l);
    int k = 0;
    int i, j = 1;

    *(pi[0]) = 0;

    for (i = 1; i < l; i++) {
        while ((k > 0) && (p[k] != p[i])) {
        	k = (*pi)[k-1];
        }

        if (p[k] == p[i]) {
            k++;
        }
        (*pi)[j] = k;
        j++;
    }
}

//returns 3 factors and an index as a list in first-last order
node_t *find_bre(node_t *pre_pair) {
    char *w = pre_pair->factor;
    char *v = pre_pair->next->factor;

    node_t *fact1 = NULL, *fact2 = NULL, *fact3 = NULL, *last_index = NULL;

    if ((v[0] == '\0') && (strchr(w, '$') != NULL)) {

    	fact1 = (node_t *) malloc(sizeof(node_t));
    	fact2 = (node_t *) malloc(sizeof(node_t));
    	fact3 = (node_t *) malloc(sizeof(node_t));
    	last_index = (node_t *) malloc(sizeof(node_t));

    	fact1->factor = w;
    	fact2->factor = "";
    	fact3->factor = "";
    	last_index->factor = "0";

    	last_index->next = NULL;
    	fact3->next = last_index;
    	fact2->next = fact3;
    	fact1->next = fact2;

    	return fact1;

    } else {
        int n = strlen(w) - 1;
        int *f = NULL;
        border(substring(w, 0, n), &f);

        int i = n;
        int last = f[i-1];

        while (i > 0) {
            if (w[f[i-1]] < w[n])
                last = f[i-1];
            i = f[i-1];
        }

        fact1 = (node_t *) malloc(sizeof(node_t));
		fact2 = (node_t *) malloc(sizeof(node_t));
		fact3 = (node_t *) malloc(sizeof(node_t));

		//count digits in last
		i = last;
		int digit_count = 0;
		while(i != 0) {
		    i /= 10;
		    digit_count += 1;
		}

		last_index = (node_t *) malloc(sizeof(node_t));
		last_index->factor = (char *) malloc(digit_count + 1);

		fact1->factor = substring(w, 0, n - last);
		fact2->factor = substring(w, n - last, n + 1);
		fact3->factor = v;
		sprintf(last_index->factor, "%d", last);

		last_index->next = NULL;
		fact3->next = last_index;
		fact2->next = fact3;
		fact1->next = fact2;

		return fact1;
    }
}

//returns 3 factors and an index as a list in first-last order
node_t *find_bre_for_alphabet(node_t *pre_pair, char list_alphabet[]) {
    char *w = pre_pair->factor;
    char *v = pre_pair->next->factor;

    node_t *fact1 = NULL, *fact2 = NULL, *fact3 = NULL, *last_index = NULL;

    if ((v[0] == '\0') && (strchr(w, '$') != NULL)) {

    	fact1 = (node_t *) malloc(sizeof(node_t));
    	fact2 = (node_t *) malloc(sizeof(node_t));
    	fact3 = (node_t *) malloc(sizeof(node_t));
    	last_index = (node_t *) malloc(sizeof(node_t));

    	fact1->factor = w;
    	fact2->factor = "";
    	fact3->factor = "";
    	last_index->factor = "0";

    	last_index->next = NULL;
    	fact3->next = last_index;
    	fact2->next = fact3;
    	fact1->next = fact2;

    	return fact1;

    } else {
        int n = strlen(w) - 1;
        int *f = NULL;
        border(substring(w, 0, n), &f);

        int i = n;
        int last = f[i-1];
        while (i > 0) {
            if (index_in_alphabet(w[f[i-1]], list_alphabet) < index_in_alphabet(w[n], list_alphabet))
                last = f[i-1];
            i = f[i-1];
        }

        fact1 = (node_t *) malloc(sizeof(node_t));
		fact2 = (node_t *) malloc(sizeof(node_t));
		fact3 = (node_t *) malloc(sizeof(node_t));

		//count digits in last
		i = last;
		int digit_count = 0;
		while(i != 0) {
		    i /= 10;
		    digit_count += 1;
		}

		last_index = (node_t *) malloc(sizeof(node_t));
		last_index->factor = (char *) malloc(digit_count + 1);

		fact1->factor = substring(w, 0, n - last);
		fact2->factor = substring(w, n - last, n + 1);
		fact3->factor = v;
		sprintf(last_index->factor, "%d", last);

		last_index->next = NULL;
		fact3->next = last_index;
		fact2->next = fact3;
		fact1->next = fact2;

		return fact1;
    }
}

void compute_icfl_recursive(char word[], node_t **curr_pointer_br, node_t **curr_pointer_icfl) {

    // At each step compute the current bre
    node_t *pre_pair = find_pre(word);
    node_t *current_bre_quad = find_bre(pre_pair);

    if(*curr_pointer_br != NULL) {
		node_t *track_pointer = *curr_pointer_br;
		while(track_pointer->next != NULL) {
			track_pointer = track_pointer->next;
		}
		track_pointer->next = current_bre_quad;

    } else {
    	*curr_pointer_br = current_bre_quad;
    }

    if ((current_bre_quad->next->factor[0] == '\0') && (strchr(current_bre_quad->factor, '$') != NULL)) {
        char *w = current_bre_quad->factor;
        node_t * icfl_node = (node_t *) malloc(sizeof(node_t));
        icfl_node->factor = substring(w, 0, strlen(w) - 1);

        if (*curr_pointer_icfl == NULL) {
        	 icfl_node->next = NULL;
        	 *curr_pointer_icfl = icfl_node;
        } else {
        	icfl_node->next = *curr_pointer_icfl;
        	*curr_pointer_icfl = icfl_node;
        }
        return;

    } else {
    	char *fact1_fact2 = (char *) malloc(strlen(current_bre_quad->next->factor) + strlen(current_bre_quad->next->next->factor) + 1);
    	fact1_fact2[0] = '\0';
    	strcat(fact1_fact2, current_bre_quad->next->factor);
    	strcat(fact1_fact2, current_bre_quad->next->next->factor);

        compute_icfl_recursive(fact1_fact2, curr_pointer_br, curr_pointer_icfl);
        if (strlen((*curr_pointer_icfl)->factor) > atoi(current_bre_quad->next->next->next->factor)) {

        	node_t * icfl_node = (node_t *) malloc(sizeof(node_t));
        	icfl_node->factor = current_bre_quad->factor;

        	if (*curr_pointer_icfl == NULL) {
        		icfl_node->next = NULL;
        	    *curr_pointer_icfl = icfl_node;
        	} else {
        	    icfl_node->next = *curr_pointer_icfl;
        	    *curr_pointer_icfl = icfl_node;
        	}

        } else {

        	node_t * new_icfl_node = (node_t *) malloc(sizeof(node_t));
        	new_icfl_node->factor = current_bre_quad->factor;
        	//strcat(new_icfl_node->factor, current_bre_quad->factor);
        	strcat(new_icfl_node->factor, (*curr_pointer_icfl)->factor);
        	new_icfl_node->next = (*curr_pointer_icfl)->next;
        	(*curr_pointer_icfl)->next = NULL;
        	free(*curr_pointer_icfl);
        }
        return;
    }
}

//ICFL recursive (without using of compute_br)- Inverse Lyndon factorization - on a specific alphabet
void compute_icfl_recursive_for_alphabet(char word[], node_t **curr_pointer_br, node_t **curr_pointer_icfl, char list_alphabet[]) {

    // At each step compute the current bre
    node_t *pre_pair = find_pre_for_alphabet(word, list_alphabet);
    node_t *current_bre_quad = find_bre_for_alphabet(pre_pair, list_alphabet);

    if(*curr_pointer_br != NULL) {
		node_t *track_pointer = *curr_pointer_br;
		while(track_pointer->next != NULL) {
			track_pointer = track_pointer->next;
		}
		track_pointer->next = current_bre_quad;

	} else {
		*curr_pointer_br = current_bre_quad;
	}

    if ((current_bre_quad->next->factor[0] == '\0') && (strchr(current_bre_quad->factor, '$') != NULL)) {
        char *w = current_bre_quad->factor;
        node_t * icfl_node = (node_t *) malloc(sizeof(node_t));
        icfl_node->factor = substring(w, 0, strlen(w) - 1);

        if (*curr_pointer_icfl == NULL) {
        	 icfl_node->next = NULL;
        	 *curr_pointer_icfl = icfl_node;
        } else {
        	icfl_node->next = *curr_pointer_icfl;
        	*curr_pointer_icfl = icfl_node;
        }
        return;

    } else {
    	char *fact1_fact2 = (char *) malloc(strlen(current_bre_quad->next->factor) + strlen(current_bre_quad->next->next->factor) + 1);
    	fact1_fact2[0] = '\0';
    	strcat(fact1_fact2, current_bre_quad->next->factor);
    	strcat(fact1_fact2, current_bre_quad->next->next->factor);

        compute_icfl_recursive(fact1_fact2, curr_pointer_br, curr_pointer_icfl);
        if (strlen((*curr_pointer_icfl)->factor) > atoi(current_bre_quad->next->next->next->factor)) {

        	node_t * icfl_node = (node_t *) malloc(sizeof(node_t));
        	icfl_node->factor = current_bre_quad->factor;
        	if (*curr_pointer_icfl == NULL) {
        		icfl_node->next = NULL;
        	    *curr_pointer_icfl = icfl_node;
        	} else {
        	    icfl_node->next = *curr_pointer_icfl;
        	    *curr_pointer_icfl = icfl_node;
        	}

        } else {

        	node_t *new_icfl_node = (node_t *) malloc(sizeof(node_t));
        	//new_icfl_node->factor[0] = '\0';
        	strcat(new_icfl_node->factor, current_bre_quad->factor);
        	strcat(new_icfl_node->factor, (*curr_pointer_icfl)->factor);
        	new_icfl_node->next = (*curr_pointer_icfl)->next;
        	(*curr_pointer_icfl)->next = NULL;
        	free(*curr_pointer_icfl);
        }
        return;
    }
}

//ICFL recursive (without using of compute_br)- Inverse Lyndon factorization
node_t *ICFL_recursive(char word[]) {
    //In this version of ICFL, we don't execute compute_br - one only O(n) scanning of word

	node_t *curr_pointer_br = NULL;
	node_t *curr_pointer_icfl = NULL;

    compute_icfl_recursive(word, &curr_pointer_br, &curr_pointer_icfl);

    return curr_pointer_icfl;
}


node_t *ICFL_recursive_for_alphabet(char word[], char list_alphabet[]) {
    //In this version of ICFL, we don't execute compute_br - one only O(n) scanning of word

	node_t *curr_pointer_br = NULL;
	node_t *curr_pointer_icfl = NULL;

    compute_icfl_recursive_for_alphabet(word, &curr_pointer_br, &curr_pointer_icfl, list_alphabet);

    return curr_pointer_icfl;
}

