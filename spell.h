#ifndef __SPELLS_H__
#define __SPELLS_H__

#include "card.h"

class Spell : public Card {
    public:
    Spell(std::string card_name, 
          int magic_cost, std::string desc);
    card_template_t print() const override;
};

#endif