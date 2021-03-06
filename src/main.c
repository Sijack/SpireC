#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorizations.h"

int main() {

	char *word = "TCAGGTCATCTGAAAAAATCATAAAGTAAAACCACAAAGCTCTGATTTGAAAAACATCATCTAAGACAAGAAATCATTCGATGTCTGAACATAGTTGGAACCGAAAGGGTTTGAATTCAAACCCTTTCGGTTCCAACCTTTTAAATAAGTAAAGCATTGAAGATACTCATTATTTGTATCCTAATCTAGTACTCAAAATGCAGATGACTTCTTATTCTTTAAGAAGGAAGGATCTATAATAACANANANAGNGNAANANAGAANACTNGNGCG";
	char *list_alphabet = "NTGCA"; //N?
	int C = 10;
	char *path = "./fasta/example.fasta";
	char buff[255];
/*
	FILE *fp;
	fp = fopen(path, "r");

	if (fp == NULL) {
		printf("\n\nErrore lettura fasta\n\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while (fgets(buff, 255, fp) != NULL) {
		i++;
		printf("\n\n\n\n\t%s\n\t%d\n", buff, i++);
		//tenere traccia di id

		if (buff[0] == '>') {
			fgets(buff, 255, fp);
		}

		if (strchr(buff, '\n') != NULL)
			word = substring(buff, 0, strlen(buff) - 1);
		else {
			word = malloc (strlen(buff) + 1);
			strcpy(word, buff);
		}

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
*/
		printf("\n\nCFL_icfl:\n");
		node_t *node5 = CFL_icfl(word, C);
		print_list_reverse(node5);

		free_list(node5);
/*
		printf("\n\nCFL_icfl_parallel:\n");
		node_t *node6 = CFL_icfl_parallel(word, C);
		print_list_reverse(node6);

		free_list(node6);

		printf("\n\nCFL_icfl_for_alphabet:\n");
		node_t *node7 = CFL_icfl_for_alphabet(word, C, list_alphabet);
		print_list_reverse(node7);

		free_list(node7);

		printf("\n\nCFL_icfl_for_alphabet_parallel:\n");
		node_t *node8 = CFL_icfl_for_alphabet_parallel(word, C, list_alphabet);
		print_list_reverse(node8);

		free_list(node8);

		printf("\n\nICFL_cfl:\n");
		node_t *node9 = ICFL_cfl(word, C);
		print_list(node9);

		free_list(node9);

		printf("\n\nICFL_cfl_parallel:\n");
		node_t *node10 = ICFL_cfl_parallel(word, C);
		print_list(node10);

		free_list(node10);

		printf("\n\nICFL_cfl_for_alphabet:\n");
		node_t *node11 = ICFL_cfl_for_alphabet(word, C, list_alphabet);
		print_list(node11);

		free_list(node11);

		printf("\n\nICFL_cfl_for_alphabet_parallel:\n");
		node_t *node12 = ICFL_cfl_for_alphabet_parallel(word, C, list_alphabet);
		print_list(node12);

		free_list(node12);

		printf("\n");
		free(word);
	}

	fclose(fp);
*/	return EXIT_SUCCESS;
}

