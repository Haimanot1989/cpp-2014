#include <iostream>
#include "class_action.h"
#include <string>

using namespace std;
using namespace casino;

void action::print(){
	string gameType = "";
	if(t == 0)
		gameType = "Blackjack";
	else if(t == 1)
		gameType = "Poker";
	else if(t == 2)
		gameType = "Chess";
	else if(t == 3)
		gameType = "Roulette";
	else
		gameType = "Tic Tac Toe";
	cout << "You are playing: " << gameType << endl;
}