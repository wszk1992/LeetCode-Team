    // how to determine if a substring is palindrome
    // how to find the way of backtracking
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        vector<string> path;
        dfs(0, s, path, ret);
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            int l=index, r=i;
            while(l<r && s[l]==s[r])
                l++, r--;
            if(l>=r) {     // check if substr(0, i) is palindrome
                path.push_back(s.substr(index, i - index + 1));   
                dfs(i+1, s, path, ret);         // then recursively call dfs() on the rest of string
                path.pop_back();        // pop up s[i] then consider s[i, i+1], s[i, i+2]...s[i, end](backtracking)
            }
        }
    }
