

#ifndef TETRIS_STYPEBLOCK_H
#define TETRIS_STYPEBLOCK_H
#include "GameBlock.h"
namespace object {
class STypeBlock : public object::GameBlock {
 public:
  STypeBlock(sf::Vector2f scale);

  std::vector<object::GameBlock> &getBlock();


 private:

  std::vector<object::GameBlock> s_block;
};
}
#endif //TETRIS_STYPEBLOCK_H
