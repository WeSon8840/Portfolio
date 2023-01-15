#include "all_cards.h"
#include "board.h"
#include "player.h"
#include "ritual.h"
#include "component.h"
#include "graveyard.h"
#include "ascii_graphics.h"

Board::Board(playernum current, std::map<playernum, std::shared_ptr<Player>> players) 
    : current_player{current}, players{players}{
        minions.emplace(player1,std::vector<std::shared_ptr<Component>>());
        minions.emplace(player2,std::vector<std::shared_ptr<Component>>());
        graveyards.emplace(player1,Graveyard());
        graveyards.emplace(player2,Graveyard());
        ritual.emplace(player1,std::shared_ptr<Ritual>(nullptr));
        ritual.emplace(player2,std::shared_ptr<Ritual>(nullptr));
    }

card_template_t Board::print() const{
    playernum p1 = player1;
    playernum p2 = player2;
    card_template_t p1_player{};
    card_template_t p2_player{};
    card_template_t p1_minion{};
    card_template_t p2_minion{};
    p1_player = graveyards.at(p1).print() + CARD_TEMPLATE_EMPTY + players.at(p1)->print(p1) + CARD_TEMPLATE_EMPTY;
    if (ritual.at(p1) != std::shared_ptr<Ritual>(nullptr)){
        p1_player = p1_player + ritual.at(p1)->print();
    } else{
        p1_player = p1_player + CARD_TEMPLATE_BORDER;
    }
    p2_player = graveyards.at(p2).print() + CARD_TEMPLATE_EMPTY + players.at(p2)->print(p2) + CARD_TEMPLATE_EMPTY;
    if (ritual.at(p2) != std::shared_ptr<Ritual>(nullptr)){
        p2_player = p2_player + ritual.at(p2)->print();
    } else{
        p2_player = p2_player + CARD_TEMPLATE_BORDER;
    }
    for (int i = 0; i < 5; i++){
        if (minions.at(p1).size() > i){
            p1_minion = p1_minion + minions.at(p1).at(i)->print();
        }else{
            p1_minion = p1_minion + CARD_TEMPLATE_BORDER;
        }
        if (minions.at(p2).size() > i){
            p2_minion = p2_minion + minions.at(p2).at(i)->print();
        }else{
            p2_minion = p2_minion + CARD_TEMPLATE_BORDER;
        }
    }
    card_template_t upper = add_left_right_border(append(p1_player,p1_minion));
    card_template_t lower = add_left_right_border(append(p2_minion,p2_player));
    return add_top_bottom_border(append(append(upper, CENTRE_GRAPHIC),lower));
}

std::ostream& operator<<(std::ostream& os, const Board & b){
    os << b.print();
    return os;
}

playernum other(playernum player) {
    if (player == player1) {
        return player2;
    } else {
        return player1;
    }
}

void Board::cleanup() {
    for (auto m: minions.at(current_player))  {
        if (m->get_defence() <= 0) {
            graveyards.at(current_player).add(m);
        }
    }
    for (auto m: minions.at(other(current_player)))  {
        if (m->get_defence() <= 0) {
            graveyards.at(other(current_player)).add(m);
        }
    }
    if (players.at(current_player)->get_hp() <= 0) {
        throw Winner(current_player);
    } else {
        throw Winner(other(current_player));
    }
}

bool Board::checkAvailable(playernum p, int n) {
    if (minions.find(p)->second.size() <= n) {
        return false;
    } else {
        return true;
    }
}

void Board::attack(int n) {
    //need to throw exception here if no minion exists at this position
    if (minions.find(current_player)->second[n - 1]->get_act_pt()) {
        players.find(other(current_player))->second->change_hp(- minions.find(current_player)->second[n - 1]->get_attack());
        //decrease action point by 1
    } else {
        //exception: no action point available
    }
}

void Board::play(std::shared_ptr<Card> c){
    if (c->get_type() == type_ritual){
        ritual.at(current_player) = std::dynamic_pointer_cast<Ritual>(c);
        return;
    }
    if (c->get_type() == type_minion){
        if (minions.at(current_player).size() <= 5){
            minions.at(current_player).push_back(std::dynamic_pointer_cast<Component>(c));
            return;
        }
        // not enough space
        return;
    }
}

void Board::attack(int n, int m){
    //exception1: no minion exists at ally position
    //exception2: no minion exists at enemy position
    auto ally = minions.find(current_player)->second[n - 1];
    auto enemy = minions.find(other(current_player))->second[m - 1];
    if (ally->get_act_pt()) {
        int ally_atk = ally->get_attack();
        int ally_def = ally->get_defence();
        int enemy_atk = enemy->get_attack();
        int enemy_def = enemy->get_defence();
        ally->set_defence(ally_def - enemy_atk);
        enemy->set_defence(enemy_def - ally_atk);
    } else {
        //exception: no action point available
    }
}

void Board::endTurn(){
    current_player = other(current_player);
    startTurn();
    // specify later
    return;
}

void Board::startTurn(){
    // specify later
    players.at(current_player)->draw();
    return;
}