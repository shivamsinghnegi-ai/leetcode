class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> upper;
        unordered_set<char> unique;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                upper[word[i]]++;
            }
        }
        int count=0;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                char ch=toupper(word[i]);
                if(unique.find(ch) == unique.end(ch) && upper[ch] > 0){
                    count++;
                    unique.insert(ch);
                    upper[ch]--;
                }
            }
        }
        return count;
    }
};