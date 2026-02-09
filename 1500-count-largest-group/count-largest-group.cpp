class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[37] = {0};  
        for (int i = 1; i <= n; i++) {
            int x = i, sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            cnt[sum]++;
        }
        int maxSize = 0;
        for (int i = 0; i < 37; i++)
            maxSize = max(maxSize, cnt[i]);

        int ans = 0;
        for (int i = 0; i < 37; i++)
            if (cnt[i] == maxSize) ans++;

        return ans;
    }
};
