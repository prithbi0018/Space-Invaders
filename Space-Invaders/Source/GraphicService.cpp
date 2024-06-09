#include "../Header/Graphic/GraphicService.h"

GraphicService::GraphicService() {
	game_window = nullptr; 
	video_mode = nullptr; 
	
}

GraphicService ::~GraphicService() {

	onDestroy();
}


void GraphicService::update() {
	
}
void GraphicService::render() {
	game_window->clear(window_color);
	game_window->display();
		
}
void GraphicService::onDestroy() {
	delete(game_window);
	delete(video_mode);
}

bool GraphicService::isGameWindowOpen() {
	return game_window->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow() {
	return game_window;
}

sf::Color GraphicService::getWindowColor() {
	return window_color;
}


void GraphicService::initialize() {
	game_window = createGameWindow(); 
}


sf::RenderWindow* GraphicService::createGameWindow() {
	setVideoMode(); 
	return new sf::RenderWindow(*video_mode, game_window_title); 
}


void GraphicService::setVideoMode() {
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); 
}


void GraphicService::initializeVariables()
{

}

