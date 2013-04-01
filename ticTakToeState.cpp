#include <iostream>
#include "class_gameState.h"
#include "ticTakToeState.h"
#include <vector>


using namespace std;
using namespace casino;

ticTakToeState::ticTakToeState(vector<vector<unsigned int> > newPositionv, int newHero, int newMachine){

	positionChose = newPositionv;
	ourHero = newHero;
	machine = newMachine;
}

void ticTakToeState::print(){

}