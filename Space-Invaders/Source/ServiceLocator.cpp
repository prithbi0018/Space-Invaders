#include "../Header/Global/ServiceLocator.h"
#include "../Header/Main/GameService.h"
#include "../Header/Event/EventService.h"
#include "../Header/Graphic/GraphicService.h"
#include"../Header/Element/ElementService.h"


namespace Global {
    using namespace Main;

    ServiceLocator::ServiceLocator()
        : graphicservice(nullptr), eventServiceInstance(nullptr), timeServiceInstance(nullptr), uiServiceInstance(nullptr),playerservice(nullptr),enemyservice(nullptr), gameplayServiceInstance(nullptr);ServiceLocatorinstance(nullptr);

    {
        createServices();
    }

    void ServiceLocator::provideEventService(EventService* eventService) {
        eventServiceInstance = eventService;
    }

    EventService* ServiceLocator::getEventServiceInstance() {
        return eventServiceInstance;
    }

    void ServiceLocator::createServices() {
        graphicservice = new GraphicService();
        eventServiceInstance = new EventService();
        timeServiceInstance = new TimeService();
        gameplayServiceInstance = new GameplayService();
    }

    void ServiceLocator::clearAllServices() {
        delete eventServiceInstance;
        delete graphicservice;
        delete timeServiceInstance;
        delete uiServiceInstance;
        delete gameplayServiceInstance;
    }

    ServiceLocator* ServiceLocator::getInstance() {
        static ServiceLocator instance;
        return &instance;
    }

    ServiceLocator::~ServiceLocator() {
        clearAllServices();
    }

    void ServiceLocator::initialize() {
        graphicservice->initialize();
    }

    void ServiceLocator::update()
    {
        graphic_service->update();
        time_service->update();
        event_service->update();
        if (GameService::getGameState() == GameState::GAMEPLAY)
        {
            player_service->update();
            enemy_service->update();
        }

        ui_service->update();   
    }

    void ServiceLocator::render() 
    {
        graphicservice->render();
        if (GameService::getGameState() == GameState::GAMEPLAY)
        {
            player_service->render();
            enemy_service->render();
        }
        ui_service->render();


    }
 
    GraphicService* ServiceLocator::GetGraphicService() {
        return graphicservice;
    }

    GraphicService* ServiceLocator::getGraphicService() {
        return graphicservice;
    }

    TimeService* ServiceLocator::getTimeService() {
        return timeServiceInstance;
    }

    
    void ServiceLocator::provideUIService(UI::UIService* uiService) {
        uiServiceInstance = uiService;
    }

    UI::UIService* ServiceLocator::getUIService() {
        return uiServiceInstance;
    }
    GameplayService* ServiceLocator::getGameplayService()
    {
        return gameplayServiceInstance;
    }
}
