#include <iostream>
#include "class_game.h"

using namespace std;
using namespace casino;



game::game(gameType newGameType, int players){
	t = newGameType;
	gamblers.reserve(players);
}

gameType game::getType(){
	return t;
}

void game::playRound(){
}

void game::start(){
}