#include "constants.h"
#include "object.h"

#ifndef OBJECT_H
#define OBJECT_H

class Project
{
private:
	std::vector<std::vector<double>> scalar_field(SCREEN_HEIGHT, std::vector<double>(SCREEN_WIDTH, 0));
	std::vector<Object> objects;
	bool is_scalar = 1;

public:

	void run();
};

#endif
