class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp = "";
        s.push_back(' ');
        int i = 0;
        int count = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp = "";
                count++;
            }
            else {
                temp += s[i];
            }
            i++;
        }
        string result = "";
        for (int i = 1; i <= count; i++) {
            result += ans[i];
            result += " ";
        }
        result.pop_back();
        return result;
    }
};