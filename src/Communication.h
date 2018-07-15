/*
 * Sender.h
 *
 *  Created on: Jul 15, 2018
 *      Author: antoine
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
#include "Settings.h"

class Communication {
public:
	Communication();
	int start();
	void sendSetting(Settings* settings);
	std::string waitForMessage(std::string key);
	std::string askMove(int playerNb, int turn);

private:
};

#endif /* COMMUNICATION_H_ */
