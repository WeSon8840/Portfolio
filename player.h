#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "hand.h"
#include "playernum.h"
#include "deck.h"

typedef std::vector<std::string> card_template_t;


class Board;

class Player{
    private:
    std::shared_ptr<Board> board;
    int hp;
    int mag;
    std::string name;
    Hand hand;
    Deck deck;
    public:
    Player(std::string Name, int HP, int Mag, std::string deck_from);
    void set_Board(std::shared_ptr<Board> board);
    void draw();
    void addHand(std::shared_ptr<Card> c);
    void discard(int n);
    card_template_t print(playernum player_num) const;
    void change_mag(int n);
    void change_hp(int n);
    int get_hp() const;
    card_template_t show_hand() const;
    void play(int c);
};

#endif