#include "object.h"

#ifndef FIELD_H
#define FIELD_H

void get_potential_field(std::vector<std::vector<double >>& scalar_field, std::vector<Object >& objects);

void get_vector_field(std::vector<std::vector<double >>& vector_field, std::vector<std::vector<double >>& scalar_field);

void give_potential_field(std::vector<std::vector<double >>& scalar_field);

void give_vector_field(std::vector<std::vector<double >>& vector_field);

#endif
