#include "ITypeBlock.h"

object::ITypeBlock::ITypeBlock(sf::Vector2f scale)
    : GameBlock{scale} {

  object::GameBlock base_block(scale);

  object::GameBlock first_block(scale);
  first_block.getBlock().setPosition(base_block.getBlock().getPosition().x - 50 * scale.x,
                                     base_block.getBlock().getPosition().y);
  object::GameBlock second_block(scale);
  second_block.getBlock().setPosition(base_block.getBlock().getPosition().x + 50 * scale.x,
                                      base_block.getBlock().getPosition().y);

  object::GameBlock third_block(scale);
  third_block.getBlock().setPosition(second_block.getBlock().getPosition().x + 50 * scale.x,
                                     base_block.getBlock().getPosition().y);
  this->I_block.push_back(base_block);
  this->I_block.push_back(first_block);
  this->I_block.push_back(second_block);
  this->I_block.push_back(third_block);

}

std::vector<object::GameBlock> object::ITypeBlock::getBlock() {

  return this->I_block;

}