//
// Created by Matthew Doyle on 2020-08-03.
//
#pragma once

#ifndef A5_COMPUTER_PLAYER2_H
#define A5_COMPUTER_PLAYER2_H

#include <iostream>
#include "abstract_player.h"
#include "choices.h"
#include "legalMove.h"
#include "bestMove.h"
#include "board.h"

using namespace std;
using namespace a5;

class Computer_player2 : public a5 :: Player {
public:
    const Tile computerTile = Tile::black;
    const Tile playerTile = Tile::white;

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

    ~Computer_player2() { } //destructor

};// Computer_player class

#endif //A5_COMPUTER_PLAYER2_H
