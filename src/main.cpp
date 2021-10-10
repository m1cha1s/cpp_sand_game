#include <iostream>
#include <SFML/Graphics.hpp>
#include <pe.hpp>

sf::Clock deltaClock;
sf::Time dt;

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(500,500), "Sand game");
    pe::PE eng(50, 50, 500, 500);

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
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            std::cout << pos.x << " " << pos.y << "\n";
            eng.set_particle(pos, pe::SAND);
        }

        eng.update();

        window.clear();
        eng.draw(&window);
        window.display();

        dt = deltaClock.restart();
        
    }
}
