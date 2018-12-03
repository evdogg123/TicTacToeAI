/*
 * main.cc
 *
 *  Created on: Nov 14, 2018
 *      Author: evdogg123
 */
#include "Game.h"
#include <iostream>
#include "GameState.h"
#include "GameStateTree.h"

using namespace std;
int getUserMove();

int main(int argc,char** argv){

	Game* game = new Game();
	int currentPlayer = 2;
	cout<<"Welcome to Tic-Tac-Toe"<<endl;
	cout<<"The Computer is X and you are O"<<endl;
	game->currentBoard->DisplayBoard();
	cout<<"The Computer Goes First:"<<endl;
		int firstMove = game->gameTree->DetermineBestMove(game->currentBoard);
		game->StartGame(currentPlayer,firstMove);
		currentPlayer = 1;
		game->currentBoard->DisplayBoard();


	while (!(game->currentBoard->isFull()) && (game->currentBoard->DetermineScore() == 0)){

		if (currentPlayer == 1){
			int move = getUserMove();
			game->updateGameState(move);
			game->currentBoard->DisplayBoard();
			currentPlayer = 2;
		}
		else{
			int move = game->gameTree->DetermineBestMove(game->currentBoard);
			game->updateGameState(move);
			cout<<"Computer Move:"<<endl;
			game->currentBoard->DisplayBoard();

			currentPlayer = 1;
		}

	}
	if (game->currentBoard->DetermineScore() == -10){
		game->currentBoard->DisplayBoard();
		cout<<"The Computer Wins!"<<endl;
	}
	else if(game->currentBoard->DetermineScore() == 10){
		game->currentBoard->DisplayBoard();
		cout<<"The User Wins. Bad bot"<<endl;
		}
	else{
		game->currentBoard->DisplayBoard();
		cout<<"It was a tie"<<endl;


}


}


int getUserMove(){
	//Converts input on number pad to index of array
		cout<< "Enter your move on the number-pad (9 is top right, 1 is bottom left)"<<endl;
		int input;
		cin >> input;
		if (0<input && input <3){
			return input +5;
		}
		if (input == 4 || input == 5){
			return input -1;
		}
		if (6 <input && input < 10){
			return input - 7;
		}
		if (input == 6){
			return 5;
		}
		if (input == 3){
			return 8;
		}
		else{
			return -1;
		}

	}

