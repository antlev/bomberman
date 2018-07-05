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
	grid = new Square[size*size];
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			grid[row*size+col] = Square();
		}
	}
}
void Gameboard::updateGameboard(){

}

