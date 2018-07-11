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
		  Player* player = new Player(playerNb);
		  do{
			  col = (rand() % (size-2))+1;
			  row = (rand() % (size-2))+1;
		  } while(gameboard->isOccupied(row*size+col));
		  std::cout << "putting player " + std::to_string(playerNb) + " in position " + std::to_string(row) +":" + std::to_string(col) << std::endl; // DEBUG
		  gameboard->putPlayer(row*size+col, player);
	}
	gameboard->printDebug(); // DEBUG
}
int Game::isFinished(){
	if(winner == 0){
		return 0;
	}
	std::cout << "Game is finished ! winner is player " << std::to_string(winner) << std::endl;
	return 1;
}
void Game::start(){
	std::cout << "Game is starting" << std::endl;
	nbTurn = 1;
}
void Game::nextTurn(){
	std::cout << "Turn number " << std::to_string(nbTurn) << std::endl;
	winner = gameboard->updateGameboard();
	nbTurn++;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
void Game::showResults(){

}
