#pragma once

#include "../Graphic/GraphicService.h"
#include "../Header/Event/EventService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService/UIService.h"
#include "../Gameplay/GameplayService.h"


namespace Global {
    class UIService;
    class ElementService;
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

        static ServiceLocator* instance;
        std::unique_ptr<ElementService> elementService;


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
        GameplayService* getGameplayService();

        
        void provideUIService(UI::UIService* uiService);
        UI::UIService* getUIService();

        void provide(ElementService* service)
        {
            elementService.reset(service);
        }

        ElementService* getElementService()
        {
            return elementService.get();
        }

    };
}
