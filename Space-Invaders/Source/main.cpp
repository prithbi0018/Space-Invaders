#include "../Header/Main/GameService.h"

int main() {
    
    GameService* gameService = new GameService;

   
    gameService->Ignite();

    
    while (gameService->isRunning()) {
        
        gameService->update();

        
        gameService->render();
    }
    





    return 0;
}
