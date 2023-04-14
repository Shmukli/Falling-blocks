#include "Engine.h"

void engine::Engine::setGameField() {
/*
 * Ratio of width of the game field to width of menu is 3:1.
 * Size of gameblock is 50px * k (for both x and y) , where k = (gameplay width of your resolution/600px). Isn't final version
 * */
  loadBackGround("../asset/background_new.png");
  backgroundScale();

}

sf::Sprite &engine::Engine::getBackground() {

  return this->background;

}

Collision &engine::Engine::getCollision() {

  return collision;

}

void engine::Engine::initVariables() {

  this->timeFactor = 0.0f;
  this->speed = 1;
  this->collisionResult = false;
  this->plScore.score_value = 0;

  this->gameOverWindow = new sf::RenderWindow(this->videoMode, "GAMEOVER", sf::Style::Titlebar | sf::Style::Close);
  engine::Engine::previousPosition = new std::vector<sf::Vector2f>;
  engine::Engine::actual_blocks = new std::vector<object::GameBlock>;
  engine::Engine::stored_blocks = new std::vector<object::GameBlock>;
  object::GameBlock::textures = new std::vector<sf::Texture>();

}

void engine::Engine::backgroundScale() {

  this->background.setScale(this->scale.x, this->scale.y);

}

sf::Vector2f &engine::Engine::getScaleOfWindow() {

  return this->scale;

}

void engine::Engine::calculateScaleOfWindow() {

  this->sizeOfWindow = this->window->getSize();
  this->scale.x = ((static_cast<float>(sizeOfWindow.x) / 800));
  this->scale.y = ((static_cast<float>(sizeOfWindow.y) / 1000));

}

void engine::Engine::loadBackGround(std::string filename) {

  this->background_texture = new sf::Texture;

  if (!(this->background_texture->loadFromFile(filename))) {
    std::cout << "Oops, something went wrong!";
  } else {
    this->background.setTexture(*this->background_texture);
  }

}

void engine::Engine::createBlock() {

  int r_number = rand() % 5;

  if (r_number == 0) {
    object::ITypeBlock i_block(this->scale);

    if (!this->actual_blocks->empty()) {

      this->actual_blocks->clear();

    }
    for (int i = 0; i < i_block.getBlock().size(); ++i) {

      this->actual_blocks->emplace_back(i_block.getBlock().at(i));

    }

  }
  if (r_number == 1) {
    object::LTypeBlock l_block(this->scale);

    if (!this->actual_blocks->empty()) {

      this->actual_blocks->clear();

    }
    for (int i = 0; i < l_block.getBlock().size(); ++i) {

      this->actual_blocks->emplace_back(l_block.getBlock().at(i));

    }
  }

  if (r_number == 2) {
    object::SQUARETypeBlock SQUARE_block(this->scale);

    if (!this->actual_blocks->empty()) {

      this->actual_blocks->clear();

    }
    for (int i = 0; i < SQUARE_block.getBlock().size(); ++i) {

      this->actual_blocks->emplace_back(SQUARE_block.getBlock().at(i));

    }

  }

  if (r_number == 3) {
    object::STypeBlock s_block(this->scale);

    if (!this->actual_blocks->empty()) {

      this->actual_blocks->clear();

    }
    for (int i = 0; i < s_block.getBlock().size(); ++i) {

      this->actual_blocks->emplace_back(s_block.getBlock().at(i));

    }

  }
  if (r_number == 4) {
    object::TTypeBlock t_block(this->scale);

    if (!this->actual_blocks->empty()) {

      this->actual_blocks->clear();

    }
    for (int i = 0; i < t_block.getBlock().size(); ++i) {

      this->actual_blocks->emplace_back(t_block.getBlock().at(i));

    }

  }

}

const bool engine::Engine::gameWindowOpened() {

  return this->window->isOpen();

}

engine::Engine::Engine(int difficulty_coef) {
  this->difficulty_coefficient = difficulty_coef;

  initVariables();
  initWindow();
  initDifficulty();
  initScore();
  setGameField();

}

void engine::Engine::updateObject() {
  this->event_controller.move(*this->actual_blocks, this->scale);

}

engine::Engine::~Engine() {

  delete engine::Engine::previousPosition;
  delete engine::Engine::stored_blocks;
  delete engine::Engine::actual_blocks;
  delete object::GameBlock::textures;
  delete engine::Engine::background_texture;
  delete window;

}

void engine::Engine::render() {

  renderBlocks(*this->actual_blocks, *this->window);
  renderStoredBlocks(*this->stored_blocks, *this->window);
  renderText(*this->window);

}

void engine::Engine::constantMove(std::vector<object::GameBlock> &game_block) {

  this->bottomCollision = false;
  for (int i = 0; i < game_block.size(); ++i) {
    if (!this->actual_blocks->empty()) {

      if ((game_block.at(i).getBlock().getPosition().y
          + 2 * game_block.at(i).getBlock().getTexture()->getSize().y > sizeOfWindow.y)) {

        this->bottomCollision = true;
        addToStoredBLocks();
      }

    }
  }

  float time = clock.getElapsedTime().asMilliseconds();
  float tempFactor = time - timeFactor;
  if (!this->bottomCollision) {
    if (tempFactor >= speed * this->difficulty_coefficient) {

      timeFactor = time;
      for (int i = 0; i < game_block.size(); ++i) {

        game_block.at(i).move_down(game_block.at(i), this->scale);

      }
    }
  }
}

