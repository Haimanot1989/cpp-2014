//#ifndef TICTAKTOEGAME.H
//#define TICTAKTOEGAME.H

#include "class_game.h"

namespace casino{
	class tikTakToeGame : public game{
		virtual void playRound();
	public:
		tikTakToeGame(int player=1);
		virtual void start();
	};
}
//#endif