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
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

Game::Game(std::string confFile){
	if(confFile != ""){
		this->confFile = confFile;
		readAndSetConf(confFile);
		std::cout << "bombrange = " << bombRange << std::endl;
		std::cout << "bombDuration = " << bombDuration << std::endl;
		std::cout << "nbBombMax =" << nbBombMax << std::endl;
	}else{
		std::cout << "Setting default values" << std::endl;
		nbPlayer = 4;
		wallPlacement = 0;
		setDefault();
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
	if(winner == -1){
		std::cout << "Game is finished ! It's a draw !" << std::endl;
		return 1;
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

void Game::setDefault(){
	nbBombMax = 3;
	bombDuration = 10;
	bombRange = 5;
}

void Game::setDefaultnbBombMax() {
	nbBombMax = 3;
}

void Game::setDefaultbombDuration() {
	bombDuration = 10;
}

void Game::setDefaultbombRange(){
	bombRange = 5;
}

void Game::readAndSetConf(std::string confFile){

	std::ifstream fichier(confFile, std::ios::in);  // on ouvre le fichier en lecture
	if(fichier)  // si l'ouverture a réussi

	{
		std::string contenu;
		std::vector<std::string>  words;
		bool nbBombMaxParam = 0, bombDurationParam = 0, bombRangeParam = 0;
		while(std::getline(fichier, contenu)) {

			words = split(contenu, ' ');

			if (words[0] == "nbBombMax"){
				if (words.size() == 2){
					nbBombMaxParam = 1;
					nbBombMax = stoi(words[1]);
				}else{
					std::cout << "Probleme configuration Nb BombMax" << std::endl;
					exit(-1);
				}
			}

			if (words[0] == "bombDuration"){
				if (words.size() == 2){
					bombDurationParam = 1;
					bombDuration = stoi(words[1]);
			} else{
					std::cout << "Probleme configuration bombDuration" << std::endl;
					exit(-1);
				}
			}

			if (words[0] == "bombRange"){
				if (words.size() == 2) {
					bombRangeParam = 1;
					bombRange = stoi(words[1]);
				}else{
					std::cout << "Probleme configuration bombRange" << std::endl;
					exit(-1);
				}

			}
		}

		fichier.close();  // on ferme le fichier

		if (!nbBombMaxParam){
			setDefaultnbBombMax();
		}
		if (!bombDurationParam){
			setDefaultbombDuration();
		}
		if (!bombRangeParam){
			setDefaultbombRange();
		}
	}
	else

		std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

}