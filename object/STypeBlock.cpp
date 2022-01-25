#include "STypeBlock.h"

object::STypeBlock::STypeBlock(sf::Vector2f scale)
: GameBlock{scale}
{


    object::GameBlock base_block(scale); //center


    object::GameBlock first_block(scale);
    first_block.getBlock().setPosition(base_block.getBlock().getPosition().x + 50*scale.x, // right corner
                                          base_block.getBlock().getPosition().y);

    object::GameBlock second_block(scale);


    second_block.getBlock().setPosition(base_block.getBlock().getPosition().x,
                                        first_block.getBlock().getPosition().y + 50*scale.y); // under center

    object::GameBlock third_block(scale);


    third_block.getBlock().setPosition(second_block.getBlock().getPosition().x - 50*scale.x,
                                       second_block.getBlock().getPosition().y);
    this->s_block.push_back(base_block);
    this->s_block.push_back(first_block);
    this->s_block.push_back(second_block);
    this->s_block.push_back(third_block);

}

std::vector<object::GameBlock>& object::STypeBlock::getBlock(){

return this->s_block;

}

/*void object::STypeBlock::rotate(object::GameBlock &game_block, sf::Vector2f &scale, int iterator) {

    if(iterator == 1) {

        game_block.getBlock().setPosition(this->s_block.at(iterator + 1).getBlock().getPosition());

    }
    if(iterator == 2) {

        game_block.getBlock().setPosition(this->s_block.at(iterator - 2).getBlock().getPosition().x - 50*scale.x,
                                                          this->s_block.at(iterator - 2).getBlock().getPosition().y);

    }
    if(iterator == 3) {

        game_block.getBlock().setPosition(this->s_block.at(iterator - 1).getBlock().getPosition().x,
                                          this->s_block.at(iterator - 1).getBlock().getPosition().y);

    }

    game_block.at(1).getBlock().setPosition(game_block.at(2).getBlock().getPosition());
    game_block.at(2).getBlock().setPosition(game_block.at(0).getBlock().getPosition().x - 50*scale.x,
                                                  game_block.at(0).getBlock().getPosition().y);
    game_block.at(3).getBlock().setPosition(game_block.at(2).getBlock().getPosition().x,
                                               game_block.at(2).getBlock().getPosition().y)


}*/
