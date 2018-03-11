#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

//Table of weights representing how optimal the position is
extern int scoreTable[8][8]; /*[8][8] = {{7, 2, 5, 4, 4, 5, 2, 7},
					 {2, 1, 3, 3, 3, 3, 1, 2},
				  	 {5, 3, 6, 5, 5, 6, 3, 5},
				     {4, 3, 5, 6, 6, 5, 3, 4},
				     {4, 3, 5, 6, 6, 5, 3, 4},
				     {5, 3, 6, 5, 5, 6, 3, 5},
				     {2, 1, 3, 3, 3, 3, 1, 2},
				     {7, 2, 5, 4, 4, 5, 2, 7},
				    };*/

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Board * board;
    Side mySide;
    Side oppSide;
};

#endif
