#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "AnimatedRenderable.hpp"
#include "Pixel.hpp"

using namespace jumper;

class Player : AnimatedRenderable
{   
    private:
    int             m_anim_num;
    void copy(const Player& tocopy);
    public:
    
    /// Konstruktor zum Laden von Texturen
    Player(std::string filename, SDL_Renderer* renderer);
    
    /// Copy Konstuktor
    Player(Player& tocopy); 
    
    
    Player operator=(const Player& other);
    
    void move(Pixel& offset);
    
    void render();
};

#endif
