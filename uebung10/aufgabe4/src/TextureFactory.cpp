#include <SDL_image.h>
#include <iostream>
#include "TextureFactory.hpp"

TextureFactory::TextureFactory(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

TextureFactory& TextureFactory::instance(SDL_Renderer* renderer)
{
    static TextureFactory instance(renderer);
    return instance;
}

SDL_Texture *TextureFactory::loadTexture(std::string texFileName,
                                     unsigned char keyR,
                                     unsigned char keyG,
                                     unsigned char keyB)
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
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, keyR, keyG, keyB) );

        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface );
        if( newTexture == NULL )
        {
            std::cout <<  "Unable to create texture from! SDL Error: " << texFileName <<  SDL_GetError() << std::endl;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return newTexture;
}


SDL_Texture *TextureFactory::loadTexture(std::string texFileName)
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
        newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface );
        if( newTexture == NULL )
        {
            std::cout <<  "Unable to create texture from! SDL Error: " << texFileName <<  SDL_GetError() << std::endl;
        }


        // Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}


SDL_Texture* TextureFactory::getTexture(const string& filename)
{
    // load texture if not loaded yet
    if (m_map[filename] == NULL)
    {
        m_map[filename] = loadTexture(filename);
        return m_map[filename]; //returns null if texture fails to load
    }
    // return texture if it was loaded already
    else return m_map[filename];
}

SDL_Texture* TextureFactory::getTexture(const string& filename, unsigned char r, unsigned char g, unsigned char b)
{
    // load texture if not loaded yet
    if (m_map[filename] == NULL)
    {
        m_map[filename] = loadTexture(filename, r, g, b);
        return m_map[filename]; //returns null if texture fails to load
    }
    // return texture if it was loaded already
    else return m_map[filename];
}


void TextureFactory::deleteTexture(SDL_Texture* texture)
{
    /* 
     * it           map iteraror
     * it->first    gives the key
     * it->second   gives the value
     */
    
    std::map< string, SDL_Texture* >::const_iterator it;
    string key;
    
    /* Search by value to find the key needed for the erase function */
    for(it=m_map.begin(); it!=m_map.end(); ++it)
    {
        if (it->second == texture)
        {
            key = it->first;
            break;
        }
    }

    SDL_DestroyTexture(texture);
    
    m_map.erase(key);
    
}

void TextureFactory::deleteTexture(string filename)
{   
    
    SDL_DestroyTexture(m_map[filename]);
    
    m_map.erase(filename);
}


void TextureFactory::deleteAll()
{   
    std::map< string, SDL_Texture* >::const_iterator it;
    
    //Iterate through map and destroy all textures
    for(it=m_map.begin(); it!=m_map.end(); ++it)
    {
        SDL_DestroyTexture(it->second); //it->second is the value
    }    
    
    //Removes(and destroys) all elements
    m_map.clear();
}















