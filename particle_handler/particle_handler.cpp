#include <SFML/Graphics.hpp>
#include "particle_handler.hpp"
#include "../particle/particle.hpp"

Particle_handler::Particle_handler(int x, int y, float winX, float winY) 
{
    world.resize(x);
    for(int i = 0; i < world.size(); i ++) 
    {
        world[i].resize(y);
        for(int y = 0; y < world[i].size(); y ++) 
            world[i][y] = {NONE, 0, sf::Vector2i(0,0)};
    }

    particleSize = sf::Vector2f(winX/x, winY/y);
}

void Particle_handler::spawnParticle(int x, int y, particle_type_t type, double mass) 
{
    world[x][y] = {type, mass, sf::Vector2i(0,0)};
}


void Particle_handler::update() 
{
    for(int x = 0; x < world.size(); x ++) 
    {
        for(int y = 0; y < world[x].size(); y ++) 
        {
            bool foundPos = false;
            sf::Vector2i target;
            for(int _x = -1; _x < 2; _x ++) 
            {
                for(int _y = -1; _y < 2; _y ++) 
                {
                    if(x+_x < 0 || x+_x >= world.size() || y+_y < 0 || y+_y >= world[x].size() || (x == _x && y == _y)) continue;
                    
                    switch (world[x][y].type)
                    {
                    case SAND:
                        if(_x == -1)
                            if(world[x+_x][y+_y].type == NONE) {
                                foundPos = true;
                                target = sf::Vector2i(x+_x, y+_y);
                            }
                        break;
                    
                    default:
                        break;
                    }
                    if(foundPos) break;
                }
                if(foundPos) break;
            }         
            if(foundPos) 
            {
                world[target.x][target.y] = world[x][y];
                world[x][y] = {NONE, 0, sf::Vector2i(0,0)};
            }
        }
    }
}

void Particle_handler::draw() 
{
    for(int x = 0; x < world.size(); x ++) 
    {
        for(int y = 0; y < world[x].size(); y ++) 
        {
            switch (world[x][y].type)
            {
            case SAND:
                // sf::RectangleShape()
                break;
            
            default:
                break;
            }
        }
    }
}