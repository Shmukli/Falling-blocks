
#ifndef TETRIS_EVENTCONTROLLER_H
#define TETRIS_EVENTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "../object/GameBlock.h"
#include "../visual/Menu.h"
#define MAX_NUMBER_OF_OPTIONS 2

namespace event {
    class eventController {
    public:
        eventController();

        ~eventController();



        sf::Event getEvent();
        //Checking key events.
        //void constantMove(std::vector<object::GameBlock>& game_block, sf::Vector2f& scale);
        //void handleMenu(Menu& menu);

        void f1Help();
        void shutdownGame(sf::RenderWindow* window);
        void holdSizeOfWindow(sf::RenderWindow* window);
        void rotateEvent(std::vector<object::GameBlock> &game_block, sf::Vector2f& scale);
        void move(std::vector<object::GameBlock> &game_block, sf::Vector2f& scale);
        void ifWindowIsClosedEvent(sf::RenderWindow* window);
        void setEvent(sf::Event& event_non_member);
        void draw(sf::RenderWindow &window);




    private:

        bool leftCollision;
        bool rightCollision;

        sf::Vector2u sizeOfWindow;
        sf::Event event;







    };
}
#endif //TETRIS_EVENTCONTROLLER_H
