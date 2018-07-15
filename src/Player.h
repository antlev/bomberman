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
	Player(int number, int position);
	int playerNumber();
	bool canPutBomb();
	int getPosition();
	void setPosition(int position);

private:
	int number;
	int numberBomb;
	int position;
;
};

#endif /* PLAYER_H_ */
