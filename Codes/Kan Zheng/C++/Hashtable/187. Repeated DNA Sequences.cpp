class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        /*bad method
        int f,b,i;
        vector<string> vec;
        unordered_set<string> set;
        if(s.length()<=10)
            return vec;
        for(f=0;f<s.length();f++)
        {
            
            for(b=f+1;b<s.length()-10;b++)
            {
                for(i=0;i<10;i++)
                {
                    if(s[f+i]!=s[b+i])
                        break;
                }
                if(i==10&&set.find(s.substr(f,10))==set.end())
                {
                    vec.push_back(s.substr(f,10));
                    set.insert(s.substr(f,10));
                }
                    
            }
        }
        return vec;
        */
        /*time still exceed
        vector<string> vec;
        unordered_set<string> set;
        for(int i=0;i<s.length();i++)
        {
            string str = s.substr(i,10);
            if(set.find(str)==set.end())
                set.insert(str);
            else
                vec.push_back(str);
        }
        */
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0, i = 0, ss = s.size();
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < ss)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
                r.push_back(s.substr(i - 10, 10));
        return r;
        }
    
    
};