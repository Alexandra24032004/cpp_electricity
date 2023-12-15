#include "object.h"

#ifndef FIELD_H
#define FIELD_H

void get_potential_field(std::vector<vector<double >>& scalar_field, Object object);

void get_vector_field(std::vector<vector<double >>& vector_field, std::vector<vector<double >>& scalar_field);

void give_potential_field(Object object);

void give_vector_field(Object object);

#endif
