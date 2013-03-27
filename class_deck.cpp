#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "class_deck.h"
#include "class_card.h"
#include <vector>
#include<string>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace cards;

void fillVector(vector<card>&);
void printVector(const vector<card>&);


void fillVector(vector<card>& newMyClass){
    for(int j=0; j<NUM_RANKS; j++){
        for(int i=0; i<NUM_SUITS;i++){
            newMyClass.push_back(card((t_suit)i,ranks[j]));
        }
    }
}

void printVector( vector<card>& newMyClass){
    size_t size = newMyClass.size();
    for(size_t i = 0; i < size; i++){
        cout << newMyClass[i].name() << endl;
    }
}
deck::deck(){
	cards.reserve(52); 
	fillVector(cards);
    //printVector(cards);
}

//fill the deck with several 52card-sets
deck::deck(int deckCount){
	cards.reserve(deckCount*52);
	for(int dcount = 1; dcount <= deckCount; dcount++){
	    for(int j=0; j<NUM_RANKS; j++){
			for(int i=0; i<NUM_SUITS;i++){
				deck::cards.push_back(card((t_suit)i,ranks[j]));
        
			}
		}
    }

	printVector(cards);
}

void deck::shuffle(){
	//cout << "shuffling the crads ..." << endl;
	random_shuffle(cards.begin(), cards.end());
	//printVector(cards);
}


card deck::deal(){
	card cardOnTheTop = cards[cards.size() - 1];
	cards.pop_back();
	return cardOnTheTop;
}

int deck::size(){
	/*int remainingCards = 0;
	for(size_t i = 0; i <= cards.size(); i++){
		if(cards[i] == null)
			remainingCards++;
	}
	return remainingCards;*/
	return cards.size();
	
}

