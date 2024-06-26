#include "../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel(){}
	EnemyModel::~EnemyModel(){}

	void EnemyModel::initialize()
	{
		enemy_position = referece_position;
	}
	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
		movement_direction = MovementDirection::RIGHT;
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}
	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}




}