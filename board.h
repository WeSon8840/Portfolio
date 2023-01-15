#ifndef __BOARD_H__
#define __BOARD_H__
#include "card.h"
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "graveyard.h"
#include "playernum.h"

typedef std::vector<std::string> card_template_t;

class Player;

class Ritual;

class Component;

class Graveyard;



class Winner {
    private:
    playernum winner;
    public:
    Winner(playernum player): winner{player} {}
};

class Board{
    private:
    playernum current_player;
    std::map<playernum, std::shared_ptr<Player>> players;
    std::map<playernum, std::vector<std::shared_ptr<Component>>> minions;
    std::map<playernum, std::shared_ptr<Ritual>> ritual;
    std::map<playernum, Graveyard> graveyards;
    public:
    Board(playernum current, std::map<playernum, std::shared_ptr<Player>> players);
    void cleanup();
    void play(std::shared_ptr<Card> c, int p, int e);
    void play(std::shared_ptr<Card> c);
    void attack(int n);
    void attack(int n, int m);
    bool checkAvailable(playernum p, int n);
    std::shared_ptr<Card> popMinion(int p, int n);
    // some other functions
    void endTurn();
    void startTurn();
    card_template_t print() const;
};

std::ostream& operator<<(std::ostream& os, const Board & b);

#endif