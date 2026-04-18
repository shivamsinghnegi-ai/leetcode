class Solution {
public:
    int reverseNumber(int n) {
        int revNum = 0, remender;
        while(n != 0) {
            remender = n % 10;
            revNum = revNum * 10 + remender;
            n /= 10;
        }
        return revNum;
    }
    int mirrorDistance(int n) {
        int revNum = reverseNumber(n);
        return abs(n - revNum);
    }
};