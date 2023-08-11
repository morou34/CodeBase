#include "Player.h"

void display_players_count()
{
    int total = Player::get_players_count();
    std::cout << "Total players: " << total << std::endl;
}
int main(int argc, char const *argv[])
{
    display_players_count();
    Player bee;
    display_players_count();
    Player dragon("Dragon", 999);
    display_players_count();

    return 0;
}
