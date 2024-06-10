#include "../Header/Player/PlayerService.h"
#include"../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"



PlayerService::PlayerService(const std::string& texturePath) : playerTexturePath(texturePath) {
    gameWindow = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize(sf::RenderWindow* window) {
    gameWindow = window;
    initializePlayerSprite();
}

void PlayerService::update() {
    processPlayerInput();
    playerSprite.setPosition(getPlayerPosition());
}

void PlayerService::render() {
    gameWindow->draw(playerSprite);
}

void PlayerService::processPlayerInput() {
    EventService* event_service = Global::ServiceLocator::getInstance()->getEventServiceInstance();

    if (event_service->isKeyboardEvent()) {
        if (event_service->pressedLeftKey()) {
            move(-1.0f * getMoveSpeed());
        }

        if (event_service->pressedRightKey()) {
            move(1.0f * getMoveSpeed());
        }
    }
}

void PlayerService::initializePlayerSprite() {

    if (playerTexture.loadFromFile(playerTexturePath)) {
        playerSprite.setTexture(playerTexture);
    }
}


void PlayerService::move(float offsetX) {
    sf::Vector2f position = playerSprite.getPosition();
    position.x += offsetX;
    playerSprite.setPosition(position);
}

int PlayerService::getMoveSpeed() {
    return 5; 
}

sf::Vector2f PlayerService::getPlayerPosition() {
    return playerSprite.getPosition();
}
