
#ifndef TETRIS_ITYPEBLOCK_H
#define TETRIS_ITYPEBLOCK_H
#include "GameBlock.h"
namespace object {
    class ITypeBlock : public object::GameBlock {
    public:
        ITypeBlock(sf::Vector2f scale);


        std::vector<object::GameBlock> getBlock();

    private:

        std::vector<object::GameBlock> I_block;

    };
}
#endif //TETRIS_ITYPEBLOCK_H
