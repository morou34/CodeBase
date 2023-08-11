#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iomanip>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &song);
    friend bool operator==(const Song &lhs, const Song &rhs);
    friend bool operator<(const Song &lhs, const Song &rhs);

private:
    std::string title, artist;
    int rating;

public:
    Song();
    Song(std::string title, std::string artist, int rating);
};

Song::Song() = default;
Song::Song(std::string title, std::string artist, int rating) : title{title}, artist{artist}, rating{rating} {};

bool operator==(const Song &lhs, const Song &rhs)
{
    return (lhs.title == rhs.title);
}

bool operator<(const Song &lhs, const Song &rhs)
{
    return (lhs.rating < rhs.rating);
}

std::ostream &operator<<(std::ostream &os, const Song &song)
{
    os << std::setw(20) << std::left << song.title
       << std::setw(20) << std::left << song.artist
       << std::setw(2) << std::left << song.rating;
    return os;
};

void display_current_song(const Song &song)
{
    std::cout << "\nPlaying:\n";
    std::cout << song << std::endl;
};

void display_playlist(const std::list<Song> &songs, const Song &song)
{
    std::system("cls");
    std::cout << "==========================================" << std::endl;
    for (const Song &song : songs)
        std::cout << song << std::endl;
    std::cout << "==========================================" << std::endl;

    display_current_song(song);
};

void display_menu()
{
    std::cout << "\nF- Play First Song" << std::endl;
    std::cout << "E- Play Last Song" << std::endl;
    std::cout << "N- Play Next Song" << std::endl;
    std::cout << "P- Play Previous Song" << std::endl;
    std::cout << "A- Add and Play New Song" << std::endl;
    std::cout << "L- List Current Playlist" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Q- Enter A Selection (Q to quit): ";
}

int main(int argc, char const *argv[])
{

    std::list<Song> songs{
        {"Pink Venom", "BLACKPINK", 4},
        {"I Ain't Worried", "OneRepublic", 5},
        {"Lonely", "Anna", 5},
        {"Dynamite", "BTS", 3},
    };

    std::list<Song>::iterator it = songs.begin();

    display_playlist(songs, *it);
    char selection = 'F';

    do
    {

        display_menu();
        std::cin >> selection;
        std::cin.clear();
        fflush(stdin);
        switch (selection)
        {
        case 'F':
            std::cout << "Playing First Song." << std::endl;
            it = songs.begin();
            display_current_song(*it);
            break;
        case 'E':
            it = songs.end();
            --it;
            display_current_song(*it);

            break;
        case 'N':
            ++it;
            if (it == songs.end())
            {
                it = songs.begin();
            }
            display_current_song(*it);

            break;

        case 'P':
            if (it == songs.begin())
            {
                it = songs.end();
                --it;
            }
            else
            {
                --it;
            }
            display_current_song(*it);
            break;
        case 'A':
        {
            std::string title, artist, rating;
            std::cout << "Enter Song Title: ";
            std::getline(std::cin, title);
            std::cin.clear();
            fflush(stdin);

            std::cout << "Enter Song Artist: ";
            std::getline(std::cin, artist);

            std::cin.clear();
            fflush(stdin);

            std::cout << "Enter Song Rating: ";
            std::getline(std::cin, rating);
            std::cin.clear();
            fflush(stdin);

            Song new_song{title, artist, std::stoi(rating)};

            if (it == songs.begin())
            {
                songs.push_front(new_song);
            }
            else
            {
                songs.insert(it, new_song);
            }
            it = std::prev(it);
            display_playlist(songs, *it);
            break;
        }

        case 'L':
            display_playlist(songs, *it);
            break;
        default:
            std::cout << "Please select a correct choice." << std::endl;
            break;
        }

    } while (selection != 'Q' && selection != 'q');

    return 0;
}
