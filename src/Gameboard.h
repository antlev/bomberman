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
#include "Wall.h"
#include "Square.h"

class Gameboard {
public:
	Gameboard();
	Gameboard(int size, int numberOfPlayers);
	void buildWalls();
	void updateGameboard();
	bool isBombDestinationEmpty(int position);
	bool canPlayerPutBomb(int playerNb);
	void ActionPlayer(int position, int move, Player* player);
	void putBomb(int row,int col, int move);
	void putPlayer(int position, Player* player);
	bool isOccupied(int position);
	void printDebug();

	int getDestination(int position,int move); // should be private

private:
	Square* grid;
	int size;

	void AreBombExploding();
	void getPlayersMove();
	int askPlayerMove(int player);
	bool isActionValid(int position, int move, Player* player);
	void movePlayer(int move, Player* player);
	bool isDestinationOccupied(int position, int move);

};

#endif /* GAMEBOARD_H_ */
