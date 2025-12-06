#include <vector>

#include "simulator/actors/actor.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map
{
public:
    const std::vector<Actor*>& getActors() const { return actors_; }
    void registerActor(Actor* new_actor) { actors_.push_back(new_actor); }

private:
    std::vector<Actor*> actors_;

};

#endif /* MAP_HPP */