#include <SFML/Graphics.hpp>

#ifndef VEC_H
#define VEC_H
class Vec {
  /*
    class of vectors
  */
private:
  float pos_x, pos_y;
  float x, y;
  sf::Color color;
  sf::Vertex main_line[2];
  sf::Vertex l_line[2];
  sf::Vertex r_line[2];
public:
  Vec(float pos_x, float pos_y, float x, float y, sf::Color color);
  void vec_draw(sf::RenderWindow& window);
};

#endif
