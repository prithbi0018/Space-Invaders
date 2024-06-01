#include "../Header/GameService.h"// Include the GameService header file

int main() {
    // Create an instance of GameService
    GameService* gameService = new GameService;

    // Call the Ignite() function to initialize the game
    gameService->Ignite();

    // Main game loop
    while (gameService->isRunning()) {
        // Update game state
        gameService->update();

        // Render game
        gameService->render();
    }

    return 0;
}
