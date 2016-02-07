 bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
        return false;
        map<char,char> m,n;
        map<char,char>::iterator iter,iter2;
        for(int i=0;i<s.length();i++) //how to use for_range loop to traverse both two strings
        {
            if(m.find(s[i])!=m.end())
            {
                iter=m.find(s[i]);
                if(iter->second!=t[i])
                return false;
            }
            else
            m.insert(pair<char,char>(s[i],t[i]));
            if(n.find(t[i])!=n.end())             // symmetry
            {
                iter2=n.find(t[i]);
                if(iter2->second!=s[i])
                return false;
            }
            else
            n.insert(pair<char,char>(t[i],s[i]));
        }
        return true;
    }