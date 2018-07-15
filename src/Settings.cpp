/*
 * Settings.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: antoine
 */

#include "Settings.h"

Settings::Settings(int nbPlayer, int nbBombMax, int bombDuration, int bombRange) : 	nbPlayer(nbPlayer), nbBombMax(nbBombMax), bombDuration(bombDuration), bombRange(bombRange), wallPlacement(wallPlacement){
}

int Settings::getNbBombMax(){
	return nbBombMax;
}
int Settings::getBombDuration(){
	return bombDuration;
}
int Settings::getBombRange(){
	return bombRange;
}
