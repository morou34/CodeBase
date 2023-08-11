#include <iostream>
#include <string>
class Player
{
private:
    std::string name;
    int xp;
    int health;

public:
    Player(std::string name_val, int h_val, int xp_val);
    Player(const Player &source);
    void player_info();
};

Player::Player(std::string name_val = "None", int h_val = 100, int xp_val = 0) : name{name_val}, health{h_val}, xp{xp_val} {};

void Player::player_info()
{
    printf("%s | health: %d | xp: %d\n", name.c_str(), health, xp);
};

Player::Player(const Player &source) : name{source.name}, xp{source.xp}, health{source.health} {};

// delegation constructor: calling a constructor to initialize an object
class Enemy
{
private:
    std::string name;
    std::string type;
    int damage;

public:
    Enemy();
    Enemy(std::string name_val, int dmg);
    Enemy(std::string name_val, std::string type_val, int dmg);
    void display_enemy();
};

Enemy::Enemy(std::string name_val, std::string type_val, int dmg) : name{name_val}, type{type_val}, damage{dmg} {};

Enemy::Enemy() : Enemy{"Akatsuki", "Water", 100} {};

Enemy::Enemy(std::string name_val, int dmg) : Enemy{name_val, "Water", dmg} {};

void Enemy::display_enemy()
{
    printf("%s | Nature Type: %s | damage: %d\n", name.c_str(), type.c_str(), damage);
}

void copy_player_info(Player p)
{
    std::cout << "\nCopy made for the object:\n";
    p.player_info();
}

int main(int argc, char const *argv[])
{
    Player ali;
    Player mouaad("Mouaad");
    Player dragon("Dragon", 200);
    Player mayoubaz("Mayoubz", 100, 999);
    Player charlie{mayoubaz};

    ali.player_info();
    mouaad.player_info();
    dragon.player_info();
    mayoubaz.player_info();
    copy_player_info(charlie);

    Enemy nagato("Nagato", "Fire - Wind - Water - Lightning", 999);
    Enemy tobi("Tobi", 8989);
    Enemy sasori;

    std::cout << std::endl;
    nagato.display_enemy();
    tobi.display_enemy();
    sasori.display_enemy();
    return 0;
}
