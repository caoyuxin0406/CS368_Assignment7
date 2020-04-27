# Ethan Lengfeld
# 9074020836
# Makefile to compile Assignment 7 - Battleship code

CXX=g++
CXXFLAGS = -Wall
EXE = Battleship

# all: battleship.o
# 	$(CXX) $(CXXFLAGS) -o $(EXE) battleship.o

# demo.o: demo.cpp Graph.h UnionFind.h SetUF.h
# 	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-del battleship.o
	-del Battleship.exe