//CHANGE MADE WOOHOO!!!
// Kevin was here hello
#include "player.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */

    board = new Board();
    mySide = side;

    if(mySide == WHITE)
        oppSide = BLACK;
    else
        oppSide = WHITE;

}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

    //If opponents move is legal, do it
    if (board -> checkMove(opponentsMove, oppSide))
        board -> doMove(opponentsMove, oppSide);

    //Test if no valid moves
    if(!(board -> hasMoves(mySide)))
        return nullptr;

    //Part 1 random method:

     /*for (int i = 0; i < 8; i++)
     {
         for (int j = 0; j < 8; j++)
         {
             Move * move = new Move(i, j);
             if (board -> checkMove(move, mySide))
             {
                 board -> doMove(move, mySide);
                 return move;
             }
         }
     }*/
    Board * boardCopy = board -> copy();
    int bestX = -1, bestY = -1, bestScore = -999999;
    Move * move;
    int myScore = 0;

    //Loop through all spots on board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            myScore = 0;
            move = new Move(i, j);

            //Check if move at current spot is legal
            if (board -> checkMove(move, mySide))
            {
                //If legal make the move on the board copy
                boardCopy -> doMove(move, mySide);
                for (int r = 0; r < 8; r++)
                {
                    for (int c = 0; c < 8; c++)
                    {
                        if (boardCopy -> get(mySide, r, c))
                            //Add the weighted score at this spot if I have a piece there
                            myScore += scoreTable[r][c];
                        else if (boardCopy -> get(oppSide, r, c))
                            //Subtract the weighted score at this spot if
                            //my oppenent has a piece there
                            myScore -= scoreTable[r][c];
                    }
                }

                //Update best score, best position, and board copy
                if (myScore > bestScore)
                {
                    bestScore = myScore;
                    bestX = i;
                    bestY = j;
                }
                boardCopy = board -> copy();
            }
        }
    }

    //If score hasn't changed we have no available moves
    if (bestX == -1 && bestY == -1)
        return nullptr;

    //Make move with best position and return it
    move -> setX(bestX);
    move -> setY(bestY);
    board -> doMove(move, mySide);
    return move;
}
