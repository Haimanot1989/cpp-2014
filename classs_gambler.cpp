#include <iostream>
#include "class_gambler.h"
#include <string>

using namespace std;
using namespace casino;

int gambler::gamblerNr = 1;
gambler::gambler(string newFirstName, string newLastName){
	gamblerId = gamblerNr++;
	firstName = newFirstName;
	lastName = newLastName;
}

/*gambler::gambler()//controlType=TERMINAL){
	
}*/

void gambler::giveMoney(cash newGivenAmount){
	if(wallet >= newGivenAmount)
		wallet += newGivenAmount; //reduse wallet 
	else
		cout << "You don't have enogh money in your wallet" << endl;
}

cash gambler::placeBet(){
	return wallet;
}
string gambler::name(){
	return lastName + ", " + firstName;
}

bool gambler::ready(){
	return readyToPlay;
}

/*action* gambler::takeAction(gameState* newG){
	return newG;
}*/

void gambler::joinGame(game& g){
	//g.gamblers.push_back(gambler(firstName, lastName));
	readyToPlay = false; //gambler has joined a game
}