#include "Vec.h"

Vec::Vec(float pos_x, float pos_y, float x, float y, sf::Color color){
    main_line[0] = sf::Vertex(sf::Vector2f(pos_x, pos_y), color);
    main_line[1] = sf::Vertex(sf::Vector2f(pos_x + x, pos_y + y), color);
    l_line[0] = sf::Vertex(sf::Vector2f(pos_x + x, pos_y + y), color);
    r_line[0] = sf::Vertex(sf::Vector2f(pos_x + x, pos_y + y), color);
    l_line[1] = sf::Vertex(sf::Vector2f(pos_x + x + (y-x)/5.66, pos_y + y - (x+y)/5.66), color);
    r_line[1] = sf::Vertex(sf::Vector2f(pos_x + x - (x+y)/5.66, pos_y + y + (x-y)/5.66), color);
}

void Vec::vec_draw(sf::RenderWindow& window) {
    /*
      method draws vector
    */
    window.draw(main_line, 2, sf::Lines);
    window.draw(l_line, 2, sf::Lines);
    window.draw(r_line, 2, sf::Lines);
  }
