/*
 * Settings.h
 *
 *  Created on: Jul 15, 2018
 *      Author: antoine
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

class Settings {
public:
	Settings(int nbPlayer, int nbBombMax, int bombDuration, int bombRange);
	int getNbBombMax();
	int getBombDuration();
	int getBombRange();
private:
	int nbPlayer;
	int nbBombMax;
	int bombDuration;
	int bombRange;
	int wallPlacement;
};

#endif /* SETTINGS_H_ */
