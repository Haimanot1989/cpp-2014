#include <iostream>
#include "class_card.h"
#include <string>
#include <sstream>
using namespace cards;
using namespace std;
card::card(t_suit new_suit, t_rank new_rank){
    suit = new_suit;
    rank = new_rank;
}

string card::name(){
//    string cardnavn = suit + rank;
	string suitChar = "H";
	string s = suit_name[suit];
	if(s == "SPADES")
		suitChar = 'S';
	else if(s == "HEARTS")
		suitChar = "H";
	else if(s == "CLUBS")
		suitChar = "C";
	else
		suitChar = "D";
	int rankInt = 1;
	if(rank <= 10)
		rankInt = rank;
	else
		rankInt = 10;
	std::stringstream sstm;
	sstm << rankInt << suitChar;
	return  sstm.str();

	/*char suitChar;
	string s = suit_name[suit];
	//"SPADES","HEARTS","CLUBS","DIAMONDS"
	switch(suit){
	case SPADES:
		suitChar = 'S';
		break;
	case HEARTS:
		suitChar = 'H';
		break;
	case CLUBS:
		suitChar = 'C';
		break;
	case DIAMONDS:
		suitChar = 'D';
		break;
	}
    return suitChar + ": " + rank;*/
}

t_suit card::getSuit(){
    return suit;
}
t_rank card::getRank(){
	if(rank >= 10)
	{
		if(rank == 'A') 
			rank = '1';
		else
			int(rank) = 10;
	}

    return t_rank(rank);
}

/*int main()
{
    card c(HEARTS, 'J');
    cout << c.name() << endl;
	system("pause");
    return 0;
}*/

