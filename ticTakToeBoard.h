#ifndef CLASS_TICTAKTOEBOARD_H
#define CLASS_TICTAKTOEBOARD_H

namespace casino{
	class board{
		unsigned int row; 
		unsigned int boardArea;
	public:
		std::vector<char> boardChar;
		board(unsigned int initialrow);
		~board();
		unsigned int getBoardArea();
		void setBoardArea(unsigned int row);
		void printThreeSquare();
		void printFourSquare();
		void print();
	};
}
#endif