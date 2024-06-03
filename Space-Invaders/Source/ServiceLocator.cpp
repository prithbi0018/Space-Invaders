#include "../Header/ServiceLocator.h"



ServiceLocator::ServiceLocator()
{
    
    graphicservice = nullptr;
    eventServiceInstance = nullptr;
    
    createServices();
}
void ServiceLocator::provideEventService(EventService* eventService) {
    eventServiceInstance = eventService;
}
EventService* ServiceLocator::getEventServiceInstance()
{
    return eventServiceInstance;
}



void ServiceLocator::createServices()
{
    
    graphicservice = new GraphicService();
    eventServiceInstance = new EventService();
    // Initialize ServiceLocator with EventService
    EventService* eventServiceInstance = new EventService();
    ServiceLocator::getInstance()->provideEventService(eventServiceInstance);

    
}

void ServiceLocator::clearAllServices()
{
    delete eventServiceInstance;
    delete graphicservice;

}

ServiceLocator* ServiceLocator::getInstance()
{
    static ServiceLocator instance;
    return &instance;
}

ServiceLocator::~ServiceLocator()
{
    clearAllServices();
}
   





void ServiceLocator::initialize()
{
    
    graphicservice->initialize();
    return;
}

void ServiceLocator::update() 
{
    
    return;
}

void ServiceLocator::render()
{
    
    graphicservice->render();
}
GraphicService* ServiceLocator::GetGraphicService()
{
    return  graphicservice;
}
 