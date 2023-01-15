#ifndef __MINION_H__
#define __MINION_H__
#include "component.h"

class Minion : public Component {
    int attack;
    int defence;
    int action_pt;
    public:
    Minion(std::string card_name, int magic_cost, std::string desc,
           int attack, int defence);
    int get_act_pt() const override;
    int get_attack() const override;
    int get_defence() const override;
    void set_attack(int n) override;
    void set_defence(int n) override;
    card_template_t print() const override;
    card_template_t print(int atk, int def) const override;
};

#endif