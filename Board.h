////////////////////////////////////////////////////////////////////////////////
// Main File: Battleship.cpp
// This File: Board.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   https://en.cppreference.com/w/cpp/language/explicit
//
////////////////////////////////////////////////////////////////////////////////

/**
 * Store all data relevant to the Battleship
 * board. Board uses Point data structure for
 * each point on Battleship Board.
*/
#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

template<unsigned xDim = 10, unsigned yDim = 10>
class Board {

    /**
     * Overloaded << operator to print the Battleship board
    */
    friend std::ostream& operator<<(std::ostream &os, const Board<xDim,yDim> &board) {
        int xLen = static_cast<int>(xDim);
        int yLen = static_cast<int>(yDim);
        os << "   ";
        for (int cols = 0; cols < xLen; cols++) {
            os << Point<xDim,yDim>::xToChar(cols);
        }
        os << std::endl;
        for (int row = 0; row < yLen; row++) {
            
            if ((row+1) > 99) {
                os << row+1;
            }
            else if ((row+1) > 9) {
                os << " " << row+1;
            }
            else {
                os << "  " << row+1;
            }

            for (int b_col = 0; b_col < xLen; b_col++) {
                if (board.board[row][b_col].getStatus() == HIT) {
                    os << "*";
                } 
                else if(board.board[row][b_col].getStatus() == MISS) {
                    os << "x";
                }
                else if(board.board[row][b_col].getStatus() == SHIP && !(board.hideShips)) {
                    os << "=";
                } 
                else {
                    os << "~";
                }
            }
            os << std::endl;
        }
        return os;
    }

    private:

        // store all Points that make up the battleship board
        Point<xDim, yDim> board[xDim][yDim];

        // boolean to determine whether ships should be hidden on board
        bool hideShips;

    public:

        /**
         * Explicit constructor to create board of Points
        */
        explicit Board(bool hide=true) {
            this->hideShips = hide;
            for(unsigned x = 0; x < xDim; x++) {
                for(unsigned y = 0; y < yDim; y++) {
                    this->board[x][y] = Point<xDim,yDim>(y,x);
                }
            }
        }

        /**
         * Set the status of the Point
        */
        void setStatus(const Point <xDim,yDim> point, Status status);

        /**
         * Determine if Point from offset is valid for new Ship placement
        */
        Point<xDim, yDim>* getShipPoint(const Point<xDim, yDim> &point, unsigned X, unsigned Y);
};


template<unsigned xDim, unsigned yDim>
void Board<xDim,yDim>::setStatus(const Point <xDim,yDim> point, Status status) {
    this->board[point.y][point.x].status = status;
}

template<unsigned xDim, unsigned yDim>
Point<xDim, yDim>* Board<xDim,yDim>::getShipPoint(const Point<xDim, yDim> &point, unsigned X, unsigned Y) {

    if(point.x+X > xDim || point.y > yDim) {
        throw std::invalid_argument("Point outside range");
    }

    Point<xDim,yDim> *pointToCheck = &this->board[point.y+Y][point.x+X];

    if(pointToCheck->getStatus() == SHIP) {
        throw std::invalid_argument("Point already occupied");
    }

    this->setStatus(*pointToCheck, SHIP);

    return pointToCheck;
}

#endif