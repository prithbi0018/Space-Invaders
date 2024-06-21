#include "../Header/Bullet/BulletController.h"
#include "../Header/Bullet/BulletView.h"
#include "../Header/Bullet/BulletModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet
{
    using namespace Global;

    BulletController::BulletController(BulletType type)
    {
        bullet_view = new BulletView();
        bullet_model = new BulletModel(type);
    }

    BulletController::~BulletController()
    {
        delete bullet_view;
        delete bullet_model;
    }

    void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
    {
        bullet_model->setPosition(position);
        bullet_model->setMovementDirection(direction);
        bullet_view->initialize(this);
    }

    void BulletController::update()
    {
        updateProjectilePosition();
        bullet_view->update();
    }

    void BulletController::render()
    {
        bullet_view->render();
    }

    void BulletController::updateProjectilePosition()
    {
        sf::Vector2f currentPosition = bullet_model->getPosition();
        float speed = bullet_model->getSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        switch (bullet_model->getMovementDirection())
        {
        case Bullet::MovementDirection::UP:
            currentPosition.y -= speed;
            moveUp();
            break;

        case Bullet::MovementDirection::DOWN:
            currentPosition.y += speed;
            moveDown();
            break;
        }

        bullet_model->setPosition(currentPosition);
        handleOutOfBounds();
    }

    void BulletController::moveUp()
    {
        // Logic for moving the bullet up
        // This can be customized based on specific requirements
    }

    void BulletController::moveDown()
    {
        // Logic for moving the bullet down
        // This can be customized based on specific requirements
    }

    void BulletController::handleOutOfBounds()
    {
        sf::Vector2f currentPosition = bullet_model->getPosition();
        if (currentPosition.y < 0 || currentPosition.y > ServiceLocator::getInstance()->getWindowService()->getWindowHeight())
        {
            // Handle the bullet going out of bounds
            // This could involve marking the bullet for deletion or recycling it
        }
    }

    sf::Vector2f BulletController::getProjectilePosition()
    {
        return bullet_model->getPosition();
    }

    BulletType BulletController::getBulletType()
    {
        return bullet_model->getBulletType();
    }
}
