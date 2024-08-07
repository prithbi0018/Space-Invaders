#pragma once

#include<SFML/Graphics.hpp>

class PlayerController;
class PlayerView
{
private:

	const sf :: String player_texture_path = "assets/textures/player_ship.png";
	const float player_sprite_width = 60.f;
	const float player_sprite_height = 60.f;
	PlayerController* playercontroller;

	sf::RenderWindow* game_window;


	sf::Texture player_texture;
	sf::Sprite player_sprite;

	void initializePlayerSprite();
	void scalePlayerSprite();

public:

	PlayerView();
	~PlayerView();

	void initialize(PlayerController * _playercontroler);
	void update();
	void render();


};