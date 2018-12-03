/*
 * GameStateTree.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: evdogg123
 */
#include <iostream>
#include "GameStateTree.h"
#include "GameState.h"
using namespace std;
	GameState* startTree;

GameStateTree::GameStateTree(int player, int index, GameState* gameState){
	startTree = gameState;
	startTree->insertTic(player, index);
	if (player == 1)
		GenerateGameTree(startTree, 2);
	else{
		GenerateGameTree(startTree, 1);
	}
}
GameStateTree::~GameStateTree(){
	delete startTree;
}
void GameStateTree::GenerateGameTree(GameState* gameState, int player){
	//DEFINITELY PROBLEM CHILD
	if (gameState->isFull() ){
		return;
	}
	else if(gameState->DetermineScore() != 0){
		return;
	}
	for (int idx = 0; idx < 9; idx++){
		if (gameState->board[idx] != 1 && gameState->board[idx] != 2){
			gameState->children[idx] = new GameState(); ///Not sure if this line is correct
			gameState->children[idx]->parent = gameState;
			for (int i = 0; i <9 ; i++){
				gameState->children[idx]->board[i] = gameState->board[i];
			}
			gameState->children[idx]->board[idx] = player;
			if (player == 1)
				GenerateGameTree(gameState->children[idx],2);
			else{
				GenerateGameTree(gameState->children[idx],1);
			}
		}
	}
}
GameState* GameStateTree::ExecuteMove(GameState* currentGameState, int index){
	return currentGameState->children[index];

	}
int GameStateTree::SumChildScores(GameState* gameState){
	if (gameState == nullptr){
		return 0;
	}
	else{
		return (gameState->DetermineScore()+ SumChildScores(gameState->children[0]) +SumChildScores(gameState->children[1]) +
				SumChildScores(gameState->children[2]) + SumChildScores(gameState->children[3]) + SumChildScores(gameState->children[4]) +
				SumChildScores(gameState->children[5]) + SumChildScores(gameState->children[6]) +
				SumChildScores(gameState->children[7]) + SumChildScores(gameState->children[8]));
		}
}
int GameStateTree::DetermineBestMove(GameState* gameState){
	int bestScore = 1000000;
	int bestMove = 0;
	for (int i = 0; i < 9; i++){
		if (gameState->children[i] != nullptr){
			if (SumChildScores(gameState->children[i]) <= bestScore){
				bestScore = SumChildScores(gameState->children[i]);
				bestMove = i;
			}
		}
	}
	return bestMove;
}




