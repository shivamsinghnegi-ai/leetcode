class Solution {
public:
    int sumOfMultiples(int n) {
          int sum = 0;
        for (int i = 1; i <= n; i++) {
            bool ok = false;
            for (int d : {3,5,7}) {
                if (i % d == 0) {
                    ok = true;
                }
            }
            if (ok)
                sum += i;
        }
        return sum;
    }
};