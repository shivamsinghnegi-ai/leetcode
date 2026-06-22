class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int m = 2;
        if (n <= m) return n;
        int k = m;
        for (int i = m; i < n; i++) {
            if (nums[i] != nums[k - m]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};