#include <SFML/Graphics.hpp> //for visualisation
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream> //for work with files
#include <string>  //for work with strings
#include <sstream>
#include <iomanip>
#include <tuple> //for work with turples
#include "Vec.h" 
#include "object.h" 

using namespace std;

#ifndef VISUAL_H
#define VISUAL_H

void tokenize(string const &str, const char delim, vector<string> &out);

string fadeColor(string c1, string c2, double mix = 0.0);

tuple<int, int, int> convertColor(const string& colorCode);

vector<vector<vector<int>>> coloring(const vector<vector<double>>& arr, double max_el, const string& c1, const string& c2);

void display_scalar_field(const vector<vector<vector<int>>>& arr, sf::RenderWindow& window);

vector<vector<vector<int>>> get_scalar_field_ff ();

vector<Vec> get_vector_field_ff (vector<int> &body);

void display_vector_field (vector<Vec> & vectors, vector<int> &body, sf::RenderWindow& window);

void visualisation (vector<vector<double>> &scalar_field, bool is_scalar, vector<Object> &objects, sf::RenderWindow& window);

#endif
