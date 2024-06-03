#pragma once
#include "../Header/GraphicService.h"
#include "../EventService.h"
#include "../Header/TimeService.h"

class ServiceLocator
{
private:
	GraphicService* graphicservice;

	ServiceLocator();
	~ServiceLocator();


	void createServices(); 
	void clearAllServices(); 
	EventService* eventServiceInstance;

	




	

public:
	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();
	GraphicService* GetGraphicService();
	void provideEventService(EventService* eventService);
	EventService* getEventServiceInstance();

	

};