sf::RenderWindow *engine::Engine::getWindow() {

  return this->window;

}

void engine::Engine::renderBlocks(std::vector<object::GameBlock> &blocks, sf::RenderTarget &target) {

  this->clock.getElapsedTime();

  for (auto &block : blocks) {

    target.draw(block.getBlock());

  }
}

event::eventController &engine::Engine::getEventController() {

  return this->event_controller;

}

std::vector<object::GameBlock> &engine::Engine::getActualBlocks() {

  return *this->actual_blocks;

}

void engine::Engine::initWindow() {

  this->videoMode.height = 1000;
  this->videoMode.width = 800;

  this->window = new sf::RenderWindow(this->videoMode, "Tetris", sf::Style::Titlebar | sf::Style::Close);

  calculateScaleOfWindow();
  this->window->setFramerateLimit(60);

}

sf::Clock &engine::Engine::getClock() {
  return this->clock;
}

void engine::Engine::renderStoredBlocks(std::vector<object::GameBlock> &blocks, sf::RenderTarget &target) {

  for (auto &block : blocks) {

    target.draw(block.getBlock());

  }
}

std::vector<object::GameBlock> &engine::Engine::getStoredBlocks() {

  return *this->stored_blocks;

}

bool &engine::Engine::getCollisionResult() {

  return this->collisionResult;
}

void engine::Engine::setCollisionResult(bool collisionRes) {

  this->collisionResult = collisionRes;

}

void engine::Engine::addToStoredBLocks() {

  updateScore();
  for (auto &block : *this->actual_blocks) {

    this->stored_blocks->emplace_back(block);

  }
  this->actual_blocks->clear();

}

void engine::Engine::savePreviousPosition(std::vector<object::GameBlock> &block) {

  this->previousPosition->clear();
  if (!(block.empty())) {
    for (int i = 0; i < block.size(); ++i) {

      this->previousPosition->emplace_back(block.at(i).getBlock().getPosition());

    }
  }

}

std::vector<sf::Vector2f> &engine::Engine::getPreviousPosition() {
  return *this->previousPosition;
}

void engine::Engine::moveToPreviousPosition(std::vector<object::GameBlock> &block,
                                            std::vector<sf::Vector2f> &previousPosition) {

  if (!(block.empty())) {
    for (int i = 0; i < previousPosition.size(); ++i) {

      block.at(i).getBlock().setPosition(previousPosition.at(i));

    }
  }

}

void engine::Engine::initScore() {
  if (!this->myFont.loadFromFile("../asset/Cute Letters.ttf")) {
    std::cout << "Couldn't download font!";
  }
  this->plScore.score_string = std::to_string(this->plScore.score_value);
  this->score.setFont(myFont);
  this->score.setString(plScore.score_string);
  this->score.setFillColor(sf::Color::Red);
  this->score.setPosition(720 * this->scale.x, 50);
  this->description.setFont(myFont);
  this->description.setString("SCORE");
  this->description.setFillColor(sf::Color::Red);
  this->description.setPosition(700 * this->scale.x, 0);
}

void engine::Engine::renderText(sf::RenderTarget &target) {

  target.draw(this->difficulty_level);
  target.draw(this->difficulty_description);
  target.draw(this->score);
  target.draw(this->description);

}

void engine::Engine::updateScore() {
  this->plScore.score_value += 50;
  this->plScore.score_string = std::to_string(this->plScore.score_value);
  this->score.setString(plScore.score_string);

}

bool engine::Engine::gameOver(std::vector<object::GameBlock> &blocks) {
  for (int i = 0; i < blocks.size(); ++i) {

    if (blocks.at(i).getBlock().getPosition().y <= 300 * scale.y) {
      loadToFile();
      std::cout << "It works";
      return true;
    }

  }
}

sf::RenderWindow *engine::Engine::getGameOverWindow() {
  return this->gameOverWindow;
}

const bool engine::Engine::gameOverWindowOpened() {

  return this->gameOverWindow->isOpen();

}

void engine::Engine::setDifficulty(int difficulty_coefficient) {

  this->difficulty_coefficient = difficulty_coefficient;

}

void engine::Engine::loadToFile() {

  std::string difficulty_coeff_string = std::to_string(difficulty_coefficient);
  this->myFile.open("info.txt", std::ios_base::app);
  myFile << "Score" << "\t" << this->plScore.score_string << "\t" << "Slow" << "\t" << difficulty_coeff_string + "\n";
}

void engine::Engine::initDifficulty() {

  this->difficulty_level_string = std::to_string(this->difficulty_coefficient);
  this->difficulty_level.setFont(myFont);
  this->difficulty_level.setString(difficulty_level_string);
  this->difficulty_level.setFillColor(sf::Color::Red);
  this->difficulty_level.setPosition(720 * this->scale.x, 150);
  this->difficulty_description.setFont(myFont);
  this->difficulty_description.setString("SLOW");
  this->difficulty_description.setFillColor(sf::Color::Red);
  this->difficulty_description.setPosition(700 * this->scale.x, 100);
}




