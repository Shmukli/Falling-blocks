#include "STypeBlock.h"

object::STypeBlock::STypeBlock(sf::Vector2f scale)
    : GameBlock{scale} {

  object::GameBlock base_block(scale); //center


  object::GameBlock first_block(scale);
  first_block.getBlock().setPosition(base_block.getBlock().getPosition().x + 50 * scale.x, // right corner
                                     base_block.getBlock().getPosition().y);

  object::GameBlock second_block(scale);

  second_block.getBlock().setPosition(base_block.getBlock().getPosition().x,
                                      first_block.getBlock().getPosition().y + 50 * scale.y); // under center

  object::GameBlock third_block(scale);

  third_block.getBlock().setPosition(second_block.getBlock().getPosition().x - 50 * scale.x,
                                     second_block.getBlock().getPosition().y);
  this->s_block.push_back(base_block);
  this->s_block.push_back(first_block);
  this->s_block.push_back(second_block);
  this->s_block.push_back(third_block);

}

std::vector<object::GameBlock> &object::STypeBlock::getBlock() {

  return this->s_block;

}


