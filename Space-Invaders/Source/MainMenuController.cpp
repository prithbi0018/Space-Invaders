#include "../Header/UI/MainMenuController/MainMenuController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;

        MainMenuUIController::MainMenuUIController() : game_window(nullptr) {}

        MainMenuUIController::~MainMenuUIController() {
            destroy();
        }

        void MainMenuUIController::initialize() {
            
        }

        void MainMenuUIController::update() {
            
        }

        void MainMenuUIController::render() {
            if (game_window) {
                game_window->clear();
               
                game_window->display();
            }
        }

        void MainMenuUIController::destroy() {
            
        }

        void MainMenuUIController::setRenderWindow(sf::RenderWindow* window) {
            game_window = window;
        }
    }
}
