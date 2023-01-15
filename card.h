#ifndef __CARD_H__
#define __CARD_H__
#include <string>
#include <iostream>
#include <vector>

typedef std::vector<std::string> card_template_t;

struct info{
    public:
    std::string card_name;
    int magic_cost;
    std::string desc;
};

enum card_type : int{
    type_minion = 0,
    type_enchantment = 1,
    type_ritual = 2,
    type_spell = 3
};

class Card {
    //int owner; //player 1 or player 2（如果两人的卡组里有同一张牌 是否需要这个filed来判断是谁的牌改变了）
    std::string card_name;
    int magic_cost;
    card_type type;
    std::string desc; //description of card ability //for print

    public:
    //ctor
    Card(std::string card_name, int magic_cost, card_type type, std::string desc);
    int get_cost() const;
    info get_info() const;
    card_type get_type() const;
    virtual card_template_t print() const = 0;

};

std::ostream& operator<<(std::ostream& os, const Card & c);

#endif