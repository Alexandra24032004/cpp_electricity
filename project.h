#include "constants.h"
#include "object.h"


#ifndef PROJECT_H
#define PROJECT_H

class Project
{
private:
	std::vector<std::vector<double>> scalar_field;  
	std::vector<Object> objects;
	bool is_scalar = 1;

public:

	Project()
	{
		scalar_field = std::vector<std::vector<double>>(SCREEN_HEIGHT, std::vector<double>(SCREEN_WIDTH, 0));
	}

	void run();
};

#endif
