#include"../Header/PlayerView.h"
#include"../Header/ServiceLocator.h"

PlayerView::PlayerView() {
	/*game_window = nullptr;
	playercontroller = nullptr;*/
}
PlayerView::~PlayerView() {}

void PlayerView::initialize(PlayerController * _playerController)
{
	playercontroller = _playerController;
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerView::initializePlayerSprite()
{
	if (player_texture.loadFromFile("assets/textures/player_ship.png"))
	{
		player_sprite.setTexture(player_texture);
		scalePlayerSprite();
	}
}
void PlayerView::scalePlayerSprite()
{

	player_sprite.setScale

		(static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
		static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y);
	
		
							
}

void PlayerView::update()
{
	
}

void PlayerView::render()
{
	game_window->draw(player_sprite);
}

