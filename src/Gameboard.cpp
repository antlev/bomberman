/*
 * Gameboard.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Game.h"
#include <string>
#include <iostream>
#include <list>
Gameboard::Gameboard(int size, int nbPlayer) : size(size), nbPlayer(nbPlayer), nbPlayersAlive(nbPlayer) { // @suppress("Member declaration not found")
	grid = new Square[size*size];
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			grid[row*size+col] = Square();
		}
	}
	playersAlive = new int[nbPlayer];
	playersPlayed = new int[nbPlayer];
	for(int i=0;i<nbPlayer;i++){
		playersAlive[i] = 1;
	}
	for(int playerNb=0;playerNb<nbPlayer;playerNb++){
		  int col,row;
		  do{
			  col = (rand() % (size-2))+1;
			  row = (rand() % (size-2))+1;
		  } while(isOccupied(row*size+col));
		  players = new Player*[nbPlayer];
		  players[playerNb] = new Player(playerNb, row*size+col);
		  putPlayer(row*size+col, players[playerNb]);
	}
	buildWalls();
}
void Gameboard::buildWalls(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(row == 0 || row == size-1 || col == 0 || col == size-1){
				grid[row*size+col].putWall();
			}
		}
	}
}
void Gameboard::printDebug(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(	grid[row*size+col].isPlayer()){
				std::cout << std::to_string(grid[row*size+col].getPlayer()->playerNumber()+1);
			}else if(grid[row*size+col].isBomb()){
				std::cout << "B";
			}else if(grid[row*size+col].isWall()){
				std::cout << "#";
			}else{
				std::cout << "_";
			}
		}
		std::cout << std::endl;
	}
}
int Gameboard::updateGameboard(){
	AreBombExploding();
	newTurn();
//	printDebug(); // DEBUG
	return isThereAWinner();
}
void Gameboard::setPlayerMove(int playerNb, int move){
	ActionPlayer(players[playerNb]->getPosition(), move, players[playerNb]);
}

int Gameboard::isThereAWinner(){
	if(nbPlayersAlive <= 0){
		return -1;
	}
	if(nbPlayersAlive == 1){
		for(int i=0; i<nbPlayer;i++){
			if(playersAlive[i] == 1){
				return i+1;
			}
		}
	}
	return 0;
}
void Gameboard::newTurn(){
	for(int i=0;i<nbPlayer;i++){
		playersPlayed[i] = 0;
	}
}
// -1:bomb 0:nothing 1:up 2:down 3:<- 4:->
bool Gameboard::isActionValid(int position, int move, Player* player){
	if(move == -1){ // bomb
		if(player->canPutBomb() && !grid[position].isBomb()){
			return 1;
		}
	}else {
		return !isDestinationOccupied(position, move);
	}
	return -1;
}
void Gameboard::ActionPlayer(int position, int move, Player* player){
	if(move != 0){
		if(move == -1){
			grid[position].putBomb();
		}else{
			grid[position].emptyPlayer();
			grid[getDestination(position, move)].putPlayer(player);
		}
	}
}
void Gameboard::AreBombExploding(){
	for(int row=0;row<size;row++){
		for(int col=0;col<size;col++){
			if(grid[row*size+col].isBomb()){
				if(grid[row*size+col].bombUpdate()){
					explosion(row*size+col);
				}
			}
		}
	}
}
void Gameboard::explosion(int position){
	grid[position].emptyBomb();
	std::list<int> playersKilled;
	int range = 3;
	int i=0;
	while((position%size)+i < size && i < range){
		if(grid[position+i].isOccupied()){
			if(grid[position+i].isPlayer()){
				playersAlive[grid[position+i].killPlayer()]=0;
				nbPlayersAlive--;
			}else{
				break;
			}
		}
		i++;
	}
	i=0;
	while((position%size)-i >= 0 && i < range){
		if(grid[position-i].isOccupied()){
			if(grid[position-i].isPlayer()){
				playersAlive[grid[position-i].killPlayer()]=0;
				nbPlayersAlive--;
			}else{
				break;
			}
		}
		i++;
	}
	i=0;
	while((position/size)+i < size && i < range){
		if(grid[position+i*size].isOccupied()){
			if(grid[position+i*size].isPlayer()){
				playersAlive[grid[position+i*size].killPlayer()]=0;
				nbPlayersAlive--;

			}else{
				break;
			}
		}
		i++;
	}
	i=0;
	while((position/size)-i >= 0 && i < range){
		if(grid[position-i*size].isOccupied()){
			if(grid[position-i*size].isPlayer()){
				playersAlive[grid[position-i*size].killPlayer()]=0;
			}else{
				break;
			}
		}
		i++;
	}
}
bool Gameboard::isDestinationOccupied(int position,int move){
	int destination = getDestination(position, move);
	if(destination == -1){
		return -1;
	}
	return grid[destination].isOccupied();
}
bool Gameboard::isOccupied(int position){
	return grid[position].isOccupied();
}
int Gameboard::getDestination(int position,int move){
	if(move == 1){
		if(position/size == 0){
			return -1;
		}
		return position-size;
	}
	if(move == 2){
		if(position/size == size){
			return -1;
		}
		return position+size;
	}
	if(move == 3){
		if(position%size == 0){
			return -1;
		}
		return position-1;
	}
	if(move == 4){
		if(position%size == size){
			return -1;
		}
		return position+1;
	}
	return -1;
}
bool Gameboard::isBombDestinationEmpty(int position){
	return 0;
}
bool Gameboard::canPlayerPutBomb(int playerNb){
	return 0;
}
void Gameboard::putBomb(int row,int col, int move){

}
void Gameboard::putPlayer(int position, Player* player){
	player->setPosition(position);
	grid[position].putPlayer(player);
}
