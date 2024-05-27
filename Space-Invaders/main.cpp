#include <SFML/Graphics.hpp>

int main()
{
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game Window");

    
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       
        window.clear();

  
      
        window.display();
    }

    return 0;
}
