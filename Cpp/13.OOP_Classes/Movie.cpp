#include "Movie.h"

Movie::Movie(std::string title, std::string rating, int watch_count) : title{title}, rating{rating}, watch_count{watch_count} {}

void Movie::set_watch_count(int inc)
{
    watch_count += inc;
}

std::string Movie::get_title() const
{
    return this->title;
}
std::string Movie::get_rating() const
{
    return rating;
}
int Movie::get_watch_count() const
{
    return watch_count;
}

Movie::~Movie() {}