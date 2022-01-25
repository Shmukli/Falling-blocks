#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/Engine.h"
#include "visual/Menu.h"

int main() {

    int difficulty_coefficient = 1000;
    bool selected;
    sf::VideoMode videoMode1;
    videoMode1.height = 1000;
    videoMode1.width = 800;

    sf::RenderWindow menuWindow(videoMode1, "Menu", sf::Style::Titlebar | sf::Style::Close);
    Menu menu(menuWindow.getSize().x, menuWindow.getSize().y, 1);

    while (menuWindow.isOpen()) {
        sf::Event event;

        while (menuWindow.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    selected = true;
                                    menuWindow.close();
                                    break;
                                case 1:
                                    std::cout << "Difficulty button has been pressed" << std::endl;
                                    difficulty_coefficient -= 200;

                                    break;
                                case 2:
                                    menu.showHistory();
                                    break;

                                case 3:
                                    menu.showHelp();
                                    break;

                                case 4:
                                    menuWindow.close();
                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    menuWindow.close();

                    break;

            }
        }


        menuWindow.clear(sf::Color::Black);
        menu.draw(menuWindow);
        menuWindow.display();
    }

    while (selected) {

        engine::Engine engine(difficulty_coefficient);
        engine.setDifficulty(difficulty_coefficient);
        srand((unsigned) time(NULL));
        engine.getClock().restart();
        selected = false;
        while (engine.gameWindowOpened() && !(engine.gameOver(engine.getStoredBlocks()))) {


            sf::Event event;
            if (engine.getActualBlocks().empty()) {
                engine.createBlock();
            }
            while (engine.getWindow()->pollEvent(event)) {    // Event controller check every event and handle it.
                engine.getEventController().shutdownGame(engine.getWindow());  // ESC - to shutdown game in every moment
                engine.getEventController().f1Help();
                engine.getEventController().setEvent(event);
                engine.getEventController().holdSizeOfWindow(engine.getWindow());  // size of window for collision
                engine.getEventController().ifWindowIsClosedEvent(engine.getWindow());




                //engine.getEventController().rotateEvent(engine.getActualBlocks(), engine.getScaleOfWindow()); // rotating in development
                engine.getEventController().move(engine.getActualBlocks(),
                                                 engine.getScaleOfWindow()); // checking move for actual block


            }

            engine.setCollisionResult(engine.getCollision().resolveObjectCollision(engine.getActualBlocks(), engine.getStoredBlocks()));
            if (!engine.getCollisionResult()) {                               // 100-113 -> handling object-object collision and object-floor
                engine.savePreviousPosition(engine.getActualBlocks());
                engine.constantMove(engine.getActualBlocks());
            }
            if (engine.getCollisionResult()) {

                engine.moveToPreviousPosition(engine.getActualBlocks(),
                                              engine.getPreviousPosition()); // if collision = true, we move block on previous pos
                engine.addToStoredBLocks();
                engine.setCollisionResult(false);
                engine.getActualBlocks().clear();
                engine.getPreviousPosition().clear();

            }
            engine.getWindow()->clear(sf::Color::Black);
            engine.getWindow()->draw(engine.getBackground());
            engine.render();

            engine.getWindow()->display();


        }


    }


    return 0;


}
