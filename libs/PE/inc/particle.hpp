#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

namespace pe
{
    typedef enum 
    {
        NONE,
        SAND,
        WATER,
    }particle_t;

    typedef struct
    {
        int x;
        int y;
    }vector;

    typedef struct 
    {
        bool updated = false;
        bool falling = false;
        bool flying = false;

        particle_t type = NONE;

        sf::RectangleShape shape;

        sf::Vector2i vel;
        sf::Vector2i acc;   
    }particle;

} // namespace pe


#endif