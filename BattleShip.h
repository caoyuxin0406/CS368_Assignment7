////////////////////////////////////////////////////////////////////////////////
// Main File: BattleShip.cpp
// This File: BattleShip.h
// Other Files: 	 Board.h / Ship.h / Point.h / BattleShip.cpp / BattleShip.h / README.md / Makefile
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld (Comments Only)
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

/**
 * Header file for running Battleship game.
*/
#ifndef BATTLESHIP_MAIN_H
#define BATTLESHIP_MAIN_H

#include <random>
#include <vector>
#include "Point.h"
#include "Ship.h"
#include "Board.h"

constexpr unsigned MAX_X{10};
constexpr unsigned MAX_Y{10};

std::vector<Ship<MAX_X,MAX_Y>> player;
std::vector<Ship<MAX_X,MAX_Y>> computer;
Board<MAX_X,MAX_Y> pBoard(false);
Board<MAX_X,MAX_Y> cBoard(true);

struct DefShip {
  unsigned len;
  std::string name;
};
  
std::vector<DefShip> ships {{2, "destroyer"},
                            {3, "cruiser"},
                            {3, "submarine"},
                            {4, "battleship"},
                            {5, "carrier"}};

void initGame();
void placeShips(std::default_random_engine &rand);
void playGame(std::default_random_engine &rand);
bool checkLost(std::vector<Ship<MAX_X,MAX_Y>> &ships);
void doShot(Point<MAX_X,MAX_Y> &shot, std::vector<Ship<MAX_X,MAX_Y>> &ships, Board<MAX_X,MAX_Y> &board);
void printBoards();

#endif
