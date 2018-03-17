#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factorizations.h"

int main() {
/*
	printf("CFL:\n");
	node_t *node = CFL("dabdadacddbdc");
	print_list_reverse(node);

	printf("\n\nCFL for alphabet:\n");
	node_t *node2 = CFL_for_alphabet("dabdadacddbdc", "dcba");
	print_list_reverse(node2);

	printf("\n\n");

*/

	printf("\n\nICFL recursive:\n");
	node_t *node5 = ICFL_recursive("abaababaabbaabbbbbbbbb");
	print_list(node5);

/*
	node_t *node3 = find_pre("dabacddbdc");
	print_list(node3);
	printf("\n");

	node_t *node4 = find_bre(node3);
	print_list(node4); //dab dad acddbdc 2

	node_t *track_pointer = node4;
	    while(track_pointer->next != NULL) {
	    	track_pointer = track_pointer->next;
	    }
	    track_pointer->next = node3;
	    print_list(node4);
	    printf("\n");
	    print_list(track_pointer);
	    print_list(node3);
*/
/*
	printf("\n\nICFL for alphabet recursive:\n");
	node_t *node4 = ICFL_recursive_for_alphabet("dabdadacddbdc", "dcba");
	print_list(node4);
*/
	return 0;
}

//parentesi finale print_ricorsiva
//node_t *node4 = find_pre("a"); //stringa vuota?
//memoria
//makefile

