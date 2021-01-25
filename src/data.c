// My Includes
#include "../headers/data.h"

// Includes
	// None for the moment.

// My Defines
	// None for the moment.

/**
 * @brief add to receiving_data the values from data_to_add
 * 
 * @param receiving_data 
 * @param data_to_add 
 */
void add_data(struct Data * receiving_data, const struct Data * data_to_add)
{
	receiving_data->_int += data_to_add->_int;
	*(receiving_data->_p_int) += *(data_to_add->_p_int);
}