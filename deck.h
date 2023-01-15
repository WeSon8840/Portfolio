#ifndef __DECK_H__
#define __DECK_H__


#include <string>
#include <vector>
#include <memory>
#include "card.h"



class Deck {
    //std::string player_name;
    std::string filename;
    std::vector<std::shared_ptr<Card>> deck;

    public:
    //ctor
    Deck(std::string filename);
    
    //read from file and form a deck
    void initDeck(std::string filename);
    // shuffle
    void shuffle();
    //check empty
    bool is_empty() const;
    //pop card from deck
    std::shared_ptr<Card> pop();
    card_template_t print() const;
};


#endif 