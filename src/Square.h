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
	bool isOccupied();
	bool isBomb();
	bool bombUpdate();
	int isPlayer();
	Player* getPlayer();
	bool isWall();
	void updatePlayer();
	void emptyPlayer();
	void putPlayer(Player* player);
	void putBomb();
	void putWall();

private:
	Bomb* bombPt;
	Player* playerPt;
	Wall* wallPt;
};

#endif /* SQUARE_H_ */
