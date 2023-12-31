// pongGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bat.h"
#include <sstream>
#include <cstdlib>


using namespace sf;
using namespace std;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Default);

    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);

    Text hud;
    Font font;
    font.loadFromFile("KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);
    hud.setFillColor(Color::White);

    Clock clock;

    while (window.isOpen())
    {

        //Handle player input


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        //Update objects

        Time dt = clock.restart();
        bat.update(dt);
        stringstream ss;
        ss << "Score: " << score << "  Lives: " << lives;
        hud.setString(ss.str());

        //Draw

        window.clear();
        window.draw(hud);

        window.draw(bat.getShape());

        window.display();





















    }



}
