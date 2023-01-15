#include "ritual.h"
#include "ascii_graphics.h"

Ritual::Ritual(std::string card_name, int magic_cost, 
               std::string desc, int charge, int acti_cost):
        Card{card_name, magic_cost, type_ritual, desc}, 
        charge{charge}, acti_cost{acti_cost} {}

card_template_t Ritual::print() const{
       info i = get_info();
       return display_ritual(i.card_name,i.magic_cost,acti_cost,i.desc,charge);
}