/*
 * Player.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Player.h"
#include <iostream>

Player::Player(int number) : number(number) {
//	std::cout << "Creating player nb" << number <<std::endl;
}
int Player::playerNumber(){
	return number;
}
bool Player::canPutBomb(){
	if(numberBomb < 3){
		return true;
	}
	return false;
}

