class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
          int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] =
                    mat[i - 1][j - 1]
                    + pref[i - 1][j]
                    + pref[i][j - 1]
                    - pref[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int len = 1; len <= min(m, n); len++) {
            for (int i = len; i <= m; i++) {
                for (int j = len; j <= n; j++) {
                    int sum =
                        pref[i][j]
                        - pref[i - len][j]
                        - pref[i][j - len]
                        + pref[i - len][j - len];

                    if (sum <= threshold) {
                        ans = len;
                    }
                }
            }
        }
        return ans;
    }
};