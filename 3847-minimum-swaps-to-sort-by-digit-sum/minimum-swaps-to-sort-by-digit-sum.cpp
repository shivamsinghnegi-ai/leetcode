class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> numIdxMap;   
        vector<pair<int, int>> sortedList;  
        for(int i =0; i<nums.size(); i++) {
            sortedList.push_back({getDigitSum(nums[i]), nums[i]});
            numIdxMap[nums[i]] = i;
        }
        sort(sortedList.begin(), sortedList.end());

        int swaps = 0;
        for(int i =0; i<nums.size(); i++) {
            if(nums[i] == sortedList[i].second) continue;
            int posi = numIdxMap[sortedList[i].second];
            numIdxMap[nums[i]] = posi;
            swap(nums[posi], nums[i]);
            swaps++;
        }
        return swaps;
    }
};