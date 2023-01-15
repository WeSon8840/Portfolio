#include "graveyard.h"
#include "card.h"
#include "component.h"
#include "ascii_graphics.h"

Graveyard::Graveyard():
    minions{}{}


bool Graveyard::isEmpty() const{
    return minions.size() == 0;
}

std::shared_ptr<Component> Graveyard::pop(){
    if (isEmpty()){
        return std::shared_ptr<Component>();
    }
    std::shared_ptr<Component> res = minions.back();
    minions.pop_back();
    return res;
}

void Graveyard::add(std::shared_ptr<Component> c){
    minions.push_back(c);
}
card_template_t Graveyard::print() const{
    if (isEmpty()){
        return CARD_TEMPLATE_BORDER;
    }
    return minions.back()->print();
}

std::ostream& operator<<(std::ostream& os, const Component & h){
    os << h.print();
    return os;
}