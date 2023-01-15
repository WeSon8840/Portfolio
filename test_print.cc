#include "ascii_graphics.h"
#include "all_cards.h"

#include "hand.h"
#include <memory>
#include <iostream>

void test_print(){
    Hand h{};
    RaiseDead c1{};
    h.add(std::make_shared<RaiseDead>());
    std::cout << c1 << std::endl;
    std::cout << h << std::endl;
    Potion_S c2{};
    h.add(std::make_shared<Potion_S>());
    std::cout << h << std::endl;
    std::cout << *(h.pop(2)) << std::endl;
    std::cout << h << std::endl;
    h.add(std::make_shared<Standstill>());
    card_template_t graph = h.print();
    std::cout << add_border(append(graph,h.print())) << std::endl;
}