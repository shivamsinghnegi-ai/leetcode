class Solution {
    static constexpr int mod = 1e9 + 7;
    int add(int a, int b) {return ((a % mod) + (b % mod)) % mod;}

    int go(int x, int y, vector<string>& board, vector<vector<int>> &dp){
        if(x == 0 && y == 0) return 0;

        auto &ret = dp[x][y];
        if(~ret) return ret;

        int val = 0;
        if(isdigit(board[x][y])) val = board[x][y] - '0';

        if(x > 0 && board[x - 1][y] != 'X') ret = max(ret, go(x - 1, y, board, dp) + val);
        if(y > 0 && board[x][y - 1] != 'X') ret = max(ret, go(x, y - 1, board, dp) + val);
        if(x > 0 && y > 0 && board[x - 1][y - 1] != 'X') ret = max(ret, go(x - 1, y - 1, board, dp) + val);

        return ret;
    }

    int go2(int x, int y, int sum, int mx, vector<string>& board, vector<vector<vector<int>>> &dp2){
        if(x == 0 && y == 0) return (sum == mx);

        auto &ret = dp2[x][y][sum];
        if(~ret) return ret;

        ret = 0;
        int val = 0;
        if(isdigit(board[x][y])) val = board[x][y] - '0';

        if(x > 0 && board[x - 1][y] != 'X') ret = add(ret, go2(x - 1, y, sum + val, mx, board, dp2));
        if(y > 0 && board[x][y - 1] != 'X') ret = add(ret, go2(x, y - 1, sum + val, mx, board, dp2));
        if(x > 0 && y > 0 && board[x - 1][y - 1] != 'X') ret = add(ret, go2(x - 1, y - 1, sum + val, mx, board, dp2));

        return ret;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mx = go(n - 1, n - 1, board, dp);
        
        if(mx == -1) return {0, 0};

        vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(18 * n, -1)));
        int cnt = go2(n - 1, n - 1, 0, mx, board, dp2);

        return {mx, cnt};
    }
};