class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;
        int ls = 0, rs = 0;
        int lq = 0, rq = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?')
                lq++;
            else
                ls += num[i] - '0';
        }
        for (int i = mid; i < n; i++) {
            if (num[i] == '?')
                rq++;
            else
                rs += num[i] - '0';
        }

        if (lq == rq)
            return ls != rs;

        return 2 * (ls - rs) != 9 * (rq - lq);
    }
};