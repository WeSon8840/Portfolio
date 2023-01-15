#ifndef __ENCHANTMENT_H__
#define __ENCHANTMENT_H__
#include "component.h"
#include <memory>

enum state : int{
    bounded = 0,
    unbounded = 1
};

class Enchantment : public Component {
    private:
    std::shared_ptr<Component> next;
    state s;
    public:
    Enchantment(std::string card_name, int magic_cost, std::string desc);
    int get_attack() const override;
    int get_defence() const override;
    int get_act_pt() const override;
    void set_attack(int n) override;
    void set_defence(int n) override;
    card_template_t print() const override;
    card_template_t print(int atk, int def) const override;
    std::shared_ptr<Component> get_base() const;
};

#endif