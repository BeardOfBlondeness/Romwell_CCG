#include "render/Sprite.h"
#include <stdlib.h>
#include <time.h>
//Initiates the window and window eventsss
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong");
sf::Event event;

/*
* contains the game loop
*/
int main()
{
    srand (time(NULL));
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
