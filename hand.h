#ifndef __HAND_H__
#define __HAND_H__

#include <string>
#include <vector>
#include <memory>

typedef std::vector<std::string> card_template_t;

class Card;

class Hand{
    private:
    std::vector<std::shared_ptr<Card>> cards;
    public:
    Hand();
    void add(std::shared_ptr<Card> c);
    bool isFull();
    std::shared_ptr<Card> peek(int n); // returns the nth card (n is from 1 to 5)
    std::shared_ptr<Card> pop(int n); // returns and removes the nth card (n is from 1 to 5)
    card_template_t print() const;
};

std::ostream& operator<<(std::ostream& os, const Hand & h);

#endif