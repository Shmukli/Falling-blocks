#include "Collision.h"


Collision::Collision() {

    this->collisionDetected = false;


}


bool
Collision::resolveObjectCollision(std::vector<object::GameBlock> &object1, std::vector<object::GameBlock> &object2) {


    if (!(object1.empty()) && !(object2.empty())) {
        this->collisionDetected = false;
        if (!this->collisionDetected) {
            for (int i = 0; i < object1.size(); ++i) {
                for (int j = 0; j < object2.size(); ++j) {
                    if (object1.at(i).getBlock().getGlobalBounds().intersects(
                            object2.at(j).getBlock().getGlobalBounds())) {
                        std::cout << "COLLISION DETECTED";
                        return this->collisionDetected = true;

                    }
                }
            }
        }

    }

}
