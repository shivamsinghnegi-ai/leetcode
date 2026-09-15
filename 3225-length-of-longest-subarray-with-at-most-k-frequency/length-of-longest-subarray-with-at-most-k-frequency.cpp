class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0; 
        int ans = 1; 
        unordered_map<int, int> mp; 
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; 
            while(mp[nums[i]] > k) {
                mp[nums[l++]]--; 
            }
            ans = max(ans, i - l + 1); 
        }
        return ans; 
    }
};