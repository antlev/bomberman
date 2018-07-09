/*
 * Square.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef SQUARE_H_
#define SQUARE_H_

class Square {
public:
	Square();
	virtual ~Square();
	int getSquare();
	bool isEmpty();
	bool isBomb();
	bool bombUpdate();
	int isPlayer();
	bool isWall();
	void updatePlayer();
	int getMove(int playerNb);
	void placeWall();
	void placePlayer(int playerNb);

private:
	int status;
	Bomb* bombPt;
	Player* playerPt;
};

#endif /* SQUARE_H_ */
