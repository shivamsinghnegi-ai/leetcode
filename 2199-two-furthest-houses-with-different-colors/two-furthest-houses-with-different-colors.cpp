class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int j = colors.size();

        for (int i = 0; i < j; i++)
            if ((colors[i] ^ colors.back()) | (colors[j - 1 - i] ^ colors[0]))
                return j - 1 - i;

        return 0;
    }
};