#ifndef RENDERABLE_HPP_
#define RENDERABLE_HPP_

#include <SDL.h>
#include <string>
#include "Pixel.hpp"

using namespace jumper;

class Renderable
{
    protected:
    SDL_Renderer*   m_renderer;
    SDL_Texture*    m_texture;
    Pixel*          m_position;
    int			    m_width;
	int				m_height;

    public:
    /// Default-Konstruktor
    Renderable();
    
    /// Ein-Argument-Konstruktor
    Renderable(SDL_Renderer* renderer);
    
    /// Copy Konstuktor
    Renderable(Renderable& tocopy);    
    
    /// Konstruktor zum Laden von Texturen
    Renderable(std::string filename, SDL_Renderer* renderer);
    
    SDL_Texture* loadTexture(std::string texFileName);
    
    SDL_Texture*loadTextureWithKey(std::string texFileName, int r, int g, int b);
        
    virtual void render() = 0;
    
    /// Destructor
    ~Renderable();
};

#endif

