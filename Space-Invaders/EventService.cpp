#include "../Space-Invaders/EventService.h"
#include "../../Header/GameService.h"
#include "../../Header/ServiceLocator.h"

EventService::EventService () { game_window = nullptr; }

EventService::~EventService() = default;

void EventService::initialize()
{
    game_window = ServiceLocator::getInstance()->GetGraphicService()->getGameWindow();
}

void EventService::update()
{
    
}

void EventService::processEvents()
{
    if (isGameWindowOpen()) {
        while (game_window->pollEvent(game_event)) {
            
            if (gameWindowWasClosed() || hasQuitGame())
            {
                game_window->close();
            }
        }
    }
}

bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); } 

bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }


bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }

bool EventService::isGameWindowOpen() { return game_window != nullptr; }

bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

bool EventService::pressedLeftKey() { return game_event.key.code == sf::Keyboard::Left; }

bool EventService::pressedRightKey() { return game_event.key.code == sf::Keyboard::Right; }