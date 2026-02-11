class Solution {
public:
    int getLeastFrequentDigit(int n) {
         string s = to_string(n);
        int minFreq = INT_MAX;
        int ans = 9;
        for (int i = 0; i < s.size(); i++) {
            int count = 0;

            for (int j = 0; j < s.size(); j++) {
                if (s[i] == s[j])
                    count++;
            }
            int digit = s[i] - '0';
            if (count < minFreq || (count == minFreq && digit < ans)) {
                minFreq = count;
                ans = digit;
            }
        }
        return ans;
    }
};