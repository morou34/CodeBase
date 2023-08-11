#include <iostream>
#include <map>

// __ MAP __

// Implemented using a Tree
// Elements are stored as KEY, VALUE pairs(std::pair)
// Ordered by KEY
// KEYS are unique no duplicates
// Direct access using the KEY
/* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -*/

// __ Multi MAP __
// Allow duplicates
// Ordered by key

int main(int argc, char const *argv[])
{

    /* -- -- -- -- -- -- -- -- -- -- --MAP-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -*/

    // Declaration and display
    std::map<int, std::string> team = {
        {7, "Alex"},
        {10, "Adam"},
        {11, "Moe"},
        {4, "Leo"}};

    // Players are displayed in order by Key (player number)
    const auto printMap = [](const std::map<int, std::string> &team)
    {
        std::cout << "\n===== printMAP ==========" << std::endl;
        for (const auto &player : team)
            std::cout << "Player: " << player.first << " | "
                      << player.second << std::endl;
        std::cout << "==================\n"
                  << std::endl;
    };

    const auto printMMap = [](const std::multimap<char, std::string> &mm)
    {
        std::cout << "\n===== print MULTIMAP ==========" << std::endl;
        for (const auto &player : mm)
            std::cout << "Grade: " << player.first << " | Students: "
                      << player.second << std::endl;
        std::cout << "=================================\n"
                  << std::endl;
    };

    printMap(team);
    auto player = team[11];
    std::cout << "Player number 11: " << player << std::endl; // Moe

    auto player2 = team[100]; // key doesn't exist
    // auto player2 = team.at(100); // error
    std::cout << "Player number 100: " << player2 << std::endl;

    // Inserting an element
    // Method 1
    team[22] = "Ford"; // team.at(22) = "Ford"
    std::cout << "Player number 22: " << team.at(22) << std::endl;

    // Method 2
    std::pair<int, std::string> newPlayer{9, "Charlie"};
    team.insert(newPlayer);
    std::cout << "Player number 9: " << team.at(9) << std::endl;
    team.insert(std::make_pair(88, "David"));

    // Update:
    team[22] = "Chakal";
    printMap(team);

    // Erase element:
    team.erase(100);

    auto it = team.find(22);
    if (it != team.end())
    {
        std::cout << it->second << " is erased.\n";
        team.erase(it);
    }

    printMap(team);

    // Search for an element
    if (team.find(10) != team.end())
        std::cout << team.at(10) << " is found.\n";

    // Check if an element exists on the map
    size_t num_88 = team.count(88);
    size_t num_99 = team.count(99);
    std::cout << "Count(88): " << num_88 << "\nCount(99): " << num_99 << std::endl;

    // Clear & Empty
    std::cout << "empty(): " << team.empty() << std::endl;
    // team.clear(); // removes all elements.

    /* -- -- -- -- -- -- -- -- -- -- -- MULTI_MAP -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -*/
    std::multimap<char, std::string> grades;

    std::pair<char, std::string> groupB{'B', "Merry, Jhon, David"};

    grades.insert(std::make_pair('A', "Alex, Ayoub"));
    grades.insert(groupB);
    printMMap(grades);

    grades.insert({'A', "Elly, Beck"});
    grades.insert({'C', "Bob"});
    grades.insert({'A', "Sam, Joe, Moe"});
    printMMap(grades);

    return 0;
}
