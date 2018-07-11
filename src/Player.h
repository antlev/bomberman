/*
 * Player.h
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
	Player(int number);
	int playerNumber();
	bool canPutBomb();

private:
	int number;
	int numberBomb;
};

#endif /* PLAYER_H_ */
