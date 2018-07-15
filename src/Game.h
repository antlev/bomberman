/*
 * Game.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef GAME_H_
#define GAME_H_
#include <string>
#include "Communication.h"
#include "Gameboard.h"
#include "Settings.h"

struct Game {
public:
	Game(std::string confFile);
	void start();
	int isFinished();
	void nextTurn();
	void showResults();
	void getPlayersMove();
	void setPlayersMove(int player, int move);
	int sanitiseMove(std::string move);

private:
	int nbTurn;
	int nbPlayer;
	int* playerMoves;
	Settings* settings;
	short wallPlacement;
	int winner;
	std::string confFile;
	Gameboard* gameboard;
	Communication* com;

};

#endif /* GAME_H_ */
