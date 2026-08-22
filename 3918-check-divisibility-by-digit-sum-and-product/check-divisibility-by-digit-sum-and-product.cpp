class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digProduct = 1;
        int x = n;
        while (x > 0) {
            int r = x % 10;
            digSum += r;
            digProduct *= r;
            x /= 10;
        }

        return n % (digSum + digProduct) == 0;
    }
};