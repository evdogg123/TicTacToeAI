/*
 * GameState.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: evdogg123
 */
#include "GameState.h"
#include <iostream>
using namespace std;


	GameState::GameState(){
		board[9] = {0};
		children[9] = {};
		parent = nullptr;
		for (int i = 0; i < 9; i++){
			children[i] = NULL;
		}
	}
	GameState::~GameState(){
		//TODO
		delete parent;
		delete children;
	}
	GameState::GameState(int player, int index,GameState* backPointer){
			board[9] = {0};
			board[index] = player;
			children[9] = {};
			parent = backPointer;
	}
	void GameState::insertTic(int player, int index){
		board[index] = player;
	}
	void GameState::insertChild(GameState* game, int index){
		children[index] = game;
	}
	bool GameState::isFull(){
		for (int i = 0; i < 9; i++){
			if (board[i] != 1 && board[i] != 2){
				return false;
			}
			}
 		return true;
		}
	void GameState::DisplayBoard(){
		//OPERATIONAL
		for (int idx = 0; idx < 9; idx++){
			if ((idx == 2 )|| (idx == 5) || (idx == 8))
				if (  board[idx] == 1)
					cout<<"[O]"<<endl;
				else if (board[idx] == 2){
					cout<<"[X]"<<endl;
				}
				else{
					cout<<"[-]"<<endl;
				}
			else{
				if (board[idx] == 1)
					cout<<"[O]";
				else if (board[idx] == 2){
					cout<<"[X]";
					}
				else{
					cout<<"[-]";
					}
		}
	}
	}

	int GameState::DetermineScore(){
	//WORKS AS FAR AS I KNOW
		//Disgusting algorithim but it hopefully works

		if ((   board[0]  ==1 ) && (  board[1] ==1 ) && (  board[2] == 1))
				return 10;

		else if ((   board[0]  == 2 ) && (  board[1] == 2 ) && (  board[2] == 2)){
				return -10;
			}

		else if ((  board[3] ==1) && (  board[4] ==1)  && (  board[5] ==1)){
					return 10;
		}
		else if ((  board[3] ==2) && (  board[4] ==2)  && (  board[5] ==2)){
					return -10;
				}

		else if ((  board[6] ==1) && (  board[7] ==1) && (  board[8] ==1)){
					return 10;
		}
		else if ((  board[6] ==2) && (  board[7] ==2) && (  board[8] ==2)){
					return -10;
				}
		else if ((  board[0] ==1) && (  board[3] ==1) && (  board[6] ==1)){

					return 10;
		}
		else if ((  board[0] ==2) && (  board[3] ==2) && (  board[6] ==2)){
					return -10;

				}
		else if ((  board[1] ==1) && (  board[4] ==1) && (  board[7] ==1)){

					return 10;
		}
		else if ((  board[1] ==2) && (  board[4] ==2) && (  board[7] ==2)){
					return -10;
				}

		else if ((  board[2] ==1) && (  board[5] ==1) && (  board[8] ==1)){

					return 10;
		}
		else if ((  board[2] ==2) && (  board[5] ==2) && (  board[8] ==2)){
					return -10;

				}
		else if ((  board[2] ==1) && (  board[4] ==1) && (  board[6] ==1)){

					return 10;
		}
		else if ((  board[2] ==2) && (  board[4] ==2) && (  board[6] ==2)){
				return -10;
				}

		else if ((  board[0] ==1) && (  board[4] ==1) && (  board[8] ==1)){
					return 10;
		}
		else if ((  board[0] ==2) && (  board[4] ==2) && (  board[8] ==2)){
					return -10;
				}
		else{
			return 0;
		}
		}





