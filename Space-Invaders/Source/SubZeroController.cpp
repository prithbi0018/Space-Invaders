#include "../Header/Enemy/Controller/SubZeroController.h"

namespace Enemy
{
    namespace Controller
    {
        // Constructor implementation
        SubzeroController::SubzeroController()
        {
            // Initialization code for SubzeroController if needed
        }

        // Destructor implementation
        SubzeroController::~SubzeroController()
        {
            // Cleanup code for SubzeroController if needed
        }

        // Override the initialize method
        void SubzeroController::initialize()
        {
            // Initialization code specific to SubzeroController
            // For example, setting initial position, state, etc.
        }

        // Override the move method
        void SubzeroController::move()
        {
            // Movement code specific to SubzeroController
            // This could include logic to move in different directions based on conditions
            moveDown(); // Example call to moveDown method
        }

        // Method to specify downward movement
        void SubzeroController::moveDown()
        {
            // Code to move the enemy down
            // For example: changing the y-coordinate by vertical_movement_speed
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
            current
