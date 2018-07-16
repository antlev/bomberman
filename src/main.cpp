//============================================================================
// Name        : main.cpp
// Author      : antoine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[]) {
	string confPath = "";
	if(argc > 1){
		confPath = argv[1];
	}
	Game game(confPath);
	srand (time(NULL));

	game.Game::start();

	while(game.Game::isFinished() != 1){
		game.Game::nextTurn();
	}

	game.showResults();
	return 0;
}
