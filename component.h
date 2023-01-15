#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include "card.h"


class Component : public Card {
    public:
    Component(std::string card_name, int magic_cost, card_type type, std::string desc);
    virtual card_template_t print() const = 0;
    virtual card_template_t print(int atk, int def) const = 0;
    virtual int get_attack() const = 0;
    virtual int get_defence() const = 0;
    virtual int get_act_pt() const = 0; 
    virtual void set_defence(int n)  = 0;
    virtual void set_attack(int n) = 0;
};

#endif