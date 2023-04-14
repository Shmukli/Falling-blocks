

#ifndef TETRIS_SQUARETYPEBLOCK_H
#define TETRIS_SQUARETYPEBLOCK_H
#include "GameBlock.h"
namespace object {
class SQUARETypeBlock : public object::GameBlock {
 public:
  SQUARETypeBlock(sf::Vector2f scale);

  std::vector<object::GameBlock> getBlock();

 private:

  std::vector<object::GameBlock> square_block;

};
}
#endif //TETRIS_SQUARETYPEBLOCK_H
