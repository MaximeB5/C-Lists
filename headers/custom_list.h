#ifndef CUSTOM_LIST_H
#define CUSTOM_LIST_H

// My Includes
#include "data.h"

// Includes
	// None for the moment.

// My Defines
	// None for the moment.

typedef struct Node {
	int		_id;
	Data *			_data;
	struct Node *	_next_element;
} Node;

void 	add_node	(Node * root_node, Node * node_to_add);
void 	set_data	(Node * node, Data * data, int * id);
void 	set_id		(Node * node, int * id);
Node * 	find_node	(Node * start_node, int value);

#endif // CUSTOM_LIST_H