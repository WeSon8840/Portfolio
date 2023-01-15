#include "minion.h"
#include "ascii_graphics.h"


Minion::Minion(std::string card_name, int magic_cost, std::string desc,
               int attack, int defence):
        Component{card_name, magic_cost, type_minion, desc},
        attack{attack}, defence{defence}, action_pt{0} {}

int Minion::get_attack() const{
       return attack;
}

int Minion::get_defence() const{
       return defence;
}

int Minion::get_act_pt() const{
       return action_pt;
}

void Minion::set_attack(int n){
       attack = n;
}

void Minion::set_defence(int n){
       defence = n;
}

card_template_t Minion::print() const{
       info i = get_info();
       return display_minion_no_ability(i.card_name,i.magic_cost,attack,defence);
}

card_template_t Minion::print(int atk, int def) const{
       info i = get_info();
       return display_minion_no_ability(i.card_name,i.magic_cost,atk,def);
}