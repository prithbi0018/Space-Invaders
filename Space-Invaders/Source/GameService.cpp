
#include "../Header/Main/GameService.h"
#include "../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
namespace Main { 

    using namespace Global;

    GameState GameService::current_state = GameState::BOOT;

    GameService::GameService() : serviceLocator(nullptr), gameWindow(nullptr) {
        initialize();
    }

    GameService::~GameService() {
        destroy();
    }

    void GameService::initialize() {
        serviceLocator = ServiceLocator::getInstance();

        GraphicService* graphicService = serviceLocator->GetGraphicService();
        if (graphicService) {
            gameWindow = graphicService->getGameWindow();
        }
    }


    void GameService::destroy() {

    }

    void GameService::Ignite() {

    }

    void GameService::update() {
        serviceLocator->getEventServiceInstance()->processEvents();
    }

    void GameService::render() {

    }

    bool GameService::isRunning() {
        return gameWindow && gameWindow->isOpen();
    }
    void GameService::setGameState(GameState new_state) {
        current_state = new_state;
    }

    GameState GameService::getGameState() {
        return current_state;
    }
   

    
    

}
