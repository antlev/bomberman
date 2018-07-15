/*
 * Sender.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: antoine
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Communication.h"



Communication::Communication() {

}
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int Communication::start(){
	vector<string>  words;
	string line;
    getline(cin, line);
	words = split(line,' ');
	if(words[0] != "START"){
		cout << "WAS EXPECTING START" <<  endl;
		exit(-1);
	}
	if(words[1] != "players"){
		cout << "WAS EXPECTING players" <<  endl;
		exit(-1);
	}
    getline(cin, line);
	words = split(line,' ');
    getline(cin, line); //STOP
    return stoi(words[0]);
}


string Communication::waitForMessage(string key){
	vector<string>  words;
	string line;
    getline(cin, line);
	words = split(line,' ');
	if(words[0] != key){
		cout << "WAS EXPECTING " << key <<  endl;
		exit(-1);
	}
	return words[1];
}

void Communication::sendSetting(Settings* settings){
	cout << "START settings" << endl;
	cout << "NB_BOMBS " << to_string(settings->getNbBombMax()) << endl;
	cout << "BOMB_DURATION " << to_string(settings->getBombDuration())  << endl;
	cout << "BOMB_RADIUS " << to_string(settings->getBombRange())  << endl;
	cout << "STOP settings" << endl;
}
string Communication::askMove(int turn, int playerNb){
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "START turn " << to_string(turn) << " " <<  to_string(playerNb+1) << endl;
	cout << "turn " << to_string(turn) << " " <<  to_string(playerNb+1) << endl;
	cout << "STOP turn " << to_string(turn) << " " <<  to_string(playerNb+1) << endl;
	vector<string>  words;
	string line;
    getline(cin, line);
	words = split(line,' ');
	if(words[0] != "START"){
		cout << "WAS EXPECTING START - Found " << line <<  endl;
		exit(-1);
	}
	if(words[1] != "actions"){
		cout << "WAS EXPECTING actions - Found " << line <<  endl;
		exit(-1);
	}
	if(stoi(words[2]) != turn){
		cout << "WAS EXPECTING turn " << to_string(turn) << " - Found " << line <<  endl;
		exit(-1);
	}
	if(stoi(words[3]) != playerNb+1){
		cout << "WAS EXPECTING player " << to_string(playerNb+1) << " - Found " << line <<  endl;
		exit(-1);
	}
    getline(cin, line);
	words = split(line,' ');
    getline(cin, line); // STOP

	return words[0];

}

