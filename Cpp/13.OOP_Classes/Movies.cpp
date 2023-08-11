#include "Movies.h"

Movies::Movies() {}
Movies::~Movies() {}

void Movies::add_movie(std::string title, std::string rating, int watch_count)
{
    for (const Movie &movie : movies)
    {
        if (movie.get_title() == title)
        {
            printf("%s exists already.", title.c_str());
            return;
        }
    }

    Movie movie(title, rating, watch_count);
    movies.push_back(movie);
}

void Movies::increment_movie(std::string title, int d)
{
    for (Movie &movie : movies)
    {
        if (movie.get_title() == title)
        {
            movie.set_watch_count(d);
            break;
        }
    }
    printf("%s not found, can't increment watch-cout.\n", title.c_str());
}

void Movies::diplay_movies()

{
    if (movies.size() == 0)
    {
        printf("No movies in collection.");
    }
    else
    {
        printf("\n______________________\n");
        for (auto item : movies)
        {
            std::cout << item.get_title() << " | " << item.get_rating() << " | " << item.get_watch_count() << std::endl;
        }
    }
}