/*
 * Game.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: twiemann
 */

#include "Game.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace jumper
{

Game::Game(MainWindow* mainWindow)
{
	m_player = 0;
	m_level = 0;
	m_layer = 0;
	m_network = 0;
	m_renderer = mainWindow->getRenderer();
	m_scoreBoard = 0;
	m_pathPlanner = 0;
	m_path = 0;
	m_pathFollower = 0;
	m_windowWidth = mainWindow->w();
	m_windowHeight = mainWindow->h();
	m_focusActor = 0;

	SDL_SetRenderDrawColor(m_renderer, 0, 102, 204, 255);
}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

void Game::setPlayer(Player* player)
{
	m_player = player;
	m_focusActor = player;
	m_actors.push_back(player);
	m_renderables.push_back(player);
}

void Game::setLevel(Level* level)
{
	m_level = level;
	m_renderables.push_back(level);
}

void Game::addActor(Actor* actor)
{
	m_actors.push_back(actor);
	m_renderables.push_back(actor);
}

void Game::update(const Uint8* &currentKeyStates)
{
	// Reset forces and jump flags
	m_player->physics().setMoveForce(Vector2f(0.0, 0.0));
	m_player->wantsToJump(false);

	if( currentKeyStates[ SDL_SCANCODE_UP ] )
	{

	}
	if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
	{

	}
	if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
	{
		m_player->physics().setMoveForce(Vector2f(-800.0, 0.0));

	}
	if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
	{
		m_player->physics().setMoveForce(Vector2f(800.0, 0.0));
	}
	if( currentKeyStates[ SDL_SCANCODE_SPACE ])
	{
		m_player->wantsToJump(true);
	}
	if( currentKeyStates[SDL_SCANCODE_A ] )
	{
		if(m_pathFollower && m_level && !m_pathFollower->running())
		{
			m_pathFollower->setPath( m_pathPlanner->getSolution());
			m_pathFollower->start(*m_level);
			m_focusActor = m_pathFollower;
		}
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 102, 204, 255);
	SDL_RenderClear(m_renderer);

	if(m_layer)
	{
		m_layer->render();
	}

	if(m_scoreBoard)
	{
		m_scoreBoard->setScore(m_player->physics().position().x());
		m_scoreBoard->render();
	}

	for(size_t i = 0; i < m_renderables.size(); i++)
	{
		m_renderables[i]->render();
	}

	if(m_network)
	{
		m_network->render();
	}

	if(m_path)
	{
		m_path->render();
	}

	if(m_pathFollower)
	{
		m_pathFollower->render();
	}

	updateCameraPosition(m_focusActor);

	// Update screen
	SDL_RenderPresent(m_renderer);

}

void Game::start()
{
	for(size_t i = 0; i < m_actors.size(); i++)
	{
		m_actors[i]->start(*m_level);
	}
}

void Game::setNetwork(Network* net)
{
	m_network = net;

	// Generate new path planner
	if(m_pathPlanner)
	{
		delete m_pathPlanner;
	}
	m_pathPlanner = new PathPlanner(net);
	m_pathPlanner->planPath(net->getStart(), net->getGoal());

	if(m_path)
	{
		delete m_path;
	}
	m_path = new Path(m_renderer, m_pathPlanner->getSolution());

}

void Game::updateCameraPosition(Actor* a)
{
	if(a)
	{
		int new_x = 0;
		int new_y = 0;

		if(fabs(a->position().x() > m_windowWidth / 2))
		{
			new_x = a->position().x() - m_windowWidth / 2;
		}
		if(fabs(a->position().y() > m_windowHeight / 2))
		{
			new_y = a->position().y() - m_windowHeight / 2;
		}

		// Update cam position
		Vector2i position(new_x, new_y);
		Renderable::m_camera.move(position);
	}
}

} /* namespace jumper */
