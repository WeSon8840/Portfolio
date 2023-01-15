#include "enchantment.h"
#include "minion.h"
#include "ascii_graphics.h"

Enchantment::Enchantment(std::string card_name, int magic_cost, std::string desc):
        Component{card_name, magic_cost, type_enchantment, desc},
        next{},
        s{unbounded}{}

int Enchantment::get_attack() const{
        return next->get_attack();
}

int Enchantment::get_defence() const{
        return next->get_defence();
}

int Enchantment::get_act_pt() const{
        return next->get_act_pt();
}

card_template_t Enchantment::print() const{
        if (s == bounded){
                return next->print(get_attack(),get_defence());
        }
        info i = get_info();
        return display_enchantment(i.card_name,i.magic_cost,i.desc);
}

card_template_t Enchantment::print(int atk, int def) const{
        return next->print(atk,def);
}

std::shared_ptr<Component> Enchantment::get_base() const{
        if (next->get_type() == type_minion){
                return next;
        }
        std::shared_ptr<Enchantment> m = std::dynamic_pointer_cast<Enchantment>(next);
        return m->get_base();
}

void Enchantment::set_attack(int n){
        next->set_attack(n);
}

void Enchantment::set_defence(int n){
        next->set_defence(n);
}