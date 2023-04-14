

#ifndef TETRIS_LTYPEBLOCK_H
#define TETRIS_LTYPEBLOCK_H
#include "GameBlock.h"
namespace object {
class LTypeBlock : public object::GameBlock {
 public:
  LTypeBlock(sf::Vector2f scale);

  std::vector<object::GameBlock> getBlock();

 private:

  std::vector<object::GameBlock> L_block;

};

#endif //TETRIS_LTYPEBLOCK_H
}