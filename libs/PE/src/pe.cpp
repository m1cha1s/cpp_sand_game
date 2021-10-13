#include <iostream>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <time.h>

#include "../inc/pe.hpp"

using namespace pe;

#define None_particle {false, false, NONE, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)}

PE::PE(int Gw, int Gh, int Sw, int Sh)
{
    std::srand(time(0));
    particle_size.x = Sw/Gw;
    particle_size.y = Sh/Gh;

    // grid.resize(2);

    // for(int i = 0; i < 2; i ++)
    // {
    //     grid[i].resize(Gh);
    //     for(int y = 0; y < Gh; y ++) 
    //     {
    //         grid[i][y].resize(Gw);
    //         for(int x = 0; x < Gw; x ++)
    //         {
    //             grid[i][y][x] = None_particle;
    //             grid[i][y][x].shape.setPosition(sf::Vector2f(x*particle_size.x, y*particle_size.y));
    //             grid[i][y][x].shape.setFillColor(sf::Color(0));
    //         }
    //     }
    // }
}

PE::~PE() 
{
    grid.clear();
}

void PE::update() 
{
    // for(int y = 0; y < grid[bank].size(); y ++) 
    // for(int x = 0; x < grid[bank][y].size(); x ++)
    // {
    //     grid[bank][y][x].shape.setPosition(sf::Vector2f(x*particle_size.x, y*particle_size.y));
    //     switch (grid[bank][y][x].type)
    //     {
    //     case NONE:
    //         grid[bank][y][x].shape.setFillColor(sf::Color(0));
    //         break;

    //     case SAND:
    //         grid[bank][y][x].shape.setFillColor(sf::Color(255, 255, 0));
    //         if(y+1 < grid[bank].size())
    //         {
    //             if(grid[bank][y+1][x].type == NONE)
    //             {
    //                 move(x, y, x, y+1);
    //                 break;
    //             }    
    //             if(x-1 > 0 && x+1 < grid[bank][y].size())   
    //             {
    //                 int rnd = (std::rand()%3)-1;
    //                 if(grid[bank][y+1][x-1].type == NONE && rnd == -1)
    //                 {
    //                     move(x, y, x-1, y+1);
    //                     break;
    //                 }
    //                 if(grid[bank][y+1][x+1].type == NONE && rnd == 1)
    //                 {
    //                     move(x, y, x+1, y+1);
    //                     break;
    //                 }
    //             }         
                
    //         }
                
    //         grid[!bank][y][x] = grid[bank][y][x];
    //         break;

    //     case WATER:
    //         grid[bank][y][x].shape.setFillColor(sf::Color(0, 0, 255));
    //         if(y+1 < grid[bank].size())
    //         {
    //             if(grid[bank][y+1][x].type == NONE)
    //             {
    //                 move(x, y, x, y+1);
    //                 break;
    //             }
    //         }    
    //         if((x-1 > 0 && x+1 < grid[bank][y].size()))
    //         {            
    //             int rnd = (std::rand()%3)-1;
    //             if(grid[bank][y][x-1].type == NONE && grid[!bank][y][x-1].type == NONE && rnd == -1)
    //             {
    //                 move(x, y, x-1, y);
    //                 break;
    //             }
    //             if(grid[bank][y][x+1].type == NONE && grid[!bank][y][x+1].type == NONE && rnd == 1)
    //             {
    //                 move(x, y, x+1, y);
    //                 break;
    //             }
    //         }
    //         grid[!bank][y][x] = grid[bank][y][x];
    //         break;
        
    //     default:
    //         break;
    //     }
    // }
    // switchBank();
}

void PE::draw(sf::RenderWindow& window)
{
    for(auto pos : grid)
        window.draw(pos.second.shape);
}

void PE::set_particle(sf::Vector2f pos, particle_t p)
{
    int x = (int)(pos.x/particle_size.x);
    int y = (int)(pos.y/particle_size.y);

    // std::cout << x << " " << y << std::endl;

    particle newParticle = {false, false, false, p, sf::RectangleShape(particle_size), sf::Vector2i(0,0), sf::Vector2i(0,0)};
    grid[{x, y}] = newParticle;
}

void PE::switchBank()
{
    // for(int y = 0; y < grid[bank].size(); y ++) 
    // for(int x = 0; x < grid[bank][y].size(); x ++)
    // {
    //     grid[bank][y][x] = None_particle;
    // }
    // bank = !bank;
}

void PE::move(int x, int y, int tx, int ty)
{
    grid[{tx, ty}] = grid[{x, y}];
    grid.erase({x,y});
    // grid[bank][y][x] = None_particle;
}

void PE::swap(int x, int y, int tx, int ty)
{

}

void PE::remove(int x, int y)
{
    grid.erase({x, y});
}