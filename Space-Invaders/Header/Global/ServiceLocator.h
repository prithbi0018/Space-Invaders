#pragma once

#include "../Graphic/GraphicService.h"
#include "../Header/Event/EventService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService/UIService.h"

namespace Global {
    class ServiceLocator {
    private:
        GraphicService* graphicservice;
        EventService* eventServiceInstance;
        TimeService* timeServiceInstance;
        UI::UIService* uiServiceInstance; 

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();
        void initialize();
        void update();
        void render();

        GraphicService* GetGraphicService();
        void provideEventService(EventService* eventService);
        EventService* getEventServiceInstance();
        GraphicService* getGraphicService();
        TimeService* getTimeService();

        
        void provideUIService(UI::UIService* uiService);
        UI::UIService* getUIService();
    };
}
