#include <iostream>
#include<SFML/Graphics.hpp>

#include "particles/particle.hpp"

sf::Clock deltaClock;
sf::Time dt;

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(500,500), "Sand game");

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            default:
                break;
            }
        }

        window.clear();

        window.display();

        dt = deltaClock.restart();
        
    }
}
