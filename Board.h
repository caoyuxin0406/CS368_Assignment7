////////////////////////////////////////////////////////////////////////////////
// Main File: Battleship.cpp
// This File: Board.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile.
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

#ifndef BOARD
#define BOARD

#include "Point.h"

template<unsigned xDim = 10, unsigned yDim = 10>
class Board {

    friend std::ostream& operator<<(std::ostream &os, const Board<xDim,yDim> &Board) {
        os << "BOARD TODO!";
        return os;
    }

    private:

        Point<xDim, yDim> board[xDim][yDim];

        bool hideShips;

    public:

        explicit Board(bool hide);

        void setStatus(const Point <xDim, yDim>, Status);

        Point<xDim, yDim>* getShipPoint(const Point<xDim, yDim> &p, unsigned X, unsigned Y);
};

#endif