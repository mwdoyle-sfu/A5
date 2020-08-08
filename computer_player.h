//computer_player.h
#pragma once

#include <iostream>
#include "abstract_player.h"
#include "choices.h"
#include "legalMove.h"
#include "bestMove.h"

using namespace std;
using namespace a5;

class Computer_player : public a5 :: Player {
public:
    const Tile playerTile = Tile::black;
    const Tile computerTile = Tile::white;

    // computer input
    void input(Game& B) {
        // determine legal moves
        bool move = legalMovesRemaining(B, playerTile, computerTile);

        // make computer player move
        if(move) {
            // determine best move
            vector<char> compMove = bestMove(B, playerTile, computerTile);
            cout << "Computer player chooses: ";

            for(int i = 0; i < compMove.size(); i++) {
                cout << compMove[i];
            }

            cout << endl << endl;
            B.println();
        }else {
            return;
        }
    }

	~Computer_player() { } //destructor

};// Computer_player class