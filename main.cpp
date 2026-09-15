#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "First Window");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({300.f, 200.f});

    sf::RectangleShape rect({150.f, 100.f});
    rect.setFillColor(sf::Color::Red);
    rect.setPosition({100.f, 100.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* keypress = event->getIf<sf::Event::KeyPressed>())
            {
                if (keypress->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(rect);
        window.draw(circle);
        window.display();
    }

    return 0;
}