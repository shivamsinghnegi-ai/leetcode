class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<n && !isalpha(s[l])) l++;
            while(r>0 && !isalpha(s[r])) r--;
            if(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};