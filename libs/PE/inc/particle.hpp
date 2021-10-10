#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

namespace pe
{
    typedef enum 
    {
        NONE,
        SAND,
    }particle_t;

    typedef struct 
    {
        bool falling = false;
        bool flying = false;

        particle_t type = NONE;

        sf::RectangleShape shape;

        sf::Vector2i vel;
        sf::Vector2i acc;   
    }particle;

} // namespace pe


#endif