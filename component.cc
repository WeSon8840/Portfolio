#include "component.h"

Component::Component(std::string card_name, int magic_cost, card_type type, std::string desc):
    Card{card_name, magic_cost, type, desc} {}

