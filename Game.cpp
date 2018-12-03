/*
 * Game.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: evdogg123
 */
#include "GameState.h"
#include "Game.h"
#include "GameStateTree.h"
#include <iostream>
using namespace std;

	GameState* currentBoard;
	GameStateTree* gameTree;
	Game::Game(){
		currentBoard = new GameState();
		gameTree = nullptr;
	}

	Game::~Game(){
		delete currentBoard;
		delete gameTree;
	}

	void Game::StartGame(int firstPlayer, int firstMove){
		//OPERATIONAL
		gameTree = new GameStateTree(firstPlayer, firstMove,currentBoard);
	}
	void Game::updateGameState(int index){
		currentBoard =  gameTree->ExecuteMove(currentBoard,index);
	}



