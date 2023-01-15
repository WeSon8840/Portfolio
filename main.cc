#include <iostream>
#include <string>
#include "card.h"
#include "player.h"
#include "board.h"
#include "deck.h"
#include "ascii_graphics.h"

const std::string help_message = "Commands: help -- Display this message.\n          end -- End the current player’s turn.\n          quit -- End the game.\n          attack minion other-minion -- Orders minion to attack other-minion.\n          attack minion -- Orders minion to attack the opponent.\n          play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player.\n          use minion [target-player target-card] -- Use minion’s special ability, optionally targeting target-card owned by target-player.\n          inspect minion -- View a minion’s card and all enchantments on that minion.\n          hand -- Describe all cards in your hand.\n          board -- Describe all cards on the board.";

playernum other_player(playernum current);

int main(int argc, char *argv[]) {
    //ask player names.
    std::string deck1 = "default.deck";
    std::string deck2 = "default.deck";
    std::cout<<"Player1 name:"<<std::endl;
    std::string p1name;
    std::getline(std::cin, p1name);
    std::cout<<"Player2 name:"<<std::endl;
    std::string p2name;
    std::getline(std::cin, p2name);
    std::map<playernum, std::shared_ptr<Player>> players;
    players.emplace(player1, std::make_shared<Player>(p1name,20,3,deck1));
    players.emplace(player2, std::make_shared<Player>(p2name,20,3,deck2));
    playernum current = player1; // current player. 
    std::shared_ptr<Board> board = std::make_shared<Board> (current, players);
    players.at(player1)->set_Board(board);
    players.at(player2)->set_Board(board);
    board->startTurn();
    std::string command;
    while (getline(std::cin, command)){
        if(command == "help"){
            std::cout<<help_message<<std::endl;
        }
        if(command == "hand"){
            std::cout<<players.at(current)->show_hand();
        }
        if(command == "draw"){
            players.at(current)->draw();
        }
        if(command == "end"){
            current = other_player(current);
            board->endTurn();
        }
        if(command == "board"){
            std::cout << board->print();
        }
        if(command == "quit"){
            break;
        }
        if(command.substr(0,5) == "play "){
            // naive implementation. need more checking.
            int n = std::stoi(command.substr(5));
            players.at(current)->play(n);
        }
    }
}

playernum other_player(playernum current){
    if (current == player1){
        return player2;
    }
    return player1;
}