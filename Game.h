/*
 * Game.h
 *
 *  Created on: Nov 19, 2018
 *      Author: evdogg123
 */
#ifndef __GAME_H__
#define __GAME_H__
#include "GameState.h"
#include "GameStateTree.h"
class Game{
public:
	GameState* currentBoard;
	GameStateTree* gameTree;
	Game();
	~Game();
	void StartGame(int firstPlayer, int firstMove);
	void updateGameState(int index);

};
#endif

