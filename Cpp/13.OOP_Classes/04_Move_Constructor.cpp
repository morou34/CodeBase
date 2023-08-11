#include <iostream>
#include <string>
#include <vector>

class Game
{
private:
    int *data;

public:
    Game(int d);
    Game(const Game &source);
    Game(Game &&source) noexcept;
    ~Game();
};

Game::Game(int d)
{
    data = new int; // you need to allocate memory for this pointer in order to use it.
    *data = d;
    printf("Constructor for: %d\n", *data);
}
// Copy constructor
Game::Game(const Game &source) : Game{*source.data}
{
    printf("Deep Copy for: %d\n", *data);
};

// Move Constructor
Game::Game(Game &&source) noexcept : data{source.data}
{
    source.data = nullptr;
    printf("Move Constructor for: %d\n", *data);
}

Game::~Game()
{
    if (data != nullptr)
        printf("De-constructor for: %d\n", *data);
    else
        printf("De-constructor for nullptr\n");
    delete data;
}
// this ponter

class Player
{
private:
    int strength;
    std::string name;

public:
    Player(std::string name, int p);
    void compare_strength(const Player &other);
};

Player::Player(std::string name, int p) : name{name}, strength{p} {}
void Player::compare_strength(const Player &other)
{
    if (this->strength > other.strength)
        printf("%s is stronger than %s.\n", this->name.c_str(), other.name.c_str());
}

int main(int argc, char const *argv[])
{
    std::vector<Game> vec;
    int LENGTH = 100'000;
    // for (int i{0}; i < LENGTH; ++i)
    //     vec.push_back(Game{i});

    Player dragon("Dragon", 1000);
    Player lion("Lion", 299);
    dragon.compare_strength(lion);
    return 0;
}

// 2.71