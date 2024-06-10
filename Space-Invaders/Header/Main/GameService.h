#pragma once

#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h" 

namespace Main {

    enum class GameState {
        BOOT,
        MAIN_MENU,
        GAME_PLAY,
    };

    class GameService {
    private:
        static GameState current_state;
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

        static void setGameState(GameState new_state);
        static GameState getGameState(); 
    };
}
