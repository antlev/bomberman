/*
 * Game.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include <iostream>
#include <string>
#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

Game::Game(std::string confFile){
	if(confFile != ""){
		this->confFile = confFile;
		// TODO read confFile
		nbPlayer = 4;
		int nbBombMax = 3;
		int bombDuration = 10;
		int bombRange = 5;
		settings = new Settings(nbPlayer, nbBombMax, bombDuration, bombRange);
	}else{
		nbPlayer = 4;
		int nbBombMax = 3;
		int bombDuration = 10;
		int bombRange = 5;
		settings = new Settings(nbPlayer, nbBombMax, bombDuration, bombRange);

		wallPlacement = 0;
	}
	playerMoves = new int[nbPlayer];
	com = new Communication();
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
		  gameboard->putPlayer(row*size+col, player);
	}
//	gameboard->printDebug(); // DEBUG
}
int Game::isFinished(){
	if(winner == 0){
		return 0;
	}
	if(winner == -1){
		std::cout << "Game is finished ! It's a draw !" << std::endl;
		return 1;
	}
	std::cout << "Game is finished ! winner is player " << std::to_string(winner) << std::endl;
	return 1;
}
void Game::start(){
	nbPlayer = com->start();
	com->sendSetting(settings);
	nbTurn = 1;
}
void Game::nextTurn(){
	getPlayersMove();
	winner = gameboard->updateGameboard();
	nbTurn++;
	std::this_thread::sleep_for(std::chrono::seconds(1));

}
void Game::getPlayersMove(){
	for(int i=0;i<nbPlayer;i++){
		std::string move = com->askMove(nbTurn, i);
		setPlayersMove(i, sanitiseMove(move));
	}
}
int Game::sanitiseMove(std::string move){
	if(move == "NOACTION"){
		return 0;
	}
	if(move == "U"){
		return 1;
	}
	if(move == "D"){
		return 2;
	}
	if(move == "L"){
		return 3;
	}
	if(move == "R"){
		return 4;
	}
	if(move == "B"){
		return -1;
	}
	return 0;
}
void Game::setPlayersMove(int player, int move){
	playerMoves[player] = move;
}

