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
	string conf = "";
	if(argc > 1){
		std::cout << argv[1] << std::endl;
		conf = argv[1];
	}
	Game game(conf);

	game.Game::start();

	while(game.Game::isFinished() != 0){
		game.Game::nextTurn();
	}

	game.showResults();
	return 0;
}
