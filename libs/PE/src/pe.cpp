#include <iostream>
#include <SFML/Graphics.hpp>
#include "../inc/pe.hpp"

using namespace pe;

#define None_particle {false, false, NONE, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)}

PE::PE(int Gw, int Gh, int Sw, int Sh)
{
    particle_size.x = Sw/Gw;
    particle_size.y = Sh/Gh;

    grid.resize(2);

    for(int i = 0; i < 2; i ++)
    {
        grid[i].resize(Gh);
        for(int y = 0; y < Gh; y ++) 
        {
            grid[i][y].resize(Gw);
            for(int x = 0; x < Gw; x ++)
            {
                grid[i][y][x] = None_particle;
                grid[i][y][x].shape.setPosition(sf::Vector2f(x*particle_size.x, y*particle_size.y));
                grid[i][y][x].shape.setFillColor(sf::Color(0));
            }
        }
    }
}

PE::~PE() 
{
    grid.clear();
}

void PE::update() 
{
    for(int y = 0; y < grid[bank].size(); y ++) 
    for(int x = 0; x < grid[bank][y].size(); x ++)
    {
        grid[bank][y][x].shape.setPosition(sf::Vector2f(x*particle_size.x, y*particle_size.y));
        switch (grid[bank][y][x].type)
        {
        case NONE:
            grid[bank][y][x].shape.setFillColor(sf::Color(0));
            break;

        case SAND:
            grid[bank][y][x].shape.setFillColor(sf::Color(255, 255, 0));
            if(y+1 < grid[bank].size())
            {
                if(grid[bank][y+1][x].type == NONE)
                {
                    move(x, y, x, y+1);
                    break;
                }                
                // std::cout<<"Debug1\n";
                if(grid[bank][y+1][x-1].type == NONE && x-1 > 0)
                {
                    // std::cout<<"Debug2\n";
                    move(x, y, x-1, y+1);
                    break;
                }
                if(grid[bank][y+1][x+1].type == NONE && x+1 < grid[bank][y].size())
                {
                    // std::cout<<"Debug2\n";
                    move(x, y, x+1, y+1);
                    break;
                }
            }
                
            grid[!bank][y][x] = grid[bank][y][x];
            break;
        
        default:
            break;
        }
    }
    switchBank();
}

void PE::draw(sf::RenderWindow* window)
{
    for(int y = 0; y < grid[bank].size(); y ++) 
    for(int x = 0; x < grid[bank][y].size(); x ++)
    {
        window->draw(grid[bank][y][x].shape);
    }
}

void PE::set_particle(sf::Vector2f pos, particle_t p)
{
    uint x = (uint)(pos.x/particle_size.x);
    uint y = (uint)(pos.y/particle_size.y);

    // std::cout << x << " " << y << std::endl;

    if(y < grid[bank].size() && x < grid[bank][0].size())
        grid[bank][y][x] = {false, false, p, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)};
}

void PE::switchBank()
{
    for(int y = 0; y < grid[bank].size(); y ++) 
    for(int x = 0; x < grid[bank][y].size(); x ++)
    {
        grid[bank][y][x] = None_particle;
    }
    bank = !bank;
}

void PE::move(int x, int y, int tx, int ty)
{
    grid[!bank][ty][tx] = grid[bank][y][x];
    // grid[bank][y][x] = None_particle;
}

void PE::swap(int x, int y, int tx, int ty)
{

}

void PE::remove(int x, int y)
{
    grid[!bank][x][y] = grid[bank][x][y] = None_particle;
}