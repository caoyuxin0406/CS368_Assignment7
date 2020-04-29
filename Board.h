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
// Online sources:   https://en.cppreference.com/w/cpp/language/explicit
//
////////////////////////////////////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

template<unsigned xDim = 10, unsigned yDim = 10>
class Board {

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

        Point<xDim, yDim> board[xDim][yDim];

        bool hideShips;

    public:

        explicit Board(bool hide=true) {
            this->hideShips = hide;
            for(unsigned x = 0; x < xDim; x++) {
                for(unsigned y = 0; y < yDim; y++) {
                    this->board[x][y] = Point<xDim,yDim>(y,x);
                }
            }
        }

        void setStatus(const Point <xDim,yDim> point, Status status);

        Point<xDim, yDim>* getShipPoint(const Point<xDim, yDim> &point, unsigned X, unsigned Y);
};


template<unsigned xDim, unsigned yDim>
void Board<xDim,yDim>::setStatus(const Point <xDim,yDim> point, Status status) {
    this->board[point.y][point.x].status = status;
}

template<unsigned xDim, unsigned yDim>
Point<xDim, yDim>* Board<xDim,yDim>::getShipPoint(const Point<xDim, yDim> &point, unsigned X, unsigned Y) {

// std::cout << "point.x = " << point.x << " and X = "<< X << "       xDim = " << xDim << std::endl;
// std::cout << "point.y = " << point.y << " and Y = "<< Y << "       yDim = " << yDim << std::endl;
    if(point.x+X > xDim || point.y > yDim) {
        // std::cout << "outside range" << std::endl;
        throw std::invalid_argument("Point outside range");
    }

    Point<xDim,yDim> *pointToCheck = &this->board[point.y+Y][point.x+X];

    if(pointToCheck->getStatus() == SHIP) {
        // std::cout << "it's a ship" << std::endl;
        throw std::invalid_argument("Point already occupied");
    }

    this->setStatus(*pointToCheck, SHIP);

    return pointToCheck;
}

#endif