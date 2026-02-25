
#include "cxx_mirror.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/System/FileInputStream.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(800, 600)),
        "SFML works"
    );

    sf::SoundBuffer sndBuff("");

    sf::Sound snd(sndBuff);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }
}