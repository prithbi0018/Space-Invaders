#include "../Header/Global/ServiceLocator.h"

namespace Global {

    ServiceLocator::ServiceLocator()
        : graphicservice(nullptr), eventServiceInstance(nullptr), timeServiceInstance(nullptr), uiServiceInstance(nullptr)
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
    }

    void ServiceLocator::clearAllServices() {
        delete eventServiceInstance;
        delete graphicservice;
        delete timeServiceInstance;
        delete uiServiceInstance;
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

    void ServiceLocator::update() {
       
    }

    void ServiceLocator::render() {
        graphicservice->render();
        ui_service->render();
        player_service->render();

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
}
