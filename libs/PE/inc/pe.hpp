#ifndef PE_HPP
#define PE_HPP

#include <random>
#include <unordered_map>

#include "particle.hpp"

namespace pe
{
    class PE
    {
    private:
        bool bank = 0;
        std::unordered_map<vector, particle> grid;

        sf::Vector2f particle_size;

        void switchBank();
        void move(int x, int y, int tx, int ty);
        void swap(int x, int y, int tx, int ty);
        void remove(int x, int y);
    public:
        PE(int Gw, int Gh, int Sw, int Sh);
        ~PE();

        void update();
        void draw(sf::RenderWindow& window);
        void set_particle(sf::Vector2f pos, particle_t p);
    };    
} // namespace pe


#endif