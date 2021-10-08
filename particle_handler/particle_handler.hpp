#ifndef PARTICLE_HANDLER_HPP
#define PARTICLE_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "../particle/particle.hpp"

class Particle_handler
{
private:
    std::vector<std::vector<particle_t>> world;
    sf::Vector2f particleSize;
public:
    Particle_handler(int x, int y, float winX, float winY);
    ~Particle_handler();

    void spawnParticle(int x, int y, particle_type_t type, double mass);
    void update();
    void draw();
};


#endif