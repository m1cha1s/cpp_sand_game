#include <SFML/Graphics.hpp>
#include "../inc/pe.hpp"

using namespace pe;

PE::PE(int Gw, int Gh, int Sw, int Sh)
{
    particle_size.x = Sw/Gw;
    particle_size.y = Sh/Gh;

    grid.resize(Gh);
    for(int y = 0; y < Gh; y ++) 
    {
        grid[y].resize(Gw);
        for(int x = 0; x < Gw; x ++)
        {
            grid[y][x] = {false, false, NONE, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)};
            grid[y][x].shape.setPosition(sf::Vector2f(x*particle_size.x, y*particle_size.y));
            grid[y][x].shape.setFillColor(sf::Color(0));
        }
    }
}

PE::~PE() 
{
    grid.clear();
}

void PE::update() 
{
    for(int y = 0; y < grid.size(); y ++) 
    for(int x = 0; x < grid[y].size(); x ++)
    {
        switch (grid[y][x].type)
        {
        case NONE:
            grid[y][x].shape.setFillColor(sf::Color(0));
            break;

        case SAND:
            grid[y][x].shape.setFillColor(sf::Color(255, 0, 255));
            break;
        
        default:
            break;
        }
    }
}

void PE::draw(sf::RenderWindow* window)
{
    for(int y = 0; y < grid.size(); y ++) 
    for(int x = 0; x < grid[y].size(); x ++)
    {
        window->draw(grid[y][x].shape);
    }
}

void PE::set_particle(sf::Vector2i pos, particle_t p)
{
    grid[pos.y/particle_size.y][pos.x/particle_size.x] = {false, false, p, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)};
}