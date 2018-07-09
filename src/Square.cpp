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
	// TODO Auto-generated constructor stub

}

Square::~Square() {
	// TODO Auto-generated destructor stub
}
bool Square::isEmpty(){
	if(bombPt){
		return 0;
	}
	if(playerPt){
		return 0;
	}
	return 1;
}
bool Square::isBomb(){
	if(bombPt){
		return 1;
	}
	return 0;
}
bool Square::bombUpdate(){
	return bombPt->updateState();
}
bool Square::isPlayer(){
	if(playerPt){
		return playerPt->playerNumber();
	}
	return 0;
}
void Square::updatePlayer(){

}
int Square::getMove(int playerNb){
	return playerPt->getMove();
}
