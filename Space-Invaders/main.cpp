#include <SFML/Graphics.hpp>

int main()
{
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML Shapes Example");

    // Create a green circle
    sf::CircleShape circle(50); // Radius of 50
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 100); // Adjust position as needed

    // Create a red square
    sf::RectangleShape square(sf::Vector2f(100, 100)); // Width and height of 100
    square.setFillColor(sf::Color::Red);
    square.setPosition(250, 100); // Adjust position as needed

    // Create a blue triangle
    sf::ConvexShape triangle;
    triangle.setPointCount(3); // Triangle has 3 points
    triangle.setPoint(0, sf::Vector2f(0, 0)); // First point
    triangle.setPoint(1, sf::Vector2f(100, 0)); // Second point
    triangle.setPoint(2, sf::Vector2f(50, 100)); // Third point
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(400, 100); // Adjust position as needed

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the shapes
        window.draw(circle);
        window.draw(square);
        window.draw(triangle);

        // Display what has been drawn
        window.display();
    }

    return 0;
}
