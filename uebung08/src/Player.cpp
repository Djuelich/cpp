#include "Player.hpp"
#include <SDL.h>
#include <iostream>
#include <fstream>

/* Konstruktor zum Laden von Texturen */
Player::Player(std::string filename,SDL_Renderer* renderer) 
{   
    m_renderer  = renderer;
    m_texture   = 0;
    m_width     = 0;
    m_height    = 0;
    m_anim_num  = 0;
    m_position  = new Pixel(400,300);
    
    
    std::ifstream in(filename.c_str());
	std::string texFileName;


	if(in.good())
	{
		in >> texFileName;
		in >> m_width >> m_height;
		in >> m_anim_num;
	}
	else
	{
		std::cout << "Unable to open file " << filename << std::endl;
	}
	
     m_texture = loadTexture(texFileName);
}

/* Copy function */
void Player::copy(const Player& tocopy)
{
    m_renderer  = tocopy.m_renderer;
    m_texture   = tocopy.m_texture;
    m_width     = tocopy.m_width;
	m_height    = tocopy.m_height;
	m_anim_num  = tocopy.m_anim_num;   
}
/* Copy Konstuktor */
Player::Player(Player& tocopy)
{
    copy(tocopy);
}

Player Player::operator=(const Player& other)
{
    if (this == &other) 
    {
        return *this;
    }

    copy(other);
  
    return *this;
}

void Player::render()
{
	if(m_renderer && m_texture)
	{
		int i;
		SDL_Rect target;
		SDL_Rect source;

		/* Set target / source width and height to tile size,
		 * they never change
		 */
		target.w = m_width;
		target.h = m_height;

		source.w = m_width;
		source.h = m_height;


	    i = 0;
		
			

					/* Compute the position of the target on the screen */
					target.x = m_position->x();
					target.y = m_position->y();

					/* Compute the position of the source pixel data
					 * within the texture (no offset for first tiles)
					 */
					source.x = i * m_width;
					source.y = 0;

					/* Copy pixel date to correct position */
					SDL_RenderCopy( m_renderer, m_texture, &source, &target);
				
			
		
	}
	else
	{
	   std::cout << "Invalid texture: "  << m_texture << " \t" << "or renderer: " << m_renderer << std::endl; 
	   exit(1);
    }
}

void Player::move(Pixel& offset)
{
    *m_position += offset;
}

