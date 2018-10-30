#ifndef SRC_TEXTUREFACTORY_HPP
#define SRC_TEXTUREFACTORY_HPP

#include <map>
#include <string>
#include <SDL.h>

using namespace std;

class TextureFactory
{
    private:
    
    TextureFactory(SDL_Renderer* renderer);
    
    SDL_Renderer* m_renderer;
    
    map<string, SDL_Texture*> m_map;
    
    SDL_Texture *loadTexture(std::string texFileName,
                                     unsigned char keyR,
                                     unsigned char keyG,
                                     unsigned char keyB);
                                     
    SDL_Texture *loadTexture(std::string texFileName);  
    
    public:
    
    static TextureFactory& instance(SDL_Renderer* renderer);
    
    
    SDL_Texture* getTexture(const string& filename);
    
    
    SDL_Texture* getTexture(const string& filename, unsigned char r, unsigned char g, unsigned char b);
    
    
    void deleteTexture(SDL_Texture* texture);
    
    
    void deleteTexture(string filename);
    
    
    void deleteAll();
       
};

#endif
