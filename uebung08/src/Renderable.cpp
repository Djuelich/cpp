#include "Renderable.hpp"
#include <SDL_image.h>
#include <iostream>
#include <fstream>


/* Default-Konstruktor */
Renderable::Renderable() :
    m_renderer(0),
    m_texture(0),
    m_width(0),
    m_height(0)
{
    
}

/* Ein-Argument-Konstruktor */
Renderable::Renderable(SDL_Renderer* renderer) :
    m_renderer(renderer),
    m_texture(0),
    m_width(0),
    m_height(0)
{
 
}
/* Konstruktor zum Laden von Texturen */
Renderable::Renderable(std::string filename, SDL_Renderer* renderer) :
    m_renderer(renderer),
    m_texture(0),
    m_width(0),
    m_height(0)
{   
    std::ifstream in(filename.c_str());
	std::string texFileName;


	if(in.good())
	{
		in >> texFileName;
		in >> m_width >> m_height;
	}
	else
	{
		std::cout << "Unable to open file " << filename << std::endl;
	}
	
     m_texture = loadTexture(texFileName);
}

/* Copy Konstruktor */
Renderable::Renderable(Renderable& tocopy)
{   
    m_renderer  = tocopy.m_renderer;
    m_texture   = tocopy.m_texture;
    m_width     = tocopy.m_width;
	m_height    = tocopy.m_height;
}

SDL_Texture* Renderable::loadTexture(std::string texFileName)
{
	// The loaded texture
	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(texFileName.c_str());
	if( loadedSurface == NULL )
	{
		std::cout << "Unable to load image! SDL_image Error: " <<  IMG_GetError() << std::endl;
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout <<  "Unable to create texture from! SDL Error: " << texFileName <<  SDL_GetError() << std::endl;
		}

		// Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;

}

SDL_Texture* Renderable::loadTextureWithKey(std::string texFileName, int r, int g, int b)
{
	// The loaded texture
	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(texFileName.c_str());
	if( loadedSurface == NULL )
	{
		std::cout << "Unable to load image! SDL_image Error: " <<  IMG_GetError() << std::endl;
	}
	else
	{
		// Set keying color
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, r, g, b) );

		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout <<  "Unable to create texture from! SDL Error: " << texFileName <<  SDL_GetError() << std::endl;
		}

		// Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;

}
    
Renderable::~Renderable()
{

}

