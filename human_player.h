//human_player.h

#include <iostream>
#include <vector>

using namespace std;
using namespace a5;

class Human_player : public a5 :: Player {
public:
	string player_input;
	int checkRow;
	int checkCol;

	const Tile playerTile = Tile::white;
	const Tile computerTile = Tile::black;

    void input(Game& B) {
        bool move = legalMovesRemaining(B, playerTile, computerTile);

        //check that move is legal and read input from cin
        if(move) {
            cout << "Enter row and column (NO SPACES): ";
            cin >> player_input;
            cout << endl;
            bool checkInput = true;

            //Check for invalid input
            if(player_input.size() != 2) {
            	checkInput = false;
            } else {
                char convertRow = player_input[0]; //convert to interger
                char convertCol = player_input[1];

                checkRow = convertRow - 96;
                checkCol = convertCol - 48;
            }

            // boundry checking
            if(checkInput) {
                if(checkRow >= 1 && checkRow <= 8) {
                    if(checkCol >= 1 && checkCol <= 8) {
                        
                        // check if player choice is available
                        bool checkloc = possibleChoices(B, checkRow, checkCol, playerTile, computerTile);

                        // print board
                        if(checkloc) {
                            B.println();
                        } else {
                            checkInput = false;
                        }
                    } else {
	                    checkInput = false; //column check
                    }
                } else {
                    checkInput = false; //row check
                }
            }

            // if entry is invalid ask for input again
            while(!checkInput) {
                checkInput = true;
                cout << "Player input invalid (NO SPACES)\n"
                     << "Try Again: ";
                cin >> player_input;
                cout << endl;

	            // boundry checking agian
	            if(checkInput) {
	                if(checkRow >= 1 && checkRow <= 8) {
	                    if(checkCol >= 1 && checkCol <= 8) {
	                        
	                        // check if player choice is available
	                        bool checkloc = possibleChoices(B, checkRow, checkCol, playerTile, computerTile);

	                        // print board
	                        if(checkloc) {
	                            B.println();
	                        } else {
	                            checkInput = false;
	                        }
	                    } else {
		                    checkInput = false; //column check
	                    }
	                } else {
	                    checkInput = false; //row check
	                }
	            }
            }

        }
        // if no moves are available
        else {
            return;
        }
    }

	~Human_player() { } //destructor

};// Human_Player class