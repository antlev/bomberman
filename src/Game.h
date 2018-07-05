/*
 * Game.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef GAME_H_
#define GAME_H_
#include "Gameboard.h"
#include "Turn.h"

struct Game {
public:
	Game(std::string confFile);
	void start();
	int isFinished();
	void nextTurn();
	void showResults();

private:
	int nbTurn;
	int nbPlayer;
	int nbBombMax;
	int bombDuration;
	int bombRange;
	short wallPlacement;
	int winner;
	std::string confFile;
	Turn turn;
	Gameboard gameboard;
};

#endif /* GAME_H_ */
