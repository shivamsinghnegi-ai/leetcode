class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int sum = total - x;
        if(sum < 0)
            return -1;
        if(sum == n)
            return n;
        int left = 0;
        int currsum = 0;
        int maxlen = -1;
        for(int right = 0; right < n; right++)
        {
            currsum += nums[right];
            while(currsum > sum)
            {
                currsum -= nums[left];
                left++;
            }
            if(currsum == sum)
            {
                maxlen = max(maxlen, right - left + 1);
            }
        }
        if(maxlen == -1)
            return -1;
        return n-maxlen;
    }
};