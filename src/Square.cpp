/*
 * Square.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */
#include "Player.h"
#include "Bomb.h"
#include "Square.h"

Square::Square() {
	this->status=0;
}

Square::~Square() {
	// TODO Auto-generated destructor stub
}
bool Square::isEmpty(){
	if(status == 0){
		return 1;
	}
	return 0;
}
bool Square::isBomb(){
	if(status == -2){
		return 1;
	}
	return 0;
}
bool Square::isWall(){
	if(status == -1){
		return 1;
	}
	return 0;
}
bool Square::bombUpdate(){
	return bombPt->updateState();
}
int Square::isPlayer(){
	if(status > 0){
		return status;;
	}
	return 0;
}
void Square::updatePlayer(){

}
int Square::getMove(int playerNb){
	return playerPt->getMove();
}
void Square::placeWall(){
	status=-1;
}
void Square::placePlayer(int playerNb){
	status=playerNb;
}
