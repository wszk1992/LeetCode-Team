    bool isAnagram(string s, string t) {
        map<char,int> m;
        map<char,int>::iterator a;
        for(string::iterator i=s.begin();i<s.end();i++)
        if(m.find(*i)==m.end())
        m.insert(pair<char,int>(*i,1));
        else
        {
            a=m.find(*i);
            a->second++;
        }
        for(int i=0;i<t.size();i++)
        if(m.find(t[i])==m.end())
        return false;
        else
        {
            a=m.find(t[i]);
            a->second--;
            if(a->second<0)
            return false;
        }
        for(auto c:m)// for(a=m.begin();a!=m.end();a++) //for(auto c:m)
        if(c.second!=0)// if((*a).second!=0)  //if(*c->second!=0)
        return false;
        return true;
    }// map的迭代器遍历 map的迭代器解引用