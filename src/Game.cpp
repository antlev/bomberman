/*
 * Game.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include <iostream>
#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

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
	int size = 10;
	gameboard = new Gameboard(size, nbPlayer);

	srand (time(NULL));
	int playerNb;

	for(playerNb=0;playerNb<nbPlayer;playerNb++){
		  int col,row;
		  col = rand() % size;
		  row = rand() % size;
		  gameboard->putPlayer(row, col, playerNb);
	}
}
int Game::isFinished(){
	if(nbTurn < 10){
		return 0;
	}
	std::cout << "Game is finished" << std::endl;
	return 1;
}
void Game::start(){
	std::cout << "Game is starting" << std::endl;
	nbTurn = 1;
}
void Game::nextTurn(){
	std::cout << "Turn number " << std::to_string(nbTurn) << std::endl;
	gameboard->updateGameboard();
	nbTurn++;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
void Game::showResults(){

}
