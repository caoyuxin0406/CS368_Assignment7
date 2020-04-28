////////////////////////////////////////////////////////////////////////////////
// Main File: Battleship.cpp
// This File: Point.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile.
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

#ifndef POINT_H
#define POINT_H

#include <iostream>

template<unsigned xDim, unsigned yDim> class Ship;
template<unsigned xDim, unsigned yDim> class Board;

enum Status {
    EMPTY,
    SHIP,
    MISS,
    HIT
};

template<unsigned xDim = 10, unsigned yDim = 10>
class Point {
    
    friend std::ostream& operator<<(std::ostream &os, const Point<xDim,yDim> &point) {
        os << "(" << (point.y+1) << "," << point.xToChar(point.x) << ")";
        return os;
    }

    friend bool operator==(const Point<xDim,yDim> &lhs, const Point<xDim,yDim> &rhs) {
        if(lhs.x == rhs.x && lhs.y == rhs.y) {
            return true;
        }
        return false;
    }


    friend class Ship<xDim, yDim>;

    friend class Board<xDim, yDim>;

    private:

        unsigned x;

        unsigned y;

        Status status;

    public:

        Point() = default;

        Point(char alpha, unsigned y);

        Point(unsigned x, unsigned y);


        static char xToChar(unsigned x);

        static unsigned xToInt(char alpha);

        Status getStatus() const;

};

template<unsigned xDim, unsigned yDim>
Point<xDim,yDim>::Point(char alpha, unsigned y) {
    unsigned xVal = xToInt(alpha);
    if(xVal < 0 || xVal > 9) {
        throw std::out_of_range("out of range!");
    }
    if(y < 0 || y > 9) {
        throw std::out_of_range("out of range!");
    }
    this->status = EMPTY;
}

template<unsigned xDim, unsigned yDim>
Point<xDim,yDim>::Point(unsigned x, unsigned y) {
    if(x < 0 || x > 9) {
        throw std::out_of_range("out of range!");
    }
    if(y < 0 || y > 9) {
        throw std::out_of_range("out of range!");
    }
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