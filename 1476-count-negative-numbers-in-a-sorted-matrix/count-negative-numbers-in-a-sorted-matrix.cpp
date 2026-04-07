class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] < 0){
                    count += col - j;
                    break;
                }
            }
        }
        return count;
    }
};