//
// Created by isaak on 25.11.15.
//

#ifndef JUMPER_RENDERABLE_H
#define JUMPER_RENDERABLE_H

#include <SDL.h>
#include <string>
#include "Camera.hpp"
#include "TextureFactory.hpp"

namespace jumper
{

class Renderable
{

public:

    /**
     * @brief Custom constructor
     * @param SDL_Renderer
     */
    Renderable(SDL_Renderer *m_renderer);

    /**
     * @brief   Renderer getter
     * @return  SDL_Renderer
     */
    SDL_Renderer *getRenderer() const;

    /**
    * @brief   Renders the object.
    */
    virtual void render() = 0;

    /// Returns the with of the rendered object
    int w() const;

    /// Returns the height of the rendered object
    int h() const;

protected:

    /// Renderer
    SDL_Renderer*		m_renderer;

    /// A texture object
    SDL_Texture*		m_texture;

	/// Source rect in the texture
	SDL_Rect 			m_sourceRect;
};

} /* namespace jumper */

#endif //JUMPER_RENDERABLE_H
