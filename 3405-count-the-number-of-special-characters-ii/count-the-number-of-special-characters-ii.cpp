class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count =0;
        for(char ch='a';ch<='z';ch++){
            char lower=ch;
            char upper =ch-32;
            int LastLower=-1;
            int FirstUpper=-1;

        for(int i=0;i<word.size();i++){
            if(word[i]==lower){
                LastLower=i;
            }
            if(word[i]==upper && FirstUpper==-1){
                FirstUpper=i;
            }
        }
        if(LastLower!=-1 && FirstUpper!=-1 && LastLower<FirstUpper){
            count++;
        }
        }
        return count;
    }
};