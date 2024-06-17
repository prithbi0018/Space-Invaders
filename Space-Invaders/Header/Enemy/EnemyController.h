#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    private:
        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0; // Pure virtual function

        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController();
        virtual ~EnemyController();

        virtual void initialize() = 0; // Pure virtual function
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
    };
}
