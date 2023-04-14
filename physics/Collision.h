
#ifndef TETRIS_COLLISION_H
#define TETRIS_COLLISION_H
#include "../object/GameBlock.h"

class Collision {
 public:
  Collision();
  ~Collision() = default;

  bool resolveObjectCollision(std::vector<object::GameBlock> &object1,
                              std::vector<object::GameBlock> &object2);

 private:

  bool collisionDetected;

};

#endif //TETRIS_COLLISION_H
