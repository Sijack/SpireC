#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorizations.h"

int main() {

	char *word = "dabdadacddbdc";
	char *list_alphabet = "dcba";

	printf("CFL:\n");
	node_t *node = CFL(word);
	print_list_reverse(node);

	printf("\n\nCFL for alphabet:\n");
	node_t *node2 = CFL_for_alphabet(word, list_alphabet);
	print_list_reverse(node2);

	printf("\n\nICFL recursive:\n");
	node_t *node3 = ICFL_recursive(word);
	print_list(node3);

	printf("\n\nICFL for alphabet recursive:\n");
	node_t *node4 = ICFL_recursive_for_alphabet(word, list_alphabet);
	print_list(node4);

	return 0;
}

//compute_icfl_for_alphabet ricorsivamente chiama compute_icfl o for_alphabet?
//find_pre(""); non accetta stringa vuota ma può ricevere stringa vuota?
//algoritmi for_alphabet in python non accettano stringhe con caratteri non presenti nell'alfabeto (upper e lower sono diversi), in c nessun errore
//memoria
//makefile

