/*
 * Bomb.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef BOMB_H_
#define BOMB_H_

class Bomb {
public:
	Bomb();
	virtual ~Bomb();
	bool updateState();

private:
	int counter;
};

#endif /* BOMB_H_ */
