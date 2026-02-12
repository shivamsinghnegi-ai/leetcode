class Solution {
public:
    int smallestEvenMultiple(int n) {
         int x = 1;

        while (true) {
            if (x % n == 0 && x % 2 == 0)
                return x;
            x++;
        }
    }
};