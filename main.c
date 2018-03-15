#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorizations.h"

int main() {

	printf("CFL:\n");
	node_t *node = CFL("dabdadacddbdc");
	print_list_reverse(node);

	printf("\nCFL for alphabet:\n");

	node_t *node2 = CFL_for_alphabet("dabdadacddbdc", "dcba");
	print_list_reverse(node2);

	printf("\n");
/*
	node_t *node3 = ICFL_recursive("dabdadacddbdc");
	//print_list(node3);
*/
/*
	node_t *curr_pointer_br = NULL;
	node_t *curr_pointer_icfl = NULL;
	printf("%x %x", &curr_pointer_br, &curr_pointer_icfl);

	compute_icfl_recursive("dabdadacddbdc", &curr_pointer_br, &curr_pointer_icfl);
*/
	return 0;
}


