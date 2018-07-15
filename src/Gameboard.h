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
#include <string>

class Gameboard {
public:
	Gameboard(int size, int numberOfPlayers);
	void buildWalls();
	int updateGameboard();
	bool isBombDestinationEmpty(int position);
	bool canPlayerPutBomb(int playerNb);
	void putBomb(int row,int col, int move);
	void putPlayer(int position, Player* player);
	bool isOccupied(int position);
	void printDebug();
	void setPlayerMove(int playerNb, int move);

	int getDestination(int position,int move); // should be private

private:
	Square* grid;
	int size;
	int nbPlayer;
	int nbPlayersAlive;
	int* playersAlive;
	int* playersPlayed;
	Player** players;

	void ActionPlayer(int position, int move, Player* player);
	void AreBombExploding();
	bool isActionValid(int position, int move, Player* player);
	void movePlayer(int move, Player* player);
	bool isDestinationOccupied(int position, int move);
	int isThereAWinner();
	void explosion(int position);
	int* playersInRange(int position,int nbPlayer);
	void newTurn();
};

#endif /* GAMEBOARD_H_ */
