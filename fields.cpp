#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "point.h"
#include "object.h"
#include "fields.h"


void get_potential_field(std::vector<std::vector<double >>& scalar_field, std::vector<Object >& objects)
{

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			//scalar_field[y][x] = 0;
			//for(int i = 0; i < objects.size(); i++)
			scalar_field[y][x] += objects[objects.size()-1].get_potential_in_the_point(x, y);
		        //std::cout << "++";
		}
	}
}

void give_potential_field(std::vector<std::vector<double>>& scalar_field)
{
	std::ofstream outFile(POTENTIAL_FIELD_FILE);

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			//std::cout << scalar_field[y][x] << "\n";
			//outFile << std::setprecision(6) << scalar_field[y][x] << ' ';
			outFile << scalar_field[y][x] << ' ';
		}

		outFile << '\n';
	}

	outFile.close();
}

void get_vector_field(std::vector<std::vector<double >>& vector_field, std::vector<std::vector<double >>& scalar_field)
{       //std::cout << "get\n";
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
				if ((!std::isinf(scalar_field[y][x]))&&(!std::isinf(scalar_field[y+1][x]))&&(!std::isinf(scalar_field[y][x+1])))
				{vector_field[y][2 * x] = scalar_field[y][x] - scalar_field[y][x + 1];
				vector_field[y][2 * x + 1] = scalar_field[y][x] - scalar_field[y + 1][x];}
				else {
					vector_field[y][2 * x] = NAN;
					vector_field[y][2 * x + 1] = NAN;
				}
			}
		}
	}
	//std::cout << "get222\n";
}

void give_vector_field(std::vector<std::vector<double >>& vector_field)
{

	std::ofstream outFile(VECTOR_FIELD_FILE);

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < 2 * FIELD_WIDTH; x++)
		{
			outFile << vector_field[y][x] << ' ';
		}

		outFile << '\n';
	}

	outFile.close();
}
