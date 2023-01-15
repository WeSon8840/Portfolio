#include "bomb.h"

Bomb::Bomb():
    Minion{"Bomb", 2, 
           "Deals damage to all the opponent minions equal to its attack value when it dies", 
           1, 2} {}