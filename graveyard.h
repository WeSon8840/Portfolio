#ifndef __GRAVEYARD_H__
#define __GRAVEYARD_H__

#include <string>
#include <vector>
#include <memory>

typedef std::vector<std::string> card_template_t;

class Component;

class Graveyard{
    private:
    std::vector<std::shared_ptr<Component>> minions;
    public:
    Graveyard();
    void add(std::shared_ptr<Component> c);
    bool isEmpty() const;
    std::shared_ptr<Component> pop();
    card_template_t print() const;
};

std::ostream& operator<<(std::ostream& os, const Component & h);

#endif