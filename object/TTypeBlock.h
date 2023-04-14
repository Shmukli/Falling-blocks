

#ifndef TETRIS_TTYPEBLOCK_H
#define TETRIS_TTYPEBLOCK_H
#include "GameBlock.h"
namespace object {
class TTypeBlock : public object::GameBlock {
 public:
  TTypeBlock(sf::Vector2f scale);

  std::vector<object::GameBlock> getBlock();

 private:

  std::vector<object::GameBlock> t_block;
};
}
#endif //TETRIS_TTYPEBLOCK_H
