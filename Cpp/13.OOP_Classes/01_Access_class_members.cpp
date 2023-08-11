#include <iostream>
#include <string>
class Player
{
public:
    std::string name{};
    int health;
    long xp;

    bool isDead()
    {
        if (health <= 0)
            return true;
        return false;
    };
    void display_info()
    {
        printf("Name: %s | Health: %d | Xp: %ld\n", name.c_str(), health, xp);
    }
};

int main(int argc, const char **argv)
{
    Player alex;
    alex.name = "Alex";
    alex.health = 100;
    alex.xp = 240;

    alex.display_info();

    // Pointer -> Player object
    Player *adam = new Player();
    adam->name = "adam";
    adam->health = 200;
    adam->xp = 2094;
    adam->display_info();
    adam->health -= 23333;
    std::cout << "Is adam dead ? " << adam->isDead() << std::endl;
    return 0;
}