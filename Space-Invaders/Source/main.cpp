#include "../Header/Main/GameService.h"
#include "../Header/Element/ElementService.h"
int main() {
    
    GameService* gameService = new GameService;

   
    gameService->Ignite();

    Global::ServiceLocator::getInstance()->provide(new Element::ElementService());

    
    Global::ServiceLocator::getInstance()->getElementService()->initialize();


    
    while (gameService->isRunning()) {
        
        gameService->update();

        
        gameService->render();
    }
    





    return 0;
}
