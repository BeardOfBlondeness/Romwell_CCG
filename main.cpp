#include <SFML/Graphics.hpp>
#include <cassert>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong");

    sf::Texture tex;
    sf::Sprite cartoon;

    assert(tex.loadFromFile("cartoon.png"));

    cartoon.setTexture(tex);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(cartoon);
        window.display();
    }

    return 0;
}