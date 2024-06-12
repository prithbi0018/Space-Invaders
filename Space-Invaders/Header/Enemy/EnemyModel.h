#pragma once
#include "SFML/Graphics.hpp"

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};
	class EnemyModel
	{
	private:

		MovementDirection movement_direction;

		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
			sf::Vector2f enemy_position;

	public:
		EnemyModel();
		~EnemyModel();

		void initialize();

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

		const float vertical_travel_distance = 100.f;
		const float enemy_movement_speed = 250.0f;

		sf::Vector2f getEnemyPosition();
		sf::Vector2f setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		sf::Vector2f setReferencePosition(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);



	};
}