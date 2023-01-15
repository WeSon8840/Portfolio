#include "spell.h"
#include "ascii_graphics.h"

Spell::Spell(std::string card_name, int magic_cost, 
             std::string desc):
    Card{card_name, magic_cost, type_spell, desc} {}

card_template_t Spell::print() const{
    info i = get_info();
    return display_spell(i.card_name, i.magic_cost, i.desc);
}