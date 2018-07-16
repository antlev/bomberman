/*
 * Game.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef GAME_H_
#define GAME_H_
#include "Gameboard.h"

struct Game {
public:
	Game(std::string confFile);
	void start();
	int isFinished();
	void nextTurn();
	void showResults();
	void readAndSetConf(std::string confFile);

private:
	int nbTurn;
	int nbPlayer;
	int nbBombMax; //alex
	int bombDuration; //alex
	int bombRange; //alex
	short wallPlacement;
	int winner;
	std::string confFile;
	Gameboard* gameboard;
	void setDefault();
	void setDefaultbombRange();
	void setDefaultbombDuration();
	void setDefaultnbBombMax();
};

#endif /* GAME_H_ */
