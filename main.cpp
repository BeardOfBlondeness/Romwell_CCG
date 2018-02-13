#include <SFML/Graphics.hpp>
#include "render/Sprite.h"

int main()
{

    Sprite cartoon("cartoon.png");

    cartoon.InitiateSprite();
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        cartoon.Draw();
        window.display();
    }

    return 0;
}