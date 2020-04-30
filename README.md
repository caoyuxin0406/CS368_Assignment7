# Author: Ethan Lengfeld , elengfeld@wisc.edu , 9074020836

Assignment 7 for CS 368: Learn a Programming Language C++

# Assignment 7: Battleship

## To Compile and Run Program
1. To run the program add all files to the any same directory.
2. Navigate to the directory location and type the command 'make'
3. This will create an executable called 'Battleship'
4. Type 'Battleship' in command line and the program will execute.

## To Clean Program
To remove executable and any .o files run the command 'make clean' 
Warning! This will delete the executable and will require rerunning 'make' to retest it

## Code Organization
Battleship.cpp defines the main functionality for
playing Battlship game.
Point.h will define points on the Battleship game 
board. Point.h is primary data structure for the 
Ship.h and Board.h files.
Ship.h will hold coordinates stored as Point
which will be used to determine wether a Ship 
has been Hit, Sunk, or wether it missed.
Board.h will keep track of Ships on the board
and update the board based on whether shots
hit a ship or miss a ship.