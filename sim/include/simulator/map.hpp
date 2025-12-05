#include <vector>

#include "actor.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map
{
public:
    const std::vector<Actor>& getActors() const { return actors_; }

private:
    std::vector<Actor> actors_;

};

#endif /* MAP_HPP */