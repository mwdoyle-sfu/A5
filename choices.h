//choices.h
#pragma once

bool possibleChoices(Game& B, int i, int j, Tile playerTile, Tile computerTile) {
    // locations
    bool topLeft = false;
    bool left = false;
    bool bottomLeft = false;
    bool bottom = false;
    bool bottomRight = false;
    bool right = false;
    bool topRight = false;
    bool top = false;

    // check for computer / player tile
    if(B.board[i][j] == computerTile)
    {
        return false;
    }else if(B.board[i][j] == playerTile) {
        return false;
    }

    // check for computer tiles
    bool checkLeft = (B.board[i][j-1] == computerTile);
    bool checkBottomLeft = (B.board[i+1][j-1] == computerTile);
    bool checkBottom = (B.board[i+1][j] == computerTile);
    bool checkBottomRight = (B.board[i+1][j+1] == computerTile);
    bool checkRight = (B.board[i][j+1] == computerTile);
    bool checkTopRight = (B.board[i-1][j+1] == computerTile);
    bool checkTop = (B.board[i-1][j] == computerTile);
    bool checkTopLeft = (B.board[i-1][j-1] == computerTile);

    // check left
    if(checkLeft) {
        for(int k = 1; k < j; k++) {
            bool check_All_Tiles_Row = (B.board[i][j-k] == computerTile);
            if(!check_All_Tiles_Row) {
                if(B.board[i][j-k] == playerTile) {
                    left = true;

                    //Change opponent tiles to your tile stoping at the player
                    for(k = 1; k < j; k++) {
                        if(B.board[i][j-k] == playerTile) {
                            break;
                        }else {
                            B.set(i,j, playerTile);
                            B.set(i, j-k, playerTile);
                        }
                    }break;
                }else {
                    break;
                }
            }else {
                left = false;
            }
        }
    }

    // check bottom left (comments are similar to above)
    if(checkBottomLeft) {
        bool check_Tiles;
        for(int k = 1; k < B.height()-i; k++) {
            if(((j - k) == 1) && B.board[i+k][j-k] == computerTile) {
                bottomLeft = false;
                break;
            }else {
                check_Tiles = (B.board[i+k][j-k] == computerTile);
                if(!check_Tiles) {
                    if(B.board[i+k][j-k] == playerTile) {
                        bottomLeft = true;

                        for(k = 1; k < B.height()-i; k++) {
                            if(B.board[i+k][j-k] == playerTile) {
                                break;
                            }else {
                                B.set(i,j, playerTile);
                                B.set(i+k, j-k, playerTile);
                            }
                        }break;
                    }
                    else {
                        break;
                    }
                } else {
                    bottomLeft = false;
                }
            }
        }
    }

    // check bottom (comments are similar to above)
    if(checkBottom) {
        for(int k = 1; k < B.height()-i; k++) {
            bool check_All_Tiles_Row = (B.board[i+k][j] == computerTile);
            if(!check_All_Tiles_Row) {
                bool checkplayerTile = B.board[i+k][j] == playerTile;
                if(checkplayerTile) {
                     bottom = true;
                    for(k = 1; k < B.height()-i; k++) {
                        if(B.board[i+k][j] == playerTile) {
                            break;
                        }else {
                            B.set(i,j, playerTile);
                            B.set(i+k, j, playerTile);
                        }
                    }break;
                }
                else {
                    break;
                }
            }else
            {
                bottom = false;
            }
        }
    }

    // check bottom right (comments are similar to above)
    if(checkBottomRight) {
        bool check_Tiles;
        for(int k = 1; k < B.height()-i; k++) {
            if(((j + k) == 8) && B.board[i+k][j+k] == computerTile) {
                bottomRight = false;
                break;
            } else {
                check_Tiles = (B.board[i+k][j+k] == computerTile);

                if(!check_Tiles) {
                    if(B.board[i+k][j+k] == playerTile) {
                        bottomRight = true;
                        for(k = 1; k < B.height()-i; k++) {
                            if(B.board[i+k][j+k] == playerTile) {
                                break;
                            }else {
                                B.set(i+k, j+k, playerTile);
                                B.set(i,j,playerTile);
                            }
                        } break;
                    }else {
                        break;
                    }
                }else {
                    bottomRight = false;
                }
            }
        }
    }

    // check right (comments are similar to above)
    if(checkRight) {
        for(int k = 1; k < B.width()-j; k++) {
            bool check_All_Tiles_Row = (B.board[i][j+k] == computerTile);
            if(!check_All_Tiles_Row) {
                if(B.board[i][j+k] == playerTile) {
                    right = true;
                    for(k = 1; k < B.width()-j; k++) {
                        if(B.board[i][j+k] == playerTile) {
                            break;
                        }else {
                            B.set(i,j,playerTile);
                            B.set(i, j+k,playerTile);
                        }
                    }break;
                }else {
                    break;
                }
            }else {
                right = false;
            }
        }
    }

    // check top right (comments are similar to above)
    if(checkTopRight) {
        bool check_Tiles;
        for(int k = 1; k < i; k++) {
            if(((j + k) == 8) && B.board[i-k][j+k] == computerTile) {
                topRight = false;
                break;
            }else {
                check_Tiles = (B.board[i-k][j+k] == computerTile);
                if(!check_Tiles) {
                    if(B.board[i-k][j+k] == playerTile) {
                        topRight = true;
                        for(k = 1; k < i; k++) {
                            if(B.board[i-k][j+k] == playerTile) {
                                break;
                            }else {
                                B.set(i,j,playerTile);
                                B.set(i-k,j+k,playerTile);
                            }
                        }break;
                    }else {
                        break;
                    }
                }else {
                    topRight = false;
                }
            }
        }
    }

    //check top (comments are similar to above)
    if(checkTop) {
        for(int k = 1; k < i; k++) {
            bool check_All_Tiles_Row = (B.board[i-k][j] == computerTile);
            if(!check_All_Tiles_Row) {
                if(B.board[i-k][j] == playerTile) {
                    top = true;
                    for(k = 1; k < i; k++) {
                        if(B.board[i-k][j] == playerTile) {
                            break;
                        }else {
                            B.set(i,j,playerTile);
                            B.set(i-k, j, playerTile);
                        }
                    }break;
                }else {
                    break;
                }
            }else {
                top = false;
            }
        }
    }

    // check top left(comments are similar to above)
    if(checkTopLeft) {
        bool check_Tiles;
        for(int k = 1; k < i; k++) {
            if(((j - k) == 1) && B.board[i-k][j-k] == computerTile) {
                topLeft = false;
                break;
            }else {
                check_Tiles = (B.board[i-k][j-k] == computerTile);
                if(!check_Tiles) {
                    if(B.board[i-k][j-k] == playerTile) {
                        topLeft = true;
                        for(k = 1; k < i; k++) {
                            if(B.board[i-k][j-k] == playerTile) {
                                break;
                            }else {
                                //replace all the opponent tiles
                                B.set(i,j,playerTile);
                                B.set(i-k, j-k, playerTile);
                            }
                        }break;
                    }else {
                        break;
                    }
                } else {
                    topLeft = false;
                }
            }
        }
    }

    // check for computer tile
    if(!checkBottom && !checkBottomLeft && !checkBottomRight && !checkLeft && !checkRight && !checkTop
        && !checkTopLeft && !checkTopRight) {
        return false;
    }
    // if none are available return false
    else if(!topLeft && !top && !left && !bottom && !bottomLeft && !bottomRight
             && !right && !topRight) {
        return false;
    }
        // otherwise return true
    else {
        return true;
    }
}