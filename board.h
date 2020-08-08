//board.h
#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

enum class Tile : char
{
	wall='M', black='B', white='W', blank='.'
};

class Game {
public:
	// A board is a 2-dimensional vector of Tiles.
    vector<vector<Tile>> board;

    Game(int w, int h) // constructor
    : board(h) 
    {
        assert(w > 1 && h > 1);

        // set all tiles to be dirt
        for(int i = 0; i < board.size(); ++i) {
            board[i] = vector<Tile>(w, Tile::blank);
        }

        // add a ring of walls around the entire board
        for(int i = 0; i < w; ++i) board[0][i] = Tile::wall;   // top
        for(int i = 0; i < w; ++i) board[h - 1][i] = Tile::wall; // bottom
        for(int i = 0; i < h; ++i) board[i][0] = Tile::wall;   // left
        for(int i = 0; i < h; ++i) board[i][w - 1] = Tile::wall; // right
             
        // add staring positions
        board[4][4] = Tile::white;
        board[4][5] = Tile::black;
        board[5][4] = Tile::black;
        board[5][5] = Tile::white;
    }

    // get the width and height of the board
    int width() const { return board[0].size(); }
    int height() const { return board.size(); }

    // set the location at row r, column c to be t
    void set(int r, int c, const Tile &t) {
        board[r][c] = t;
    }


    // print the board to the screen
    void print() const {
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                cout << char(board[i][j]) << " ";
            }
        
	        if(i == 0 || i == 9) {
	        	cout << " ";
	        } else {
	        char letters = 96 + i;
	        cout << letters;
	        }
	        
	        cout << "\n";
        }
    }

    void println() const {
        // prints the numbers 0-8 at the top
        for(int i = 0; i < width()-1; i++) {
            
            if(i == 0) {
                cout << "  ";
            } else {
                cout << i << " ";
            }
        }

        cout << "\n";
        print();
        cout << "\n";
    }
};