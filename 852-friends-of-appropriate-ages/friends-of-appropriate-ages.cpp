class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(),ages.end());
        for(int i=ages.size()-1;i>0;i--){
            int x = i;
            int y = x - 1;
            while(y >= 0){
                double yAge = (0.5 * ages[x]) + 7;
                if(ages[y] > yAge){
                    ++ans;
                    if(ages[x] == ages[y]) ++ans;
                }
                y--;
            }
        }
        return ans;
    }
};