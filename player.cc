#include "player.h"
#include "board.h"
#include "ascii_graphics.h"



Player::Player(std::string Name, int HP, int Mag, std::string deck_from):
    board{},
    hp{HP},
    mag{Mag},
    name{Name},
    hand{},
    deck{deck_from}
    {}
    
void Player::set_Board(std::shared_ptr<Board> b){
    board = b;
}

void Player::draw(){
    if (hand.isFull()) return;
    if (deck.is_empty()) return;
    hand.add(deck.pop());
}

void Player::addHand(std::shared_ptr<Card> c){
    if (hand.isFull()) return; // or error or other behavior
    hand.add(c);
}

void Player::discard(int n){
    hand.pop(n);
}

card_template_t Player::print(playernum player_num) const{
    if (player_num == player2){
        return display_player_card(2,name,hp,mag);
    }
    return display_player_card(1,name,hp,mag);
}

void Player::change_mag(int n){
    mag += n;
}

void Player::change_hp(int n){
    hp += n;
}

int Player::get_hp() const{
    return hp;
}

card_template_t Player::show_hand() const{
    return hand.print();
}

void Player::play(int n){
    //need to check for conditions here.
    std::shared_ptr<Card> c = hand.pop(n);
    mag = mag - c->get_cost();
    board->play(c);
}