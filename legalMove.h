//legalMove.h
#pragma once

bool legalMovesRemaining(Game& B, Tile playerTile, Tile computerTile)
{
	bool top = false;
	bool topRight = false;
	bool right = false;
	bool bottomRight = false;
	bool bottom = false;
	bool bottomLeft = false;
	bool left = false;
    bool topLeft = false;
    
    vector<vector<bool>> legalMoveVector(B.height(), vector<bool>(B.width()));

    for(int i = 0; i < B.height(); i++) {
        for(int j = 0; j < B.width(); j++) {
            bool blank = (B.board[i][j] == Tile::blank);

            //Find game peice
            if(blank) {
                bool checkLeft = (B.board[i][j-1] == computerTile);
                bool checkBottomLeft = (B.board[i+1][j-1] == computerTile);
                bool checkBottom = (B.board[i+1][j] == computerTile);
                bool checkBottomRight = (B.board[i+1][j+1] == computerTile);
                bool checkRight = (B.board[i][j+1] == computerTile);
                bool checkTopRight = (B.board[i-1][j+1] == computerTile);
                bool checkTop = (B.board[i-1][j] == computerTile);
                bool checkTopLeft = (B.board[i-1][j-1] == computerTile);

                if(checkTop) {
                    for(int k = 1; k < i; k++) {
                        // checking for computer tile
                        bool check_All_Tiles_Row = (B.board[i - k][j] == computerTile);
                        bool check_playerTile = (B.board[i - k][j] == playerTile);

                        if(check_All_Tiles_Row) {
                            top = false;
                        }else {
                            if(check_playerTile) {
                                top = true;
                                break;
                            }else {
                                top = false;
                                break;
                            }
                        }
                    }
                }

                if(checkTopRight) {
                    // look computer tiles in height
                    for(int k = 1; k < i; k++) {
                        if(((j + k) == 8) && B.board[i - k][j + k] == computerTile) {
                            topRight = false;
                            break;
                        }else {
                            // checking for computer tile
                            bool check_Tiles = (B.board[i - k][j + k] == computerTile);
                            bool check_playerTile = (B.board[i - k][j + k] == playerTile);

                            if(check_Tiles) {
                                topRight = false;
                            }
                            else {
                                if(check_playerTile) {
                                    topRight = true;
                                    break;
                                }else {
                                    topRight = false;
                                    break;
                                }
                            }
                        }
                    }
                }

                if(checkRight) {
                    for(int k = 1; k < B.width()-j; k++) {
                        bool check_All_Tiles_Row = (B.board[i][j+k] == computerTile);
                        bool check_playerTile = (B.board[i][j+k] == playerTile);

                        if(check_All_Tiles_Row) {
                            right = false;
                        }else {
                            if(check_playerTile) {
                                right = true;
                                break;
                            }else {
                                right = false;
                                break;
                            }
                        }
                    }
                }

                if(checkBottomRight) {
                    // look computer tiles in height
                    for (int k = 1; k < B.height() - i; k++) {
                        if(((j + k) == 8) && B.board[i + k][j + k] == computerTile) {
                            bottomRight = false;
                            break;
                        }else {
                            // checking for computer tile
                            bool check_Tiles = (B.board[i + k][j + k] == computerTile);
                            bool check_playerTile = (B.board[i + k][j + k] == playerTile);

                            if(check_Tiles) {
                                bottomRight = false;
                            }else {
                                if(check_playerTile) {
                                    bottomRight = true;
                                    break;
                                }else {
                                    bottomRight = false;
                                    break;
                                }
                            }
                        }
                    }
                }

                if(checkBottom) {
                    for(int k = 1; k < B.height()-i; k++) {
                        //Check for computer tile
                        bool check_All_Tiles_Row = (B.board[i+k][j] == computerTile);
                        bool check_playerTile = (B.board[i+k][j] == playerTile);

                        // if not replace tiles in between
                        if(check_All_Tiles_Row) {
                            bottom = false;
                        }else {
                            if(check_playerTile) {
                                bottom = true;
                                break;
                            }else {
                                bottom = false;
                                break;
                            }
                        }
                    }
                }

                if(checkBottomLeft) {
                    for(int k = 1; k < B.height()-i; k++) {
                        //Check walls
                        if(((j - k) == 1) && B.board[i+k][j-k] == computerTile) {
                            bottomLeft = false;
                            break;
                        }else {
                            bool check_Tiles = (B.board[i+k][j-k] == computerTile);
                            bool check_playerTile = (B.board[i+k][j-k] == playerTile);

                            if(check_Tiles) {
                                bottomLeft = false;
                            }else {
                                if(check_playerTile) {
                                    bottomLeft = true;
                                    break;
                                }else {
                                    bottomLeft = false;
                                    break;
                                }
                            }
                        }
                    }
                }

                if(checkLeft) {
                    //check columns
                    for(int k = 1; k < j; k++) {
                        //Check every column to see if the tile at that spot is an opponent
                        bool check_All_Tiles_Row = (B.board[i][j-k] == computerTile);
                        bool check_playerTile = (B.board[i][j-k] == playerTile);

                        if(check_All_Tiles_Row) {
                            left = false;
                        }else {
                            if(check_playerTile) {
                                left = true;
                                break;
                            }else {
                                left = false;
                                break;
                            }
                        }
                    }
                }

                if(checkTopLeft) {
                    // check row for computer tiles
                    for(int k = 1; k < i; k++) {
                         if(((j - k) == 1) && B.board[i - k][j - k] == computerTile) {
                            topLeft = false;
                            break;
                        }else {
                            // find computer tiles
                            bool check_Tiles = (B.board[i - k][j - k] == computerTile);
                            bool check_playerTile = (B.board[i - k][j - k] == playerTile);

                            if(check_Tiles) {
                                topLeft = false;
                            }else {
                                if(check_playerTile) {
                                    topLeft = true;
                                    break;
                                }else {
                                    topLeft = false;
                                    break;
                                }
                            }
                        }
                    }
                }

                if(!checkBottom && !checkBottomLeft && !checkBottomRight && !checkLeft && !checkRight && !checkTop
                   && !checkTopLeft && !checkTopRight) {
                    legalMoveVector[i][j] = false;
                }else if(!topLeft && !top && !left && !bottom && !bottomLeft && !bottomRight 	// no moves available
                        && !right && !topRight) {
                    legalMoveVector[i][j] = false;
                }else { 																		// move available
                    legalMoveVector[i][j] = true;
                }
            }
        }
    }

    // check for legalMove move
    bool legalMove = false;

    for(int i = 0; i < B.height(); i++) {
        for(int j = 0; j < B.width(); j++) {
            if(legalMoveVector[i][j] == true) {		// legal move available
                legalMove = true;
                return legalMove;
            }

            bool check_i = (i == B.height() - 1);
            bool check_j = (j == B.height() - 1);

            if(check_i && check_j) {				//no legal moves
                legalMove = false;
                return legalMove;
            }
        }
    }
    return legalMove;
}


