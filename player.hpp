#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

//Table of weights representing how optimal the position is
extern int scoreTable[8][8];

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
