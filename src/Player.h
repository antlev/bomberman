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
	Player();
	int playerNumber();
	int getMove();

private:
	int number;
};

#endif /* PLAYER_H_ */
