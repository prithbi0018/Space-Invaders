#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Main/GameService.h"
#include "../Global/ServiceLocator.h"


    class GameService {
    private:
        
        Global::ServiceLocator* serviceLoctor;
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








