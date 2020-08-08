// a5.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Matthew Doyle>
// St.# : <3012223322>
// Email: <mwdoyle@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "board.h"
#include "computer_player.h"
#include "human_player.h"
#include "computer_player2.h"

using namespace std;

const int length = 10;
const int height = 10;

int main() {	
	bool start_Game = true;
	char begin = 0;
	
	cout << "\nWelcome to the wild world of Reversi !!!!!\n\n"
		 << "B = Black\n" << "W = White\n\n"
		 << "You are white, press enter to begin...";
	
	scanf("%c", &begin);
	system("clear");

	while(start_Game) {
		// create objects and display board
		Game B(length,height);
		Human_player player;
		Computer_player comp;
		Computer_player2 comp2;

		// print the board to the screen with starting position
		B.println();
	
		while(true) {
            // initialize scores
            int player_score = 0;
            int computer_score = 0;

            // evaluate if there are any legal moves to make for the player
            bool legalMovePlayer = legalMovesRemaining(B, Tile::white, Tile::black);
//            player.input(B);
            comp2.input(B);


            // if no moves are available
            if(!legalMovePlayer) {
                cout <<"No moves are available\n";
            }

            // evaluate if there are any legal moves to make for the computer
            bool legalMoveComp = legalMovesRemaining(B, Tile::black, Tile::white);
            comp.input(B);

            // if no moves are available
            if(!legalMoveComp) {
                cout << "No moves are available\n";
            }

            // count white and black tiles on game board
            for(int i = 0; i < B.height(); i++) {
                for(int j = 0; j < B.width(); j++) {
                    bool white = (B.board[i][j] == Tile::white);
                    bool black = (B.board[i][j] == Tile::black);

                    if(white) {
                        player_score++;
                    } else if(black) {
                        computer_score++;
                    }
                }
            }

            // when neither player can make a move its game over
            if(!legalMoveComp && !legalMovePlayer) {
                cout << "Game Over\n";
                cout << "Players score: " << player_score << endl;
                cout << "Computers score: " << computer_score << endl;
                cout << endl;

                if(player_score > computer_score) {
                    cout << "You win!\n";
                } else if(player_score < computer_score) {
                    cout << "The Computer won, were you even trying?\n";
                } else if(player_score == computer_score) {
                    cout << "Tie game\n";
                } break;
            }

            cout << "Players score: " << player_score << endl;
            cout << "Computers score: " << computer_score << "\n";
        }

        // play again?
        cout << "Play again? Enter y or n: ";
        string playAgain;
        cin >> playAgain;

        if(playAgain == "y") {
	        cout << endl;
        } else {
            start_Game = false;
        }
    }

    cout << "Game Over\n";
    return 0;
}