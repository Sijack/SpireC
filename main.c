#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorizations.h"

int main() {
	node_t *node = CFL("dabdadacddbdc");
	print_list(node);

	printf("\n");

	node_t *node2 = CFL_for_alphabet("dabdadacddbdc", "dcba");
	print_list(node2);

	return 0;
}


