class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> minn(n, INT_MAX);
        vector<int> maxx(n, INT_MIN);
        maxx[0] = max(maxx[0], nums[0]);
        minn[n-1] = min(minn[n-1], nums[n-1]);
        for(int i = 1; i < n; i++){
            maxx[i] = max(nums[i], maxx[i-1]);
        }
        for(int i = n-2; i>=0; i--){
            minn[i] = min(nums[i], minn[i+1]);
        }
        vector<int> ans(n, 0);
        ans[n-1] = maxx[n-1];
        for(int i = n-2; i >= 0; i--){
            if(maxx[i] > minn[i+1]){
                ans[i] = ans[i+1];
            }
            else {
                ans[i] = maxx[i];
            }
        }
        return ans;
    }
};