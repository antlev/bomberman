/*
 * Gameboard.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include "Bomb.h"
#include "Player.h"
#include "Square.h"

class Gameboard {
public:
	Gameboard();
	Gameboard(int size, int numberOfPlayers);
	void updateGameboard();
	bool isBombDestinationEmpty(int row, int col);
	bool isDestinationEmpty(int row,int col,int move);
	bool canPlayerPutBomb(int playerNb);
	void movePlayer(int row,int col, int move);
	void putBomb(int row,int col, int move);

private:
	Square* grid;
	int size;

	void AreBombExploding();
	void getPlayersMove();
};

#endif /* GAMEBOARD_H_ */
