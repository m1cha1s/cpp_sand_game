#include "particle.hpp"

Particle_handler::Particle_handler() {

}

Particle_handler::~Particle_handler() {

}

void Particle_handler::spawnParticle(sf::Vector2i pos) {
    grid[pos.x][pos.y] = true;
}

void Particle_handler::update() {
    for(int x = 0; x < 100; x ++) {
        for(int y = 0; y < 100; y ++) {
            
        }        
    }
}

void Particle_handler::draw() {

}