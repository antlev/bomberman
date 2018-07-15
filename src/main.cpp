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
//	if(argc > 1){
//		std::cout << argv[1] << std::endl;
//		conf = argv[1];
//	}
	Game game(conf);
	srand (time(NULL));

	game.Game::start();

	while(game.Game::isFinished() != 1){
		game.Game::nextTurn();
	}


	while(1);

	return 0;
}
