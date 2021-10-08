#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

enum particle_type_t {
    NONE,
    SAND,
    WATER,
};

typedef struct {
    particle_type_t type;
    double mass;
    sf::Vector2i vel;
} particle_t;

#endif