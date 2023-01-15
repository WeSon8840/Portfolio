#ifndef __RITUAL_H__
#define __RITUAL_H__
#include "card.h"

class Ritual : public Card {
    int charge;
    int acti_cost; //activation cost

    public:
    Ritual(std::string card_name, int magic_cost,
           std::string desc, int charge, int acti_cost);
    card_template_t print() const override;
};

#endif