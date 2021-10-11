#ifndef PE_HPP
#define PE_HPP

#include <vector>

#include "particle.hpp"

namespace pe
{
    class PE
    {
    private:
        std::vector<std::vector<pe::particle>> grid;

        sf::Vector2f particle_size;
    public:
        PE(int Gw, int Gh, int Sw, int Sh);
        ~PE();

        void update();
        void draw(sf::RenderWindow* window);
        void set_particle(sf::Vector2f pos, particle_t p);
    };    
} // namespace pe


#endif