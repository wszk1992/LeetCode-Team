    // solution 1 hash table
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(auto c:s)
            m[c]++;
        for(auto n:t)
            if(--m[n]<0)
                return n;
        return 0;
    }
    
    // solution 2 bit manipulation
    char findTheDifference(string s, string t) {
        char res=0;
        for(int i=0;i<s.size();i++)
            res^=(s[i]^t[i]);
        return res^t[t.size()-1];
    }
