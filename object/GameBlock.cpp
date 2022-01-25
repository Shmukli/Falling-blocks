#include "GameBlock.h"


std::vector<sf::Texture>* object::GameBlock::textures = nullptr;

object::GameBlock::GameBlock(sf::Vector2f scale){
    loadSprite();
this->sprite.setPosition(100*scale.x,50*scale.y);
this->sprite.setScale(scale.x, scale.y);


}



sf::Sprite& object::GameBlock::getBlock(){

    return this->sprite;

}

void object::GameBlock::loadSprite(){



   if(GameBlock::textures->empty()) {
        if (!(this->texture.loadFromFile("../asset/BLOCK_TEXTURE.png")))
        {
            std::cout << "Oops, something went wrong!";
        }
        GameBlock::textures->push_back(this->texture);
    }
    this->sprite.setTexture(GameBlock::textures->at(0));


}


void object::GameBlock::move_down(object::GameBlock &game_block, sf::Vector2f &scale){

    game_block.getBlock().setPosition(   game_block.getBlock().getPosition().x,
                                      game_block.getBlock().getPosition().y + 50*scale.y);

}


void object::GameBlock::move_left(object::GameBlock &game_block, sf::Vector2f& scale) {



        game_block.getBlock().setPosition(game_block.getBlock().getPosition().x - 50 * scale.x,
                                             game_block.getBlock().getPosition().y);


}





void object::GameBlock::move_right(object::GameBlock &game_block, sf::Vector2f& scale) {




        game_block.getBlock().setPosition(game_block.getBlock().getPosition().x + 50 * scale.x,
                                             game_block.getBlock().getPosition().y);




}

/*bool object::GameBlock::operator==(const object::GameBlock &rhs) {
    return false;
}*/

