/*
 * GameState.h
 *
 *  Created on: Nov 19, 2018
 *      Author: evdogg123
 */
#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__
class GameState{
public:
	int board[9];
	GameState* children[9];
	GameState* parent;
	GameState();
	GameState(int player, int index, GameState* backPointer);
	~GameState();
	void insertTic(int player, int index);
	void insertChild(GameState* game, int index);
	bool isFull();
	void DisplayBoard();
	int DetermineScore();
};
#endif



