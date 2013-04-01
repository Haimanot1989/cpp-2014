#include <iostream>
#include <string>
#include "class_game.h"
#include "ticTakToeGame.h"


using namespace std;
using namespace casino;

tikTakToeGame::tikTakToeGame(int newPlayer): game(ticTakToe){

}

void tikTakToeGame::start(){
	string firstName, lastName;

	cout << "Your first name: ";
	cin >> firstName;

	cout << "Your last name: ";
	cin >> lastName;
	gambler house = gambler("House", "House");
	gambler player = gambler(firstName, lastName);
}//end of start

void tikTakToeGame::playRound(){

}
int main(){
	tikTakToeGame game1 = tikTakToeGame();
	game1.start();
	system("pause");
	return 0;
}
