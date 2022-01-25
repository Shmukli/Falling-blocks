
#include "eventController.h"


event::eventController::eventController() {

    this->rightCollision = false;
    this->leftCollision = false;


}

event::eventController::~eventController() {


}


void event::eventController::ifWindowIsClosedEvent(sf::RenderWindow *window) {

    if (this->event.type == sf::Event::Closed)
        window->close();

}

void event::eventController::holdSizeOfWindow(sf::RenderWindow *window) {

    this->sizeOfWindow = window->getSize();

}

sf::Event event::eventController::getEvent() {

    return this->event;

}

void event::eventController::setEvent(sf::Event &event_non_member) {

    this->event.type = event_non_member.type;

}


/*void event::eventController::constantMove(std::vector<object::GameBlock> &game_block, sf::Vector2f &scale){


    for (int i = 0; i < game_block.size(); ++i) {
        if (game_block.at(i).getBlock().getPosition().x +
              game_block.at(i).getBlock().getTexture()->getSize().x < sizeOfWindow.y) {
            this->bottomCollision = true;
        }


    }
    if (!this->bottomCollision) {
        for (int i = 0; i < game_block.size(); ++i) {


            game_block.at(i).move_down(game_block.at(i), scale);
        }
    }
}*/


/*void event::eventController::rotateEvent(std::vector<object::GameBlock> &game_block, sf::Vector2f &scale){

    if (this->event.type == sf::Event::KeyPressed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){


            for (int i = 0; i < game_block.size(); ++i) {

                game_block.at(i).rotate(game_block.at(i),scale, i);

            }







        }
    }

}*/



void event::eventController::move(std::vector<object::GameBlock> &game_block, sf::Vector2f &scale) {


    if (this->event.type == sf::Event::KeyPressed) {

        this->rightCollision = false;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            for (int i = 0; i < game_block.size(); ++i) {
                if (game_block.at(i).getBlock().getPosition().x +
                    6 * game_block.at(i).getBlock().getTexture()->getSize().x > sizeOfWindow.x) {

                    this->rightCollision = true;

                }


            }
            if (!this->rightCollision) {
                for (int i = 0; i < game_block.size(); ++i) {

                    game_block.at(i).move_right(game_block.at(i), scale);

                }
            }
        }
    }

    if (this->event.type == sf::Event::KeyPressed) {

        this->leftCollision = false;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            for (int i = 0; i < game_block.size(); ++i) {

                if (game_block.at(i).getBlock().getPosition().x  <= 0) {

                    this->leftCollision = true;

                }


            }
            if (!this->leftCollision) {
                for (int i = 0; i < game_block.size(); ++i) {

                    game_block.at(i).move_left(game_block.at(i), scale);

                }
            }

        }
    }


}

void event::eventController::shutdownGame(sf::RenderWindow* window) {

    if(this->event.type == sf::Event::KeyPressed) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            sf::VideoMode videoMode1;
            videoMode1.height = 400;
            videoMode1.width = 400;

            sf::RenderWindow menuExitWindow(videoMode1, "Exit", sf::Style::Titlebar | sf::Style::Close);
            Menu menu(menuExitWindow.getSize().x, menuExitWindow.getSize().y, 2);
            while (menuExitWindow.isOpen()) {
                sf::Event event;

                while (menuExitWindow.pollEvent(event)) {
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
                                            window->close();
                                            menuExitWindow.close();
                                            break;
                                        case 1:
                                            std::cout << "Difficulty button has been pressed" << std::endl;
                                            menuExitWindow.close();

                                    }

                                    break;
                            }

                            break;
                        case sf::Event::Closed:
                            menuExitWindow.close();

                            break;

                    }
                }


                menuExitWindow.clear(sf::Color::Black);
                menu.draw(menuExitWindow);
                menuExitWindow.display();
            }


            // window->close();
        }
    }

}

void event::eventController::f1Help() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
        sf::VideoMode videoMode1;
        videoMode1.height = 512;
        videoMode1.width = 768;

        sf::RenderWindow menuHelpWindow(videoMode1, "Help", sf::Style::Titlebar | sf::Style::Close);
        while (menuHelpWindow.isOpen()) {
            sf::Event event_temp;
            while (menuHelpWindow.pollEvent(event_temp)) {
                if (event_temp.type == sf::Event::KeyPressed) {
                    if (event_temp.key.code == sf::Keyboard::Escape);
                    menuHelpWindow.close();
                    if (event_temp.type == sf::Event::Closed)
                        menuHelpWindow.close();
                }
            }

            sf::Texture helpScreen;
            helpScreen.loadFromFile("../asset/help_asset.png");
            sf::Sprite helpScreenToDraw;
            helpScreenToDraw.setTexture(helpScreen);
            menuHelpWindow.clear(sf::Color::Black);
            menuHelpWindow.draw(helpScreenToDraw);
            menuHelpWindow.display();


        }
    }

}


/*void event::eventController::handleMenu(Menu &menu) {
    switch(menu.GetPressedItem()){
        case 0:
            std::cout << "Play button has been pressed" << std::endl;
            break;
        case 1:
            std::cout << "Level button has been pressed" << std::endl;
            break;
        case 2:
            window.close();
            break;




    }*/




/*
sf::Event event::eventController::move_left(std::vector<object::GameBlock> &game_block, sf::Vector2f& scale) {
    if (event.type == sf::Event::KeyPressed) {
        if ((this->event.key.code == sf::Keyboard::A) || (this->event.key.code == sf::Keyboard::Left)) {
            for (auto &b: game_block) {
                game_block.front().getBlock().setPosition(game_block.front().getBlock().getPosition().x - 50 * scale.x,
                                                          game_block.front().getBlock().getPosition().y - 50 * scale.y);
            }

        }
    }
}



sf::Event event::eventController::move_right(std::vector<object::GameBlock> &game_block, sf::Vector2f& scale){
    if (this->event.type == sf::Event::KeyPressed) {
        if ((this->event.key.code == sf::Keyboard::D) || (this->event.key.code == sf::Keyboard::Right)) {
            for (auto &b: game_block) {
                game_block.front().getBlock().setPosition(game_block.front().getBlock().getPosition().x + 50 * scale.x,
                                                          game_block.front().getBlock().getPosition().y + 50 * scale.y);
            }

        }
    }
}*/

