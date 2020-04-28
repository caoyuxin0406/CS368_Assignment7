# Ethan Lengfeld
# 9074020836
# Makefile to compile Assignment 7 - Battleship code

CXX=g++
CXXFLAGS = -Wall
EXE = Battleship

all: battleship.o
	$(CXX) $(CXXFLAGS) -o $(EXE) battleship.o

battleship.o: BattleShip.cpp BattleShip.h Point.h Ship.h Board.h
	$(CXX) $(CXXFLAGS) -c BattleShip.cpp

clean:
	-del battleship.o
	-del Battleship.exe