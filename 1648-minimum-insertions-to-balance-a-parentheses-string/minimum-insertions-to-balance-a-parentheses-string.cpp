class Solution {
public:
    int minInsertions(string s) {
        int cnt=0;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                cnt++;                  
            else{
                if(!cnt)
                    ans++;              
                else
                    cnt--;               
                if(i+1==n||s[i+1]!=')')
                    ans++;              
                else
                    i++;    
            }
        }

        return ans+cnt*2;   
    }
};