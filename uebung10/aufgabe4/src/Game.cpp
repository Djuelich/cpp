/*
 * Game.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: twiemann
 */

#include "Game.hpp"

namespace jumper
{

Game::Game(MainWindow* mainWindow)
    :m_renderer(mainWindow->getRenderer())
{
    
}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

void Game::setPlayer(Player* player)
{
    m_player = player;
    m_renderables.push_back(player);
}

void Game::setLevel(Level* level)
{
    m_level = level;
    m_renderables.push_back(level);
}

void Game::addBot(Bot* bot)
{
    m_actors.push_back(bot);
}

void Game::update(const Uint8* &currentKeyStates)
{   
    int moveX = 0;
    int moveY = 0;
    bool jump = false;
    
    if( currentKeyStates[ SDL_SCANCODE_UP ] )
    {
	    moveY = -1;
    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
    {
	    moveY = 1;
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
    {
	    moveX = -1;
    }
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
    {
	    moveX = 1;
    }
    if( currentKeyStates[ SDL_SCANCODE_SPACE ])
    {
	    jump = true;
	    //std::cout << "jump!" << std::endl;
	    m_player->wantsToJump(true);
    }
    

    SDL_RenderClear(m_renderer);
    
    
    if(m_level)
    {
        m_level->render();
    }
    
    for (int i = 0;i < m_actors.size(); i++)
    {
        m_actors[i]->move(*m_level);
        m_actors[i]->render();
    }
    
    
    //Store default move-force
    Vector2f temp(m_player->physics().moveForce());
    
    //Change move-force to given direction and move the player
    m_player->physics().setMoveForce(temp * moveX);
    m_player->move(*m_level);
    m_player->render();
    
    //Set move-force back to default
    m_player->physics().setMoveForce(temp);
    
    
    
    SDL_RenderPresent(m_renderer);

}

} /* namespace jumper */
