    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26);
        for(auto c:magazine)
            m[c-'a']++;
        for(auto r:ransomNote)
            if(--m[r-'a']<0)
                return false;
        return true;
    }
