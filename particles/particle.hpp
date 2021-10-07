#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

typedef struct 
{
    sf::Vector2f pos;
} Particle;

class Particle_handler
{
private:
    // sf::Vector2f displaySize;
    bool grid[100][100];
public:
    Particle_handler();
    ~Particle_handler();

    void spawnParticle(sf::Vector2i pos);
    void update();
    void draw();
};

#endif