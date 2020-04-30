////////////////////////////////////////////////////////////////////////////////
// Main File: BattleShip.cpp
// This File: Point.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   CS368-Exceptions Slides
//                   http://www.cplusplus.com/reference/stdexcept/out_of_range/
//
////////////////////////////////////////////////////////////////////////////////

/**
 * This class will act as the main data
 * structure for the BattleShip program.
 * Keep track of a points x,y coordinates
 * as well as the status of the point.
*/
#ifndef POINT_H
#define POINT_H

#include <iostream>

// forward declaration of Ship and Board classes
template<unsigned xDim, unsigned yDim> class Ship;
template<unsigned xDim, unsigned yDim> class Board;

/**
 * Each point will have a status member
 * to keep track of it's current status
 * EMPTY - point has not been targeted or 
 *         ship has not been places
 * SHIP - point has part of ship placed
 * MISS - point was targeted and there was no ship
 * HIT - point was targeted and there was a ship
*/
enum Status {
    EMPTY,
    SHIP,
    MISS,
    HIT
};

template<unsigned xDim = 10, unsigned yDim = 10>
class Point {

    /**
     * overloaded << operator to print out coordinates of Point
    */
    friend std::ostream& operator<<(std::ostream &os, const Point<xDim,yDim> &point) {
        os << "(" << (point.y+1) << "," << point.xToChar(point.x) << ")";
        return os;
    }

    /**
     * overloaded == operator to determine if two Points are equal
    */
    friend bool operator==(const Point<xDim,yDim> &lhs, const Point<xDim,yDim> &rhs) {
        if(lhs.x == rhs.x && lhs.y == rhs.y) {
            return true;
        }
        return false;
    }

    // Ship is friend so it can utilize members
    friend class Ship<xDim, yDim>;

    // Board is friend so it can utilize members
    friend class Board<xDim, yDim>;

    private:

        // keep track of x coordinate converted to (A-...)
        unsigned x;

        // keep track of y coordinate 
        unsigned y;

        // store status of Point (EMPTY,SHIP,MISS,HIT)
        Status status;

    public:

        Point() = default;

        /**
         * Constructor for Point that takes in char alpha
         * and unsigned y arguments
        */
        Point(char alpha, unsigned y);

        /**
         * Constructor for Point that takes in unsigned x
         * and unsigned y arguments
        */
        Point(unsigned x, unsigned y);


        /**
         * Convert unsigned x to a char
        */
        static char xToChar(unsigned x);

        /**
         * Convert to char to unsigned value
        */
        static unsigned xToInt(char alpha);

        /**
         * Get status of Point
        */
        Status getStatus() const;

};

template<unsigned xDim, unsigned yDim>
Point<xDim,yDim>::Point(char alpha, unsigned y) {
    unsigned xVal = xToInt(alpha);
    if(xVal < 0 || xVal > 9) {
        throw std::out_of_range("out of range!");
    }
    this->x = xVal;
    if(y < 0 || y > 9) {
        throw std::out_of_range("out of range!");
    }
    this->y = y;
    this->status = EMPTY;
}

template<unsigned xDim, unsigned yDim>
Point<xDim,yDim>::Point(unsigned x, unsigned y) {
    if(x < 0 || x > 9) {
        throw std::out_of_range("out of range!");
    }
    this->x = x;
    if(y < 0 || y > 9) {
        throw std::out_of_range("out of range!");
    }
    this->y = y;
    this->status = EMPTY;
}


template<unsigned xDim, unsigned yDim>
char Point<xDim,yDim>::xToChar(unsigned x) {
    char val = static_cast<char>(x + 'A');
    return val;
}

template<unsigned xDim, unsigned yDim>
unsigned Point<xDim,yDim>::xToInt(char alpha) {
    unsigned val = static_cast<unsigned>(alpha-'A');
    return val; 
}

template<unsigned xDim, unsigned yDim>
Status Point<xDim,yDim>::getStatus() const {
    return this->status;
}

#endif