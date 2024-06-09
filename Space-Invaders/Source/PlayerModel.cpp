#include "../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel() : player_alive(false), player_score(0) {}

PlayerModel::~PlayerModel() {}

void PlayerModel::initialize() {}
void PlayerModel::reset()
{
	player_alive = true;
	player_position = initial_player_position;
	player_score = 0;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return player_position;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}

bool PlayerModel::getPlayerAlive()
{
	return player_alive;
}

void PlayerModel::setPlayerAlive(bool alive)
{
	player_alive = alive;
}
