class Solution{
public:
    string lexGreaterPermutation(string &s, string &tgt){
        int n = s.size();
        int freq[26] = {0};
        for(int i = 0 ; i < n ; i++) freq[s[i]-'a']++ , freq[tgt[i]-'a']--;
        bool isSame = true;
        for(int i = 0 ; i < 26 ; i++) if(freq[i]) isSame = false;
        if(isSame) return next_permutation(tgt.begin(),tgt.end()) ? move(tgt) : "" ;

        map<char,int> m;
        for(int i = 0 ; i < n ; i++) m[s[i]]++;
        string ans = move(s);

        auto fun = [&](auto &fun,int idx)->bool{
            if(idx == n) return true;
            auto it = m.lower_bound(tgt[idx]); if(it==m.end()) return false;

            if(it->first > tgt[idx]){
                ans[idx++] = it->first;
                if((--it->second) == 0) m.erase(it);
                for(auto &[ch,f] : m)
                    for(int i = 0 ; i < f ; i++) ans[idx++] = ch;
                return true;
            }

            ans[idx] = it->first;
            if((--it->second) == 0) m.erase(it);
            if(fun(fun,idx+1)) return true;
            m[tgt[idx]]++;

            it = m.upper_bound(tgt[idx]); if(it==m.end()) return false;
            ans[idx++] = it->first;
            if((--it->second) == 0) m.erase(it);
            for(auto &[ch,f] : m)
                for(int i = 0 ; i < f ; i++) ans[idx++] = ch;
            return true;
        };

        return fun(fun,0) ? move(ans) : "" ;
    }
};