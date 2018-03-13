Adam - Contributed calcScore function and scoreTable to heuristic.
Kevin - Contributed getMobility to heuristic.
Both of us worked on and contributed to doMove and recursive Minimax.

We began by making a simple heuristic that took into account an array of weights
for each position on the board. This helped to make the bot prioritize getting corners, etc.
We then improved this heuristic by adding in a factor of mobility - the same weights as
above but this time attributed to the moves our bot could make on a given board.
Finally, we implemented minimax recursion to depth 4, which look several moves ahead
to pick the optimal score.
We think these strategies will work because we have had success against BetterPlayer
and we have a decent heuristic with a bot that is looking several moves ahead.