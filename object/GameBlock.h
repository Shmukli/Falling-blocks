

#ifndef TETRIS_GAMEBLOCK_H
#define TETRIS_GAMEBLOCK_H
#include "GameObject.h"
namespace object {
class GameBlock : public GameObject {
 public:
  GameBlock() = default;
  GameBlock(sf::Vector2f scale);
  virtual ~GameBlock() = default;

  sf::Sprite &getBlock();
  void loadSprite();

  void move_right(object::GameBlock &game_block, sf::Vector2f &scale);

  void move_left(object::GameBlock &game_block, sf::Vector2f &scale);

  void move_down(object::GameBlock &game_block, sf::Vector2f &scale);




  /* GameBlock operator=(const GameBlock& gb) const; */
  static std::vector<sf::Texture> *textures;

 private:

  sf::Texture texture;
  sf::Sprite sprite;
};
}
#endif //TETRIS_GAMEBLOCK_H
