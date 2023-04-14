

#ifndef TETRIS_GAMEOBJECT_H
#define TETRIS_GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
namespace object {
class GameObject {
 public:
  GameObject() = default;
  ~GameObject() = default;

  sf::Vector2f getVelocity();

 private:

  sf::Vector2f Vel;

};
}
#endif //TETRIS_GAMEOBJECT_H
