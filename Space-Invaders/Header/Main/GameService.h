
#pragma once

#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h" 

namespace main { 
    class GameService {
    private:
        Global::ServiceLocator* serviceLocator; 
        sf::RenderWindow* gameWindow;

        void initialize();
        void destroy();

    public:
        GameService();
        ~GameService();

        void Ignite();
        void update();
        void render();
        bool isRunning();
    };
}
