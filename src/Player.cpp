/*
 * Player.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Player.h"
#include <iostream>

Player::Player(int number, int position) : number(number), position(position){
	numberBomb=0;
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
int Player::getPosition(){
	return position;
}
void Player::setPosition(int position){
	this->position = position;
}

