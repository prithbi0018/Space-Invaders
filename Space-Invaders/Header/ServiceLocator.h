#pragma once
#include "../Header/GraphicService.h"

class ServiceLocator
{
private:
	GraphicService* graphicservice;

	ServiceLocator();
	~ServiceLocator();


	void createServices(); 
	void clearAllServices(); 
	

public:
	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();
	void setgamewindow();
	void remove();








};

