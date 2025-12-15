#include <vector>

#include "simulator/actors/actor.hpp"

#ifndef MAP_HPP
#define MAP_HPP

typedef std::vector<std::vector<int>> GridType;

class Map   // used for MPC only. Units = 1m
{
public:
    Map(int world_size = 100) : occupancyGrid_(world_size, std::vector<int>(world_size, 0)) {  }
    const std::vector<Actor*>& getActors() const { return actors_; }
    void registerActor(Actor* new_actor) { actors_.push_back(new_actor); }  // use raw pointers so that I "borrow" ownership from the simulator class, which owns via unique_ptr
    const GridType& grid() const { return occupancyGrid_; }
    void setCell(const int& x, const int& y, const int& val) { occupancyGrid_[x][y] = val; }    //TODO: make enum for different values
    void clearCell(const int& x, const int& y) { occupancyGrid_[x][y] = 0; }

private:
    std::vector<Actor*> actors_;
    GridType occupancyGrid_;    //0 = free, 1 = occupied

};

#endif /* MAP_HPP */