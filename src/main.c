#include <stdio.h>
#include <stdlib.h>
#include "factorizations.h"

int main() {

	char *word;
	char *list_alphabet = "TNGCA"; //N
	int C = 10;
	char *path = "./fasta/example.fasta";
	char buff[255];

	FILE *fp;
	fp = fopen(path, "r");

	if (fp == NULL) {
		printf("\n\nErrore lettura fasta\n\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buff, 255, fp) != NULL) {
		printf("\n\n\n\n\t%s", buff);
		//tenere traccia di id
		if (buff[0] == '>') {
			fgets(buff, 255, fp);
		}

		if (strchr(buff, '\n') != NULL)
			word = substring(buff, 0, strlen(buff) - 1);
		else
			strcpy(word, buff);

		if (check_word_and_alphabet(word, list_alphabet) == 0) //false
			return EXIT_FAILURE;
		//atexit(report_mem_leak); //for mem_leak_detector

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

		printf("\n\nICFL recursive for alphabet:\n");
		node_t *node4 = ICFL_recursive_for_alphabet(word, list_alphabet);
		print_list(node4);

		free_list(node4);

		printf("\n\nCFL_icfl:\n");
		node_t *node5 = CFL_icfl(word, C);
		print_list_reverse(node5);

		free_list(node5);

		printf("\n\nCFL_icfl_for_alphabet:\n");
		node_t *node6 = CFL_icfl_for_alphabet(word, C, list_alphabet);
		print_list_reverse(node6);

		free_list(node6);

		printf("\n\nICFL_cfl:\n");
		node_t *node7 = ICFL_cfl(word, C);
		print_list(node7);

		free_list(node7);

		printf("\n\nICFL_cfl_for_alphabet:\n");
		node_t *node8 = ICFL_cfl_for_alphabet(word, C, list_alphabet);
		print_list(node8);

		free_list(node8);

		free(word);
	}

	return EXIT_SUCCESS;
}

