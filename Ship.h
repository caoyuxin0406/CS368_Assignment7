////////////////////////////////////////////////////////////////////////////////
// Main File: BattleShip.cpp
// This File: Ship.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile
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

/**
 * Hold all data related to the Ship 
 * that is placed the Battleship board
*/
#ifndef SHIP_H
#define SHIP_H

#include "Point.h"
#include <vector>

/**
 * Enum to determine which 
*/
enum Direction {
    VERTICAL,
    HORIZONTAL
};

template<unsigned xDim = 10, unsigned yDim = 10>
class Ship {

    private:

        // store the name of the ship
        std::string name;

        // store the Points that make up the Ship
        std::vector<Point<xDim, yDim>*> ship;

    public:

        /**
         * Constuctor to set name of ship and the Points 
         * already established in a Ship vector
        */
        Ship(std::string name, const std::vector<Point<xDim, yDim>*> shipCoords);

        /**
         * Constructor to set name of ship as well as place new ship
         * on the board. It will test each Point of the new ship. Points
         * are placed based on parament len(length) and Direction
        */
        Ship(std::string name, const Point<xDim, yDim> &coord, unsigned len, Direction direction, Board<xDim, yDim> &board);

        /**
         * Set the name of the Ship
        */
        void setName(std::string name);

        /**
         * Return name of the Ship
        */
        std::string getName();

        /**
         * Determine if point on ship has been hit.
        */
        bool isHit(const Point<xDim, yDim> &target) const;

        /**
         * Determine if Ship has been sunk. That is
         * all Points in ship have status of HIT
        */
        bool isSunk() const;

};

template<unsigned xDim, unsigned yDim>
Ship<xDim,yDim>::Ship(std::string name, const std::vector<Point<xDim,yDim>*> shipCoords) :
    name(name),
    ship(shipCoords)
{}

template<unsigned xDim, unsigned yDim>
Ship<xDim,yDim>::Ship(std::string name, const Point<xDim, yDim> &coord, unsigned len, Direction direction, Board<xDim, yDim> &board) {

    this->name = name;

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