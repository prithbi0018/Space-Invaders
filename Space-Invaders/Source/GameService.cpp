
#include "../Header/Main/GameService.h"
#include "../Header/Global/ServiceLocator.h"
#include "../Header/Event/EventService.h"


main::GameService::GameService() {
    serviceLocator = nullptr;
    initialize();
}

main::GameService::~GameService() {
    destroy();
}

void main::GameService::initialize() {
    serviceLocator = Global::ServiceLocator::getInstance();
}

void main::GameService::destroy() {
}
    
void main::GameService::Ignite() {
}

void main::GameService::update() {
    serviceLocator->getEventServiceInstance()->processEvents();
}

void main::GameService::render() {
}

bool main::GameService::isRunning() {
    return serviceLocator->GetGraphicService()->isGameWindowOpen();
}
