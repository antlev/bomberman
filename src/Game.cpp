/*
 * Game.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include <iostream>
#include "Game.h"

Game::Game(std::string confFile){
	if(confFile != ""){
		this->confFile = confFile;
		// TODO read confFile
	}else{
		std::cout << "Setting default values" << std::endl;
		nbPlayer = 4;
		nbBombMax = 3;
		bombDuration = 10;
		bombRange = 5;
		wallPlacement = 0;
	}
	winner = 0;
	nbTurn = 0;
	int size = 50;
	gameboard = Gameboard(size, nbPlayer);
}
int Game::isFinished(){
	std::cout << "Game is finished" << std::endl;
	return 0;
}
void Game::start(){
	std::cout << "Game is staring" << std::endl;
	nbTurn = 1;
	turn = Turn();
}
void Game::nextTurn(){
	winner = turn.nextTurn();
}
void Game::showResults(){

}
