// My Includes
#include "../headers/custom_list.h"
// Includes
#include <stddef.h>	// NULL

// My Defines
	// None for the moment.

/**
 * @brief add a node to the root node
 * If there is already a node after the root node, it inserts the new node between them
 * 
 * @param root_node 
 * @param node_to_add 
 */
void add_node(Node * root_node, Node * node_to_add)
{
	// Save the next node
	Node * node_after_root = root_node->_next_element;
	
	// Add the node to the root
	root_node->_next_element = node_to_add;
	
	// If there was a node before the add, set it after the new node
	if(node_after_root) {
		node_to_add->_next_element = node_after_root;
	}
}


/**
 * @brief Add the data to the Node
 * 
 * @param node 
 * @param data 
 */
void set_data(Node * node, Data * data, int * id)
{
	node->_data = data;
	set_id(node, id);
}


/**
 * @brief set the id of the node and increments by one the id passed to the function
 * 
 * @param node 
 * @param id 
 */
void set_id(Node * node, int * id)
{
	node->_id = *id;
	++(*id);
}


/**
 * @brief the search begin at the specified node.
 * It return a pointer on the first node to have the value in its data
 * If it cannot be find, it returns NULL.
 * 
 * @param start_node 
 * @param value 
 * @return Node* 
 */
Node * find_node(Node * start_node, int value)
{
	Node * current_node = start_node;
	do
	{
		if( (current_node->_data->_int == value) || (*(current_node->_data->_p_int) == value) ) {
			return current_node;
		}

		current_node = current_node->_next_element;
	}
	while(current_node);

	return NULL;
}