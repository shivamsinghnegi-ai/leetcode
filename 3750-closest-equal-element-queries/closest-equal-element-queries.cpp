class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map <int,pair <int,int>> mpp;
        vector <int> ans(n,-1);
        for(int i = 0 ; i <n ; i++){
            if(mpp.count(nums[i])){
                int a = mpp[nums[i]].first;
                int b = mpp[nums[i]].second;
                ans[i] = min(i - a , n - i + a);
                if(ans[a] == -1)
                    ans[a] = INT_MAX;
                ans[a] = min(ans[a] , min(i-a , n-i+a));
                if(ans[b] == -1)
                    ans[b] = INT_MAX;

                ans[b] = min(ans[b] , min(i-b , n-i+b));
                ans[i] = min(ans[i] , min(i - b , n - i + b));

                mpp[nums[i]].second = i;

            }
            else {
                mpp[nums[i]] = {i,i};
            }

        }
        for(int& q :queries){
            q = ans[q];
        }

        return queries;

    }
};