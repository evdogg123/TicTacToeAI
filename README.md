# TicTacToeAI
Project to Build AI that will always win or tie at TicTacToe using a decision tree 

The GameState class serves as a node of the decision tree. It contains a board, which is the current board, and 9 child GameStates, which are the maximum
of 9 different moves that the next player can make.

The GameStateTree class creates this tree, and allows the AI to determine the best move by summing up all the GameState nodes in each branch and
choosing the best option for the computer.

The Game class executes the Game by updating the current board by traveling through the GameStateTree based on the moves that are inputted.
