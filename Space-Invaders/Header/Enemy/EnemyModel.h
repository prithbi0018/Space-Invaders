#pragma once
#include "SFML/Graphics.hpp"

namespace Enemy
{
	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
			sf::Vector2f enemy_position;

	public:
		EnemyModel();
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyPosition();
		sf::Vector2f setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		sf::Vector2f setReferencePosition(sf::Vector2f position);



	};
}