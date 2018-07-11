/*
 * Gameboard.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Gameboard.h"
#include <string>
#include <iostream>
Gameboard::Gameboard() {

}
Gameboard::Gameboard(int size, int numberOfPlayers) { // @suppress("Member declaration not found")
	this->size=size;
	grid = new Square[size*size];
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			grid[row*size+col] = Square();
		}
	}
	buildWalls();
}
void Gameboard::buildWalls(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(row == 0 || row == size-1 || col == 0 || col == size-1){
				grid[row*size+col].putWall();
			}
		}
	}
}
void Gameboard::printDebug(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(	grid[row*size+col].isPlayer()){
				std::cout << std::to_string(grid[row*size+col].getPlayer()->playerNumber());
			}else if(grid[row*size+col].isBomb()){
				std::cout << "B";
			}else if(grid[row*size+col].isWall()){
				std::cout << "*";
			}else{
				std::cout << "_";
			}
		}
		std::cout << std::endl;
	}
}
int Gameboard::updateGameboard(){
	AreBombExploding();
	getPlayersMove();

	printDebug(); // DEBUG
	return isThereAWinner();
}
int Gameboard::isThereAWinner(){
	return 0; // TODO
}
void Gameboard::getPlayersMove(){
	Player* player;
	int move;
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(grid[row*size+col].isPlayer() == 1){
				player = grid[row*size+col].getPlayer();
				move = askPlayerMove(player->playerNumber());
				if(move != 0){
					if(isActionValid(row*size+col, move, player)){
						std::cout << "action is valid" << std::endl; // DEBUG
						ActionPlayer(row*size+col, move, player);
					}else{
						std::cout << "action is not valid" << std::endl; // DEBUG
					}
				}
			}
		}
	}
}
int Gameboard::askPlayerMove(int player){
	// TODO ask for player move
	srand (time(NULL));
	int move = (rand() % 6) - 1;
	std::cout << "player " + std::to_string(player) + " move is " + std::to_string(move) << std::endl;
	return move;
}
// -1:bomb 0:nothing 1:up 2:down 3:<- 4:->
bool Gameboard::isActionValid(int position, int move, Player* player){
	if(move == -1){ // bomb
		if(player->canPutBomb() && !grid[position].isBomb()){
			return 1;
		}
	}else {
		return !isDestinationOccupied(position, move);
	}
	return -1;
}
void Gameboard::ActionPlayer(int position, int move, Player* player){
	if(move == -1){
		grid[position].putBomb();
	}else{
		grid[position].emptyPlayer();
		std::cout << "putting player " + std::to_string(player->playerNumber()) + " in position " + std::to_string(position/size) +":" + std::to_string(position%size) << std::endl; // DEBUG
		grid[getDestination(position, move)].putPlayer(player);
	}

}
void Gameboard::AreBombExploding(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(grid[row*size+col].isBomb()){
				if(grid[row*size+col].bombUpdate()){
					grid[row*size+col].emptyBomb();
					explosion(row*size+col);
				}
			}
		}
	}
}
void Gameboard::explosion(int position){
	// TODO
}
bool Gameboard::isDestinationOccupied(int position,int move){
	int destination = getDestination(position, move);
	if(destination == -1){
		return -1;
	}
	return grid[destination].isOccupied();
}
bool Gameboard::isOccupied(int position){
	return grid[position].isOccupied();
}
int Gameboard::getDestination(int position,int move){
	if(move == 1){
		if(position/size == 0){
			return -1;
		}
		return position-size;
	}
	if(move == 2){
		if(position/size == size){
			return -1;
		}
		return position+size;
	}
	if(move == 3){
		if(position%size == 0){
			return -1;
		}
		return position-1;
	}
	if(move == 4){
		if(position%size == size){
			return -1;
		}
		return position+1;
	}
	return -1;
}
bool Gameboard::isBombDestinationEmpty(int position){
	return 0;
}
bool Gameboard::canPlayerPutBomb(int playerNb){
	return 0;
}
void Gameboard::putBomb(int row,int col, int move){

}
void Gameboard::putPlayer(int position, Player* player){
	grid[position].putPlayer(player);
}
