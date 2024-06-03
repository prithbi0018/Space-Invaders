#include "../Header/GraphicService.h"


// Constructor: Initializes game window and video mode pointers to null.
GraphicService::GraphicService() {
	game_window = nullptr; // Initializes game window pointer to null
	video_mode = nullptr; // Initializes video mode pointer to null
	
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
	game_window = createGameWindow(); // Assigns a new game window to the game_window pointer
}

// Creates a new SFML RenderWindow object with specified video mode and title.
sf::RenderWindow* GraphicService::createGameWindow() {
	setVideoMode(); // Sets up the video mode for the window
	return new sf::RenderWindow(*video_mode, game_window_title); // Creates and returns a new RenderWindow object
}

// Sets up the video mode for the game window using specified dimensions and system's color depth.
void GraphicService::setVideoMode() {
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
}


void GraphicService::initializeVariables()
{

}

