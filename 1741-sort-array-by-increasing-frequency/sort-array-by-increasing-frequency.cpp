class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums)
            mp[x]++;
        vector<pair<int,int>> vp;
        for(auto &[e,f] : mp)
            vp.push_back({f,e}); 
        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        vector<int> ans;
        for(auto &[f,e] : vp)
            ans.insert(ans.end(), f, e);

        return ans;
    }
};