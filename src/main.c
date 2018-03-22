#include <stdio.h>
#include <stdlib.h>
#include "factorizations.h"

int main() {

	char *word = "DABDADACDDBDC";
	char *list_alphabet = "DCBA";

	if (check_word_and_alphabet(word, list_alphabet) == 0) //false
		return EXIT_FAILURE;
//	atexit(report_mem_leak); //for mem_leak_detector

	int i;
	for (i = 0; i < 10000000; i++) {

		printf("\n\nCFL:\n");
		node_t *node = CFL(word);
		print_list_reverse(node);

		free_list(node);

		printf("\n\nCFL for alphabet:\n");
		node_t *node2 = CFL_for_alphabet(word, list_alphabet);
		print_list_reverse(node2);

		free_list(node2);

		printf("\n\nICFL recursive:\n");
		node_t *node3 = ICFL_recursive(word);
		print_list(node3);

		free_list(node3);

		printf("\n\nICFL for alphabet recursive:\n");
		node_t *node4 = ICFL_recursive_for_alphabet(word, list_alphabet);
		print_list(node4);

		free_list(node4);
	}

	return EXIT_SUCCESS;
}

//compute_icfl_for_alphabet ricorsivamente chiama compute_icfl_for_alphabet (confermato, anche se controlla)
//for_alphabet in python non accettano stringhe con char non presenti nell'alfabeto, aggiunta funzione di controllo ma non modifica
//organizzazione struttura progetto

//memoria icfl



