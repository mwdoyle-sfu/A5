//bestMove.h
#pragma once

vector<char> bestMove(Game& B, Tile playerTile, Tile computerTile)
{
    vector<vector<int>> legalMove(B.height(), vector<int>(B.width()));

    int bestMoveTop = 0;
    int bestMoveTopRight = 0;
    int bestMoveRight = 0;
    int bestMoveBottomRight = 0;
    int bestMoveBottom = 0;
    int bestMoveBottomLeft = 0;
    int bestMoveLeft = 0;
    int bestMoveTopLeft = 0;

    // find the blank tiles
    for(int i = 0; i < B.height(); i++) {
        for(int j = 0; j < B.width(); j++) {
            bool findBlank = (B.board[i][j] == Tile::blank);

            // find the computer peices
            if(findBlank) {
                
                bool checkLeft = (B.board[i][j-1] == computerTile);
                bool checkBottomLeft = (B.board[i+1][j-1] == computerTile);
                bool checkBottom = (B.board[i+1][j] == computerTile);
                bool checkBottomRight = (B.board[i+1][j+1] == computerTile);
                bool checkRight = (B.board[i][j+1] == computerTile);
                bool checkTopRight = (B.board[i-1][j+1] == computerTile);
                bool checkTop = (B.board[i-1][j] == computerTile);
                bool checkTopLeft = (B.board[i-1][j-1] == computerTile);
                
                // check top
                if(checkTop) {
                    // search the row for opponent peices
                    for(int k = 1; k < i; k++) {
                        bool check_All_Tiles_Row = (B.board[i-k][j] == computerTile);

                        // check for player tile and replace inbetween tiles
                        if(!check_All_Tiles_Row) {
                            if(B.board[i-k][j] == playerTile) {
                                for(k = 1; k < i; k++) {
                                    if(B.board[i-k][j] == playerTile) {
                                        break;
                                    }else {
                                        bestMoveTop++;
                                    }
                                }
                            }else {
                                break;
                            }

                            legalMove[i][j] += bestMoveTop;
                            break;
                        }else {
                            //if the spot is not legal do nothing
                        }
                    }
                    bestMoveTop = 0;
                }

                // check top right
                if(checkTopRight) {
                    // bool for checking diagonals
                    bool check_Tiles;

                    // find computer tiles
                    for(int k = 1; k < i; k++) {
                        bool checkWall = ((j + k == 8) && B.board[i-k][j+k] == computerTile);
                        if(checkWall) {
                            // spot is not legal
                            break;
                        }else {
                        	// set bool for checking diagonals
                            check_Tiles = (B.board[i-k][j+k] == computerTile);

                            // change any subsequent tiles
                            if(!check_Tiles) {
                                if(B.board[i-k][j+k] == playerTile) {
                                    // change opponent entries
                                    for(k = 1; k < i; k++) {
                                        //prevent any over replacement to prevent errors
                                        if(B.board[i-k][j+k] == playerTile) {
                                            break;
                                        }else {
                                            bestMoveTopRight++;
                                        }
                                    }
                                }else {
                                    break;
                                }
                                legalMove[i][j] += bestMoveTopRight;
                                break;
                            }
                        }
                    }
                    bestMoveTopRight = 0;
                }

                // check right (comments are similar to above)
                if(checkRight) {
                    for(int k = 1; k < B.width()-j; k++) {
                        bool check_All_Tiles_Row = (B.board[i][j+k] == computerTile);
                        if(!check_All_Tiles_Row) {
                            if(B.board[i][j+k] == playerTile) {
                                for(k = 1; k < B.width()-j; k++) {
                                    if(B.board[i][j+k] == playerTile) {
                                        break;
                                    }else {
                                        bestMoveRight++;
                                    }
                                }
                            }else {
                                break;
                            }

                            legalMove[i][j] += bestMoveRight;
                            break;
                        }
                    }
                    bestMoveRight = 0;
                }     
                
                // check bottom right (comments are similar to above)
                if(checkBottomRight) {
                    bool check_Tiles;

                    for(int k = 1; k < B.height()-i; k++) {
                        bool checkWall = ((j + k == 8) && B.board[i+k][j+k] == computerTile);
                        if(checkWall) {
                            //Invalid spot
                            break;
                        }
                        else {
                            check_Tiles = (B.board[i+k][j+k] == computerTile);

                            if(!check_Tiles) {
                                if(B.board[i+k][j+k] == playerTile) {
                                    for(k = 1; k < B.height()-i; k++) {
                                        if(B.board[i+k][j+k] == playerTile) {
                                            break;
                                        }else {
                                            bestMoveBottomRight++;
                                        }
                                    }
                                }else {
                                    break;
                                }

                                legalMove[i][j] += bestMoveBottomRight;
                                break;
                            }
                        }
                    }
                    bestMoveBottomRight = 0;
                }        
                
                // check bottom (comments are similar to above)
                if(checkBottom) {
                    for(int k = 1; k < B.height()-i; k++) {
                        bool check_All_Tiles_Row = (B.board[i+k][j] == computerTile);

                        if(!check_All_Tiles_Row) {
                            if(B.board[i+k][j] == playerTile) {
                                for(k = 1; k < B.height()-i; k++) {
                                    if(!check_All_Tiles_Row && B.board[i+k][j] == playerTile) {
                                        break;
                                    }else {
                                        bestMoveBottom++;
                                    }
                                }
                            }else {
                                break;
                            }

                            legalMove[i][j] += bestMoveBottom;
                            break;
                        }
                    }
                    bestMoveBottom = 0;
                }                                   

				// check bottom left (comments are similar to above)
                if(checkBottomLeft) {
                    bool check_Tiles;

                    for(int k = 1; k < B.height()-i; k++) {
                        bool checkWall = ((j - k == 1) && B.board[i+k][j-k] == computerTile);
                        if(checkWall) {
                            //Invalid Spot
                            break;
                        }else {
                            check_Tiles = (B.board[i+k][j-k] == computerTile);

                            if(!check_Tiles) {
                                if(B.board[i+k][j-k] == playerTile) {
                                    for(k = 1; k < B.height()-i; k++) {
                                        if(!check_Tiles && B.board[i+k][j-k] == playerTile) {
                                            break;
                                        }else {
                                            bestMoveBottomLeft++;
                                        }
                                    }
                                }else {
                                    break;
                                }

                                legalMove[i][j] += bestMoveBottomLeft;
                                break;
                            }
                        }
                    }
                    bestMoveBottomLeft = 0;
                }
				
				// check left (comments are similar to above)
                if(checkLeft) {
                    for(int k = 1; k < j; k++) {
                        bool check_All_Tiles_Row = (B.board[i][j-k] == computerTile);

                        if(!check_All_Tiles_Row) {
                            if(B.board[i][j - k] == playerTile) {
                                for(k = 1; k < j; k++) {
                                    if(B.board[i][j-k] == playerTile) {
                                        break;
                                    }else {
                                        bestMoveLeft++;
                                    }
                                }
                            }else {
                                break;
                            }

                            legalMove[i][j] += bestMoveLeft;
                            break;
                        }
                    }
                    bestMoveLeft = 0;
                }
				
				// check top left (comments are similar to above)
                if(checkTopLeft) {
                    bool check_Tiles;

                    for(int k = 1; k < i; k++) {
                        bool checkWall = ((j - k == 1) && B.board[i-k][j-k] == computerTile);
                        if(checkWall) {
                            //Invalid Spot
                            break;
                        }else {
                            check_Tiles = (B.board[i-k][j-k] == computerTile);

                            if(!check_Tiles) {
                                if(B.board[i-k][j-k] == playerTile) {
                                    for(k = 1; k < i; k++) {
                                        if(B.board[i-k][j-k] == playerTile) {
                                            break;
                                        }else {
                                            bestMoveTopLeft++;
                                        }
                                    }
                                }else {
                                    break;
                                }

                                legalMove[i][j] += bestMoveTopLeft;
                                break;
                            }
                        }
                    }
                    bestMoveTopLeft = 0;
                }
            }
        }
    }

    // find the best option
    int tmp = 0;
    int best = legalMove[0][0];
    int height_At_i = 0;
    int width_At_j = 0;

    // corner options
    int bestHeight = 0;
    int bestWidth = 0;

    // find move with highest turn rate
    for(int i = 0; i < B.height(); i++) {
        for(int j = 0; j < B.width(); j++) {
            tmp = legalMove[i][j];

            if(tmp >= best) {
                best = tmp;
                height_At_i = i;
                width_At_j = j;

                // bool corners available
                bool checkTopLeft = (B.board[1][1] == Tile::blank && legalMove[1][1] > 0);
                bool checkBottomLeft = (B.board[8][1] == Tile::blank && legalMove[8][1] > 0);
                bool checkTopRight = (B.board[1][8] == Tile::blank && legalMove[1][8] > 0);
                bool checkBottomRight = (B.board[8][8] == Tile::blank && legalMove[8][8] > 0);

                // if corner is available make best choice
                if(checkTopLeft) {
                    bestHeight = 1;
                    bestWidth = 1;
                }

                if(checkBottomLeft) {
                    bestHeight = 8;
                    bestWidth = 1;
                }

                if(checkTopRight) {
                    bestHeight = 1;
                    bestWidth = 8;
                }

                if(checkBottomRight) {
                    bestHeight = 8;
                    bestWidth = 8;
                }

            }
        }
    }

    //Create a vector compMove to store the location of the computers move in order to display it
    vector<char> compMove;

    //If the preferred height and width are possible, make that move instead
    if(bestHeight > 0 && bestWidth > 0) {
        char height = bestHeight + 96;
        char width = bestWidth + 48;

        //Push back the location to the vector
        compMove.push_back(height);
        compMove.push_back(width);

        //Make the move
        possibleChoices(B, bestHeight, bestWidth, playerTile, computerTile);
        legalMove.clear();
    }
    //Otherwise, make the move that gets the most turnovers
    else
    {
        char height = height_At_i + 96;
        char width = width_At_j + 48;

        //Push back the most profitable option to the vector
        compMove.push_back(height);
        compMove.push_back(width);

        //Make the move
        possibleChoices(B, height_At_i, width_At_j, playerTile, computerTile);
        legalMove.clear();
    }

    //Return the vector for displaying it to the user what the computer had done
    return compMove;
}