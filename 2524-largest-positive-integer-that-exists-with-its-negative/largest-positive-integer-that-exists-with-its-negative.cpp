class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum == 0) {
                return nums[high];
            }
            else if (sum < 0) {
                low++;
            }
            else {
                high--;
            }
        }
        return -1;
    }
};