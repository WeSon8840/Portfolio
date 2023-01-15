#include "hand.h"
#include "card.h"
#include "ascii_graphics.h"

Hand::Hand():
    cards{}{}

void Hand::add(std::shared_ptr<Card> c){
    if (isFull()){
        // throw error?
        return;
    }
    cards.emplace_back(c);
}

bool Hand::isFull(){
    return cards.size() == 5;
}

std::shared_ptr<Card> Hand::peek(int n){
    if (n > cards.size()){
        // throw error?
        std::shared_ptr<Card> null;
        return null;
    }
    return cards.at(n - 1);
}
std::shared_ptr<Card> Hand::pop(int n){
    std::shared_ptr<Card> res = peek(n);
    cards.erase(cards.begin() + n - 1);
    return res;
}
card_template_t Hand::print() const{
    card_template_t result{};
    for (auto c : cards){
        result = result + c->print();
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Hand & h){
    os << h.print();
    return os;
}