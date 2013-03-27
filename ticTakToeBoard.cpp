#include <iostream>
#include <vector>
#include "ticTakToeBoard.h"

using namespace std;
using namespace casino;

const unsigned short int THREESQUARE = 9, FOURSQUARE = 16;
board::board(unsigned int initialRow){
	row = initialRow;
	setBoardArea(initialRow);
	for(int i = 0; i < boardArea; i++){
		boardChar.push_back(i);
	}
}

board::~board(){
}

void board::setBoardArea(unsigned int newRow){
	boardArea = newRow * newRow;
}

unsigned int board::getBoardArea(){
	return boardArea;
}

void board::printThreeSquare(){

	cout << " ----------------"<<endl;

	for(int i = 0; i < boardArea; i++ ){
		int positionForPrint = int(boardChar[i]) + 1;
		cout << " |  " << positionForPrint;
		
		if(positionForPrint % row == 0){
			cout  << " | "<< endl;
			cout << " ----------------"<<endl;	 
			}
		}
}

void board::printFourSquare(){
	cout << " ---------------------"<<endl;
	for(int i = 0; i < boardArea; i++ ){
		int positionForPrint = int(boardChar[i]) + 1;
		cout << " | " << positionForPrint;

		if(positionForPrint <= THREESQUARE)
			cout << " ";

		if(positionForPrint % row == 0){
				cout  << " | "<< endl;
			cout << " ---------------------"<<endl;	 
		}
	}

}

void board::print(){
	int boardArea = getBoardArea();
	if(boardArea == THREESQUARE){
		printThreeSquare();
	}//end of if
	else if(boardArea == FOURSQUARE){
		printFourSquare();
	}//end of if
}

/*int main(){
	board b3(3);
	b3.print();

	board b(4);
	b.print();
	system("pause");
	return 0;
}*/