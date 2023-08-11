#include "Movies.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Movies movies;

    movies.add_movie("Batman", "PG-18", 1);
    movies.add_movie("Uncharted", "PG-3", 1);
    movies.add_movie("Snowpiercer", "PG-10", 1);
    movies.diplay_movies();

    movies.increment_movie("One Piece");
    movies.increment_movie("Batman", 3);

    movies.add_movie("Superman", "PG-20", 2);
    movies.add_movie("Uncharted", "PG-3", 1);
    movies.diplay_movies();

    return 0;
}
