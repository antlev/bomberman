/*
 * Bomb.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Bomb.h"

Bomb::Bomb() {
	counter=3; // TODO
}
Bomb::~Bomb(){

}
bool Bomb::updateState(){
	counter--;
	if(counter == 0){
		return 1;
	}else{
		return 0;
	}
}
void Bomb::explosion(){
	// TODO
}
