#ifndef DATA_H
#define DATA_H

// My Includes
	// None for the moment.

// Includes
	// None for the moment.

// My Defines
	// None for the moment.

typedef struct Data {
	int		_int;
	int	*	_p_int;
} Data;

void add_data(struct Data * receiving_data, const struct Data * data_to_add);

#endif // DATA_H