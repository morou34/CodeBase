#include "Player.h"

int Player::players_count{0};
Player::Player(std::string name, int rank) : name{name}, rank{rank}
{
    ++players_count;
    std::cout << "Player " << this->name << " created." << std::endl;
}

Player::Player() : Player{"Private", 1} {}
Player::Player(std::string name) : Player{name, 1} {}

Player::~Player()
{
    --players_count;
    std::cout << "Player " << name << " deleted." << std::endl;
    std::cout << "Total players: " << players_count << std::endl;
}

int Player::get_players_count()
{
    return players_count;
}