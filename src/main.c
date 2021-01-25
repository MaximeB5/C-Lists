// My Includes
#include "../headers/data.h"
#include "../headers/custom_list.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
#define NB_NODE 3

int main()
{
	printf("Hello from C-Lists.\n\n");

	// -------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------

	printf("\nTest for Struct Data\n\n");
	// Test for add
	int int_1 = 0;
	int int_2 = 0;
	int * p_int_1 = &int_1;
	int * p_int_2 = &int_2;
	
	*p_int_1 = 3;
	*p_int_2 = 9;

	Data data_rx;
	Data data_tx;

	data_rx._int 	= 1;
	data_tx._int 	= 2;
	data_rx._p_int 	= p_int_1;
	data_tx._p_int 	= p_int_2;

	printf("Values of data_rx before add : %d, %d, and values of data_tx : %d, %d.\n", data_rx._int, *(data_rx._p_int), data_tx._int, *(data_tx._p_int));
	add_data(&data_rx, &data_tx);
	printf("Values of data_rx after add : %d, %d, and values of data_tx : %d, %d.\n", data_rx._int, *(data_rx._p_int), data_tx._int, *(data_tx._p_int));

	// -------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------

	printf("\n\nTest for Struct Node\n\n");

	int node_counter = 0;
	
	Node * head		= NULL;
    Node * second	= NULL;
    Node * third 	= NULL;
  
    // Allocate 3 nodes in the heap 
    head	= (Node *) malloc( sizeof(Node) );
    second 	= (Node *) malloc( sizeof(Node) );
    third 	= (Node *) malloc( sizeof(Node) );

	// Set the data -> head
	printf("\nHead takes data_tx : %d, %d.\n", data_tx._int, *(data_tx._p_int));
	head->_data = &data_tx;
	set_id(head, &node_counter);

	// Set the data -> second
	printf("\nSecond takes data_rx : %d, %d.\n", data_rx._int, *(data_rx._p_int));
	set_data(second, &data_rx, &node_counter);
	printf("Second checks data_rx : %d, %d.\n", data_rx._int, *(data_rx._p_int));

	// Set the data -> third
	printf("\nThird takes data_rx : %d, %d.\n", data_rx._int, *(data_rx._p_int));
	add_data(&data_rx, &data_tx);
	set_data(third, &data_rx, &node_counter);
	printf("Third checks data_rx : %d, %d.\n\n", data_rx._int, *(data_rx._p_int));

	// Add the nodes
	add_node(head, second);
	add_node(head, third);

	// Check
	Node * current_node = head;
	do
	{	printf("Adress of the Node : %p\n", current_node);
		printf("Node '%d' with values %d and %d\n", current_node->_id, current_node->_data->_int, *(current_node->_data->_p_int));
		current_node = current_node->_next_element;
	} while(current_node);

	// Free the memory
	free(head);
	free(second);
	free(third);
	
	// All to NULL
	head 	= NULL;
	second 	= NULL;
	third	= NULL;

	return(0);
}
