/*
 * Square.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */
#include "Player.h"
#include "Bomb.h"
#include "Wall.h"
#include "Square.h"
#include <iostream>
#define SAFE_DELETE(a) if( (a) != NULL ) delete (a); (a) = NULL;

Square::Square() {
	playerPt = 0;
	bombPt = 0;
	wallPt = 0;
}

Square::~Square() {
	// TODO Auto-generated destructor stub
}
bool Square::isEmpty(){
	if(playerPt == 0 && bombPt == 0 && wallPt == 0){
		return 1;
	}
	return 0;
}
bool Square::isOccupied(){
	if(playerPt == 0 && wallPt == 0){
		return 0;
	}
	return 1;
}
void Square::putPlayer(Player* player){
	if(wallPt != 0){
		std::cout << "trying to put player in wall"; // DEBUG
		exit(0);
	}
	playerPt = player;
}
void Square::emptyPlayer(){
	playerPt = 0;
}
int Square::killPlayer(){
	int playerNb = playerPt->playerNumber();
	if(playerPt){
		SAFE_DELETE(playerPt);
	}
	return playerNb;
}
void Square::putBomb(){
	bombPt = new Bomb();
}
void Square::emptyBomb(){
	bombPt = 0;
}
void Square::putWall(){
	wallPt = new Wall();
}

bool Square::isBomb(){
	if(bombPt != 0){
		return 1;
	}
	return 0;
}
bool Square::isWall(){
	if(wallPt != 0){
		return 1;
	}
	return 0;
}
int Square::isPlayer(){
	if(playerPt != 0){
		return 1;
	}
	return 0;
}
Player* Square::getPlayer(){
	return playerPt;
}
void Square::updatePlayer(){

}
bool Square::bombUpdate(){
	return bombPt->updateState();
}

