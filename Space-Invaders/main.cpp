#include <SFML/Graphics.hpp>

class Player {
public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    sf::Vector2f position;
    float move_speed;

    // Constructor
    Player() {
        move_speed = 5.0f; // Set default move speed
    }

    // Method to move the player
    void move(float direction) {
        // Update player position based on direction and move speed
        position.x += direction * move_speed;
    }

    // Method to get player position
    sf::Vector2f getPosition() {
        return position;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    Player player;
    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);
    player.position = sf::Vector2f(400.0f, 500.0f); // Set initial position

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handling input and movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f); // Move player left
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f); // Move player right
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Set the player position
        player.player_sprite.setPosition(player.getPosition());

        // Draw the player
        window.draw(player.player_sprite);

        // Display what was drawn
        window.display();
    }

    return 0;
}
