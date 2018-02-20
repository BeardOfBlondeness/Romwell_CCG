#define SFML_STATIC
#include "render/Sprite.h"
#include "game/Game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
//Initiates the window and window eventsss
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Romwell CCG");
sf::Event event;

/*
* contains the game loop
*/
int main()
{
    srand (time(NULL));
    Sprite cartoon("cartoon.png");
    int arr1[31];
    int arr2[31];
    for(int i = 0; i<31; i++) {
      arr1[i] = i;
      arr2[i] = i;
    }
    Game g(arr1, arr2);
    g.WaitForTurn(false);
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

    int pause;
    cin >> pause;
    return 0;
}
