#include <SFML/Graphics.hpp>

class Player {
public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    sf::Vector2f position;

    // Constructor
    Player() {
        // Initialize player texture and sprite
        player_texture.loadFromFile("assets/textures/player_ship.png");
        player_sprite.setTexture(player_texture);
        // Set initial position
        position.x = 400; // Initial x-position
        position.y = 500; // Initial y-position
    }

    // Method to move the player
    void move(int direction) {
        // Update player position based on direction
        position.x += direction * 5; // Adjust movement speed as neededd
    }

    // Method to get player position
    sf::Vector2f getPosition() {
        return position;
    }
};

int main() {
    // Game window setup
    sf::VideoMode vm(800, 600); // Define the video mode
    sf::RenderWindow window(vm, "SFML Game"); // Create the game window

    // Player setup
    Player player; // Create a player object

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window if close event is detected
            }
        }

        // Handling input and rendering the player ship
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1); // Move player left
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1); // Move player right
        }

        window.clear(sf::Color::Blue); // Clear the window with blue color

        // Update player position and draw to screen
        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);

        window.display(); // Display the rendered frame
    }

    return 0;
}
