#define SFML_STATIC
#include "render/Sprite.h"
#include "Menu.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//Initiates the window and window events
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Romwell CCG");
sf::Event event;

/*
* contains the game loop
*/
int main()
{
    srand (time(NULL));
    Menu m;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        m.DrawBackground();
        window.display();
    }

    int pause;
    cin >> pause;
    return 0;
}
