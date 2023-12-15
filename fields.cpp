#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "point.cpp"
#include "object.cpp"
#include "fields.h"


void get_potential_field(std::vector<vector<double >>& scalar_field, Object object)
{
	std::ofstream out;
	out.open(POTETNTIAL_FIELD_FILE);

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			scalar_field[y][x] = object.get_potential_in_the_point(x, y);
			scalar_field[y][x] = std::cout << std::setprecision(6) << object.get_potential_in_the_point(x, y) << ' ';
		}

		std::cout << '\n';
	}

	out.close();
}

void give_potential_field(Object object)
{
	std::vector<std::vector<double>> scalar_field(FIELD_HEIGHT, std::vector<double>(FIELD_WIDTH));

	get_potential_field(scalar_field, object);

	std::ofstream out;
	out.open(POTETNTIAL_FIELD_FILE);

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			std::cout << std::setprecision(6) << scalar_field[y][x] << ' ';
		}

		std::cout << '\n';
	}

	out.close();
}

void get_vector_field(std::vector<std::vector<double >>& vector_field, std::vector<std::vector<double >>& scalar_field)
{
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (x == FIELD_WIDTH - 1 || y == FIELD_HEIGHT - 1)
			{
				vector_field[y][2 * x] = 0.0;
				vector_field[y][2 * x + 1] = 0.0;
			}
			else
			{
				vector_field[y][2 * x] = scalar_field[y][x] - scalar_field[y][x + 1];
				vector_field[y][2 * x + 1] = scalar_field[y][x] - scalar_field[y + 1][x];
			}
		}
	}
}

void give_vector_field(Object object)
{
	std::vector<std::vector<double>> vector_field(FIELD_HEIGHT, std::vector<double>(2 * FIELD_WIDTH));
	std::vector<std::vector<double>> scalar_field(FIELD_HEIGHT, std::vector<double>(FIELD_WIDTH));

	//get_potential_field(scalar_field, object);
	//get_vector

	std::ofstream out;
	out.open(POTETNTIAL_FIELD_FILE);

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			std::cout << std::setprecision(6) << scalar_field[y][x] << ' ';
		}

		std::cout << '\n';
	}

	out.close();
}
