#ifndef Player_H_
#define Player_H_
#include <string>
#include <iostream>

class Player
{
private:
    std::string name;
    int rank;
    static int players_count;

public:
    Player();
    Player(std::string name);
    Player(std::string name, int rank);
    ~Player();

    static int get_players_count();
};

#endif