#include "../Header/UI/MainMenuController/MainMenuController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../Header/Main/GameService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;

        MainMenuUIController::MainMenuUIController() : game_window(nullptr) {}

        MainMenuUIController::~MainMenuUIController() 
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeButtons();
            
        }
        void MainMenuUIController::processButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&play_button_sprite, mouse_position))
            {
                ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK); 
                ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic(); 
                GameService::setGameState(GameState::GAMEPLAY);
            }

            if (clickedButton(&instructions_button_sprite, mouse_position))
            {
                printf("Clicked Instruction Button \n");
            }

            if (clickedButton(&quit_button_sprite, mouse_position))
                game_window->close();
        }

        void MainMenuController::initializeBaclgroundImage()

        {
            if (background_texture.loadFromFile(background_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }
        void MainMenuController::scaleBackGroundImage()
        {
            background_sprite.setScale
            (
                static_cast<float>(game_window->getSize().x)/background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y)/background_sprite.getTexture()->getSize().y
            );          
        }

       
        void MainMenuUIController::initializeButtons()
        {
            
            if (loadButtonTexturesFromFile())
            {
              
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }
       
        bool MainMenuUIController::loadButtonTexturesFromFile()
        {
            return play_button_texture.loadFromFile(play_button_texture_path) &&
                instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(quit_button_texture_path);
        }

        void MainMenuUIController::setButtonSprites()
        {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }


        void MainMenuUIController::scaleAllButttons()
        {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            play_button_sprite.setPosition({ x_position, 500.f });
            instructions_button_sprite.setPosition({ x_position, 700.f });
            quit_button_sprite.setPosition({ x_position, 900.f });
        }

        void MainMenuUIController::processButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&play_button_sprite, mouse_position))
            {
                GameService::setGameState(GameState::GAMEPLAY);
            }

            if (clickedButton(&instructions_button_sprite, mouse_position))
            {
                printf("Clicked Instruction Button \\n");
            }

            if (clickedButton(&quit_button_sprite, mouse_position))
                game_window->close();
        }
        bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void MainMenuUIController::update()
        {

        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(play_button_sprite);
            game_window->draw(instructions_button_sprite);
            game_window->draw(quit_button_sprite);
        }
        void MainMenuUIController::destroy()
        {

        }

        void MainMenuUIController::setRenderWindow(sf::RenderWindow* window)
        {
            game_window = window;
        }
       

    }

}
