class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> arr;

        for (int i = 0; i < queries.size(); i++) {
            arr.push_back({queries[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(queries.size());
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;

        for (int i = 0; i < queries.size(); i++) {

            int time = arr[i].first;
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];
                mp[server]++;
                right++;
            }
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                mp[server]--;

                if (mp[server] == 0) {
                    mp.erase(server);
                }

                left++;
            }
            ans[arr[i].second] = n - mp.size();
        }

        return ans;
    }
};