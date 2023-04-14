
#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <fstream>
#include "../object/GameBlock.h"
#include "../object/ITypeBlock.h"
#include "../object/LTypeBlock.h"
#include "../object/SQUARETypeBlock.h"
#include "../object/STypeBlock.h"
#include "../object/TTypeBlock.h"
#include "../event/eventController.h"
#include "../physics/Collision.h"
#include "../visual/Menu.h"
#include <string>

struct player_score {
  int id;
  int score_value;
  std::string score_string;

};

namespace engine {
class Engine {
 public:
  Engine(int difficulty_coef);

  ~Engine();

  void initWindow();
  const bool gameWindowOpened();
  const bool gameOverWindowOpened();
  void setGameField();
  void loadBackGround(std::string filename);
  void backgroundScale();
  void calculateScaleOfWindow();
  void initVariables();
  void constantMove(std::vector<object::GameBlock> &game_block);
  void savePreviousPosition(std::vector<object::GameBlock> &block);
  std::vector<sf::Vector2f> &getPreviousPosition();
  sf::RenderWindow *getGameOverWindow();

  void updateBlock(std::vector<object::GameBlock> &game_block);

  void loadToFile();

  void setDifficulty(int difficulty_coefficient);

  void initDifficulty();

  void initScore();
  void updateScore();

  sf::Vector2f &getEndingLine();
  void moveToPreviousPosition(std::vector<object::GameBlock> &block, std::vector<sf::Vector2f> &previousPosition);
  void addToStoredBLocks();
  void setCollisionResult(bool collisionRes);
  bool &getCollisionResult();
  sf::Clock &getClock();
  Collision &getCollision();
  sf::RenderWindow *getWindow();
  sf::Sprite &getBackground();
  event::eventController &getEventController();
  std::vector<object::GameBlock> &getActualBlocks();
  std::vector<object::GameBlock> &getStoredBlocks();
  sf::Vector2f &getScaleOfWindow();
  void createBlock();

  // Game logic
  void render();
  void renderText(sf::RenderTarget &target);
  void renderStoredBlocks(std::vector<object::GameBlock> &block, sf::RenderTarget &target);
  void renderBlocks(std::vector<object::GameBlock> &block, sf::RenderTarget &target);
  void update();
  void updateObject();
  void spawnBlock();
  bool gameOver(std::vector<object::GameBlock> &blocks);

 private:

  bool bottomCollision;
  bool collisionResult;
  int difficulty_coefficient;
  int iterator;
  std::string iterator_string;

  std::ofstream myFile;

  float timeFactor;
  float speed;

  player_score plScore;

  //Menu menu;
  std::string difficulty_level_string;
  sf::Text difficulty_description;
  sf::Text difficulty_level;
  sf::Font myFont;
  sf::Text description;
  sf::Text score;
  sf::Clock clock;
  sf::Texture *background_texture;
  sf::Sprite background;
  event::eventController event_controller;
  Collision collision;

  sf::RenderWindow *gameOverWindow;
  sf::RenderWindow *window;
  sf::VideoMode videoMode;
  sf::Vector2u sizeOfWindow;
  sf::Vector2f scale;
  std::vector<sf::Vector2f> *previousPosition;
  std::vector<object::GameBlock> *actual_blocks;

  std::vector<object::GameBlock> *stored_blocks;

};
}
#endif //TETRIS_ENGINE_H
