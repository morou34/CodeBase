#ifndef Movie_H_
#define Movie_H_
#include <string>
#include <iostream>

class Movie
{
private:
    std::string title;
    std::string rating;
    int watch_count;

public:
    Movie(std::string title, std::string rating, int watch_cout);
    std::string get_title() const;
    std::string get_rating() const;
    int get_watch_count() const;
    void set_watch_count(int inc);
    ~Movie();
};

#endif // !1