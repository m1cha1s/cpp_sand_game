#include <iostream>
#include <SFML/Graphics.hpp>

#include "particle/particle.hpp"
#include "particle_handler/particle_handler.hpp"

sf::Clock deltaClock;
sf::Time dt;



int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(500,500), "Sand game");
    // Particle_handler hdl(100, 100, 500, 500);

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
