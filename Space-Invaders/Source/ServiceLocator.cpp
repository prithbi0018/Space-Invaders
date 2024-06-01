#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator() {
    // Constructor implementation
    graphicservice = nullptr;
}

ServiceLocator::~ServiceLocator() {
    // Destructor implementation
}

void ServiceLocator::createServices() {
    // Implementation of creating services
}

void ServiceLocator::clearAllServices() {
    // Implementation of clearing all services
}

ServiceLocator* ServiceLocator::getInstance() {
    // Implementation of getInstance
}

void ServiceLocator::initialize() {
    // Implementation of initialize
    graphicservice->initialize();
    return;
}

void ServiceLocator::update() {
    // Implementation of update
    return;
}

void ServiceLocator::render() {
    // Implementation of render
    graphicservice->render();
}
GraphicService* ServiceLocator::GetGraphicService()
{
    return  graphicservice;
}
