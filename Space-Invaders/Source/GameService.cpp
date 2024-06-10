
#include "../Header/Main/GameService.h"
#include "../Header/Global/ServiceLocator.h"

namespace main { 
    GameService::GameService() : serviceLocator(nullptr), gameWindow(nullptr) {
        initialize();
    }

    GameService::~GameService() {
        destroy();
    }

    void GameService::initialize() {
        serviceLocator = Global::ServiceLocator::getInstance();

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
}
