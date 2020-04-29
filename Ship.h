////////////////////////////////////////////////////////////////////////////////
// Main File: Battleship.cpp
// This File: Ship.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile.
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   CS368-Exceptions Slides
//                   https://github.com/Haivision/srt/issues/568
//
////////////////////////////////////////////////////////////////////////////////

#ifndef SHIP_H
#define SHIP_H

#include "Point.h"
#include <vector>

enum Direction {
    VERTICAL,
    HORIZONTAL
};

template<unsigned xDim = 10, unsigned yDim = 10>
class Ship {

    private:

        std::string name;

        std::vector<Point<xDim, yDim>*> ship;

    public:

        Ship(std::string name, const std::vector<Point<xDim, yDim>*> shipCoords);

        Ship(std::string name, const Point<xDim, yDim> &coord, unsigned len, Direction direction, Board<xDim, yDim> &board);

        void setName(std::string name);

        std::string getName();

        bool isHit(const Point<xDim, yDim> &target) const;

        bool isSunk() const;

};

template<unsigned xDim, unsigned yDim>
Ship<xDim,yDim>::Ship(std::string name, const std::vector<Point<xDim,yDim>*> shipCoords) :
name(name),
ship(shipCoords)
{}

// TODO
template<unsigned xDim, unsigned yDim>
Ship<xDim,yDim>::Ship(std::string name, const Point<xDim, yDim> &coord, unsigned len, Direction direction, Board<xDim, yDim> &board) {
    this->name = name;

// std::cout << "coord.x = " << coord.x <<  "       xDim = " << xDim << std::endl;
// std::cout << "coord.y = " << coord.y <<  "       yDim = " << yDim << std::endl;

    std::vector<Point<xDim, yDim>*> newShip;
    try {
        for(unsigned point = 0; point < len; point++) {
            Point<xDim,yDim> *newPoint;
            if(direction == VERTICAL) {
                newPoint = board.getShipPoint(coord, 0, point);
            } else {
                newPoint = board.getShipPoint(coord, point, 0);
            }
            newShip.push_back(newPoint);
        }
    } catch (std::invalid_argument &error) {
        // std::cout << "here" << std::endl;
        for(Point<xDim,yDim> *currPoint : newShip) {
            currPoint->status = EMPTY;
        }
         throw std::invalid_argument("Unable to place ship");
    }
    this->ship = newShip;
}

template<unsigned xDim, unsigned yDim>
void Ship<xDim,yDim>::setName(std::string newName) {
    this->name = newName;
}

template<unsigned xDim, unsigned yDim>
std::string Ship<xDim,yDim>::getName() {
    return this->name;
}

template<unsigned xDim, unsigned yDim>
bool Ship<xDim,yDim>::isHit(const Point<xDim,yDim> &target) const {
    for(Point<xDim,yDim>* currPoint : this->ship) {
        if(currPoint->x == target.x && currPoint->y == target.y) {
            currPoint->status = HIT;
            return true;
        }
    }
    return false;
}

template<unsigned xDim, unsigned yDim>
bool Ship<xDim,yDim>::isSunk() const {
    for(Point<xDim,yDim>* currPoint : this->ship) {
        if(currPoint->status != HIT ) {
            return false;
        }
    }
    return true;
}

#endif