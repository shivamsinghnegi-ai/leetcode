class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, long long> indexsum;
        unordered_map<int, long long> indexcnt;
        for (int i = 0; i < n; i++) {
            long long freq = indexcnt[nums[i]];
            long long sum = indexsum[nums[i]];
            arr[i] += freq * i - sum;
            indexcnt[nums[i]] += 1;
            indexsum[nums[i]] += i;
        }

        indexsum.clear();
        indexcnt.clear();
        for (int i = n - 1; i >= 0; i--) {
            long long freq = indexcnt[nums[i]];
            long long sum = indexsum[nums[i]];
            arr[i] += sum - freq * i;
            indexcnt[nums[i]] += 1;
            indexsum[nums[i]] += i;
        }
        return arr;
    }
};