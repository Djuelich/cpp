//
// Created by isaak on 25.11.15.
//

#include <SDL_image.h>
#include <iostream>
#include "Renderable.hpp"

namespace jumper
{


Renderable::Renderable(SDL_Renderer* renderer)
	: m_renderer(renderer), m_texture(0)
{
	m_sourceRect.x = 0;
	m_sourceRect.y = 0;
	m_sourceRect.w = 0;
	m_sourceRect.h = 0;
}

SDL_Renderer *Renderable::getRenderer() const
{
    return m_renderer;
}



int Renderable::w() const
{
	return m_sourceRect.w;
}

int Renderable::h() const
{
	return m_sourceRect.h;
}


} /* namespace jumper */

