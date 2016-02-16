    bool wordPattern(string pattern, string str) {
    map<char,string> m;
    vector<string> s;
    map<char,string>::iterator iter;
    int k=0,l=0;
    for(;k<str.length();k++)                                     //for(auto c:str)
    if(str[k]==' ')
    {
        s.push_back(str.substr(l,k-l));
        l=k+1;
    }
    s.push_back(str.substr(l,l-k));
    if(pattern.size()!=s.size())
      return false;
    string::iterator i=pattern.begin();
    vector<string>::iterator j=s.begin();
    for(;i!=pattern.end();i++,j++)                                //i<m.end()?
    {
        if(i+1!=pattern.end()&&(*i==*(i+1))!=(*j==*(j+1)))
        return false;
        if(m.find(*i)==m.end())
        m.insert(pair<char,string>(*i,*j));                       //insert has no return value?
    else 
    {
        iter=m.find(*i);
        if(iter->second!=*j)
        return false;
    }}
    return true;
    }                                                             // testcase¿¼ÂÇ²»È«