//#ifndef TICTAKTOESTATE.H
//#define TICTAKTOESTATE.H
#include "class_gameState.h"

namespace casino{
	class ticTakToeState : public gameState{
		//one vector of position for each player
		std::vector< std::vector<unsigned int> > positionChose;

		//Location of "my positions" in positionChose
		int ourHero;

		//Location of machine's positions in positionChose
		int machine;

	public:
		ticTakToeState(std::vector< std::vector<unsigned int> > positionv, int iHero, int iMachine);
		void print();

		//special position getters
		std::vector<unsigned int> machinePositions();
		std::vector<unsigned int> myPositions();

		//General position getter
		std::vector<unsigned int> positionsI(int i);


		//Special indexes for general position getter
		int getOurHero();
		int getMachine();

		ticTakToeState& operator= (const ticTakToeState& Copy){
			if(&Copy == this){
				return *this;
			}

			positionChose = Copy.positionChose; // copied positionChose
			return *this;
		}

		//friend ticTakToeState operator=(const ticTakToeState& Copy);

	};
}
//#endif