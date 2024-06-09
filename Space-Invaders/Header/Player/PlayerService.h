#pragma once
#include <SFML/Graphics.hpp>



class EventService;

class PlayerService
{
   
    private:
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        const std::string playerTexturePath = "assets/textures/player_ship.png";;
        sf::RenderWindow* gameWindow;
        void initializePlayerSprite();
        void processPlayerInput();

    public:
        PlayerService(const std::string& texturePath);
        ~PlayerService();

        void initialize(sf::RenderWindow* window);
        void update();
        void render();

        void move(float offsetX);
        int getMoveSpeed();
        sf::Vector2f getPlayerPosition();
    };




