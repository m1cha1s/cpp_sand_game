#include <iostream>
#include <SFML/Graphics.hpp>
#include <pe.hpp>

#define DW 1000
#define DH 1000

sf::Clock deltaClock;
sf::Time dt;

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(DW,DH), "Sand game");
    pe::PE eng(100, 100, DW, DH);

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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            eng.set_particle(window.mapPixelToCoords(sf::Mouse::getPosition(window)), pe::SAND);


        if(deltaClock.getElapsedTime().asSeconds() >= 0.01)
        {
            dt = deltaClock.restart();
            
            eng.update();  
        }

        window.clear();
        eng.draw(&window);
        window.display();        
    }
}
