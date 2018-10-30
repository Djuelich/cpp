/*
 * Game.hpp
 *
 *  Created on: Dec 11, 2015
 *      Author: twiemann
 */

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include "MainWindow.hpp"
#include "Actor.hpp"
#include "Bot.hpp"
#include "Player.hpp"
#include "Path.hpp"
#include "Level.hpp"
#include "Network.hpp"
#include "TexturedLayer.hpp"
#include "ScoreBoard.hpp"
#include "PathPlanner.hpp"

#include <vector>

#include "PathFollower.hpp"
using std::vector;

namespace jumper
{

class MainWindow;

/*
 *
 */
class Game
{
public:

	/// Constructor
	Game(MainWindow* window);

	/// Destructor
	virtual ~Game();

	/// Sets the player object
	void setPlayer(Player* player);

	/// Sets the current level
	void setLevel(Level* level);

	/// Adds a new bot to the scene
	void addActor(Actor* actor);

	/// Updates the current state according to the given key states
	void update(const Uint8* &currentKeyStates);

	void start();

	void setLayer(TexturedLayer* layer) { m_layer = layer;}	;

	void setScoreBoard(ScoreBoard* b) { m_scoreBoard = b;};

	void setNetwork(Network* net);

	void setPathFollower(PathFollower* p) { m_pathFollower = p;};

private:

	/***
	 * Updates the camera position with focus on the given actor
	 */
	void updateCameraPosition(Actor* a);

	/// All renderables in the game
	vector<Renderable*> 	m_renderables;

	/// All actors
	vector<Actor*>			m_actors;

	/// The user controlled player
	Player*					m_player;

	/// The current level
	Level*					m_level;

	/// A Layer
	TexturedLayer*			m_layer;

	/// A score board
	ScoreBoard*				m_scoreBoard;

	/// Pointer to the main window of the game
	SDL_Renderer*			m_renderer;

	/// A Network
	Network*				m_network;

	/// A path planner
	PathPlanner*			m_pathPlanner;

	PathFollower*			m_pathFollower;

	/// A path
	Path*					m_path;

	/// The actor that has the camera focus
	Actor*					m_focusActor;

	/// Window width
	int						m_windowWidth;

	/// Window height
	int						m_windowHeight;


};

} /* namespace jumper */

#endif /* SRC_GAME_HPP_ */