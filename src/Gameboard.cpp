/*
 * Gameboard.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Gameboard.h"
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
}
void Gameboard::updateGameboard(){

	AreBombExploding();

	getPlayersMove();

}
void Gameboard::getPlayersMove(){
	int playerNb;
	int move;
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(playerNb = (grid[row*size+col].isPlayer())){
				move = grid[row*size+col].getMove(playerNb);
				if(move == 1){ //put bomb
					if(isBombDestinationEmpty(row, col) && canPlayerPutBomb(playerNb)){
						putBomb(row,col, playerNb);
					}
				} else if(isDestinationEmpty(row,col, move)){
					movePlayer(row,col, move);
				}
			}
		}
	}
}
void Gameboard::AreBombExploding(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(grid[row*size+col].isBomb()){
				grid[row*size+col].bombUpdate();
			}
		}
	}
}
bool Gameboard::isDestinationEmpty(int row,int col,int move){
	return 0;
}
bool Gameboard::isBombDestinationEmpty(int row,int col){
	return 0;
}
bool Gameboard::canPlayerPutBomb(int playerNb){
	return 0;
}
void Gameboard::putBomb(int row,int col, int move){

}
void Gameboard::movePlayer(int row,int col, int move){

}
