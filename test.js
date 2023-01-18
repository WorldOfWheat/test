function gameWon(board) {
    /* Looks at all possible lines of 3,
     * to see if they are occupied by three of the same symbols
     * board: is a 1D array with 9 integers: 
     * 1 = "X" (first player), 0 = free, 1 = "O"
     * Returns boolean.
     */
    let value;
    let i;
    // In Structured Text you'd not have gameWonReturn, 
    //    as you would use `gameWon` instead for returning a value
    let gameWonReturn = false; 
    
    for (i = 0; i < 3; i++) {
        value = board[i*3];
        if (value != 0 && value == board[i*3+1] && value == board[i*3+2]) {
            gameWonReturn = true;
            break;
        }
        value = board[i];
        if (value != 0 && value == board[i+3] && value == board[i+6]) {
            gameWonReturn = true;
            break;
        }
        if (value != 0 && value == board[4] && value == board[8-i]) {
            gameWonReturn = true;
            break;
        }
    }
    return gameWonReturn;
}

function play(board, moveStack, moveCount, move) {
    let playReturn;
    
    // Derive played symbol from number of moves played
    board[move] = 1 - (moveCount % 2) * 2; // Use MOD operator. Result is 1 or -1
    moveStack[moveCount] = move; // Log move in stack
    playReturn = moveCount + 1;
    return playReturn;
}

function minimax(board, moveStack, moveCount) {
    const scoreStack = Array(10); // Array of signed integers
    const originalMoveCount = moveCount;
    let move;          // -1..9
    let score;         // -10..10
    let player;        // -1 or 1
    let minimaxReturn = -1; // -1..9

    while (true) {
        // Current player can be derived from the number of moves that were played
        player = 1 - (moveCount % 2) * 2; // 1 = First, maximizing player. -1 = Second, minimizing player
        // Check for game-over
        if (gameWon(board)) { // Preceding move resulted in win for previous player
            scoreStack[moveCount] = -(10 - moveCount) * player; // Earlier wins get greater score
        } else if (moveCount == 9) { // It's a draw
            scoreStack[moveCount] = 0;
        } else {
            moveStack[moveCount] = -1; // Prepare for iterating moves for current player
            scoreStack[moveCount] = -player * 10; // Initialize with worst possible score for current player
            moveCount++;
        }
        do { // Repeat:
            moveCount--;
            if (moveCount < originalMoveCount) { // All done
                break; // Exit point
            }
            // Look for a next, valid move
            move = moveStack[moveCount];
            if (move >= 0) { // Was a valid move: derive score from deeper results
                score = scoreStack[moveCount + 1]; // Best score opponent can get
                if ((board[move] == 1) == (score > scoreStack[moveCount])) { // Improvement
                    scoreStack[moveCount] = score;
                    if (moveCount == originalMoveCount) {
                        minimaxReturn = move; // For now this is a best move...
                    }
                }
                // Take back move
                board[move] = 0;
            }
            // Look for next valid move
            do {
                move++;
            } while (move < 9 && board[move] != 0) // Occupied
        } while (move == 9); // Backtrack (i.e. repeat loop) when all moves were tried

        if (moveCount < originalMoveCount) { // All done
            break; // Exit point
        }
        // Play move
        moveCount = play(board, moveStack, moveCount, move);
    }
    return minimaxReturn;
}

function main() {
    const board = Array(9).fill(0); // An empty 3x3 board as 1 dimensional array
    const moveStack = Array(10);    // History of played moves (indices in board)
    let moveCount = 0;              // Number of moves played
    let bestMove;
    
    /* Demo:
     * Play moves to arrive at this board:
     *  
     *     X | O | 
     *    ---+---+---
     *     O |   |
     *    ---+---+---
     *     X |   |
     */     
    moveCount = play(board, moveStack, moveCount, 0); // Play X in top-left
        moveCount = play(board, moveStack, moveCount, 1); // Play O next to it
    moveCount = play(board, moveStack, moveCount, 6); // Play X in bottom-left
        moveCount = play(board, moveStack, moveCount, 3); // Play O in middle row
    
    // Run minimax for suggesting where to play an "X":
    bestMove = minimax(board, moveStack, moveCount);
    console.log(bestMove); // 4 (center of the board)
}
main();
