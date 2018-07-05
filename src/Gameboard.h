/*
 * Gameboard.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include "Square.h"

class Gameboard {
public:
	Gameboard();
	Gameboard(int size, int numberOfPlayers);
	void updateGameboard();


private:
	Square* grid;
};

#endif /* GAMEBOARD_H_ */
