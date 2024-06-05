#pragma once
#include "../Header/GraphicService.h"
#include "../EventService.h"
#include "../Header/TimeService.h"

class ServiceLocator
{
private:
	GraphicService* graphicservice;
	EventService* eventServiceInstance;
	TimeService* timeServiceInstance;

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

	

};

