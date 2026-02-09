class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // Track which columns are occupied by queens
        vector<int> colOccupied(n);
      
        // Track which diagonals are occupied (top-left to bottom-right)
        // For diagonal: row + col is constant, range: [0, 2n-2]
        vector<int> diagonalOccupied(n << 1);
      
        // Track which anti-diagonals are occupied (top-right to bottom-left)
        // For anti-diagonal: row - col + n is constant, range: [1, 2n-1]
        vector<int> antiDiagonalOccupied(n << 1);
      
        // Store all valid board configurations
        vector<vector<string>> result;
      
        // Current board state during backtracking
        vector<string> currentBoard(n, string(n, '.'));
      
        // Recursive function to place queens row by row
        function<void(int)> backtrack = [&](int row) -> void {
            // Base case: all queens successfully placed
            if (row == n) {
                result.push_back(currentBoard);
                return;
            }
          
            // Try placing a queen in each column of the current row
            for (int col = 0; col < n; ++col) {
                // Check if current position is safe (no conflicts)
                if (colOccupied[col] + diagonalOccupied[row + col] + 
                    antiDiagonalOccupied[n - row + col] == 0) {
                  
                    // Place the queen
                    currentBoard[row][col] = 'Q';
                  
                    // Mark the column and diagonals as occupied
                    colOccupied[col] = 1;
                    diagonalOccupied[row + col] = 1;
                    antiDiagonalOccupied[n - row + col] = 1;
                  
                    // Recursively place queens in the next row
                    backtrack(row + 1);
                  
                    // Backtrack: remove the queen and unmark positions
                    colOccupied[col] = 0;
                    diagonalOccupied[row + col] = 0;
                    antiDiagonalOccupied[n - row + col] = 0;
                    currentBoard[row][col] = '.';
                }
            }
        };
      
        // Start placing queens from the first row
        backtrack(0);
      
        return result;
    }
};