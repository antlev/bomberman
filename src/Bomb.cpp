/*
 * Bomb.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: antoine
 */

#include "Bomb.h"

Bomb::Bomb() {
	counter=100;
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

