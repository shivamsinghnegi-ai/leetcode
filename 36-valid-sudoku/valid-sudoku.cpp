class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col) {
        char num = board[row][col];
        // Check row
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == num)
                return false;
        }
        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == num)
                return false;
        }
        // Find starting position of 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        // Check 3x3 box
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {

                if ((i != row || j != col) && board[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                if (!isValid(board, row, col))
                    return false;
            }
        }
        return true;
    }
};