/*
 * GameStateTree.h
 *
 *  Created on: Nov 19, 2018
 *      Author: evdogg123
 */

#include "GameState.h"
#ifndef __GAMESTATETREE_H__
#define __GAMESTATETREE_H__
class GameStateTree{
public:
	GameState* startTree;
	~GameStateTree();
	GameStateTree(int player, int index, GameState* gameState);
	void GenerateGameTree(GameState* gameState, int player);
	GameState* ExecuteMove(GameState* currentGameState, int index);
	int SumChildScores(GameState* gameState);
	int DetermineBestMove(GameState* gameState);

};
#endif
