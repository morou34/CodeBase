#ifndef Movies_H_
#define Movies_H_
#include <vector>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;

public:
    Movies();
    ~Movies();
    void add_movie(std::string title, std::string rating, int watch_count);
    void increment_movie(std::string title, int d = 19);
    void diplay_movies();
};

#endif // !Movie_H_