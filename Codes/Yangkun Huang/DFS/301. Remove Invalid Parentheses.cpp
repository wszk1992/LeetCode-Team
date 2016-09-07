    // bfs?
    
    // must calculate left and right at the first, cannot do it on the fly
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left_remain = 0, right_remain = 0;
        for (char ch : s) {
            if (ch == '(')
                ++left_remain;
            if (ch == ')') 
                left_remain > 0 ? --left_remain : ++right_remain;
        }
        dfs(s.begin(), left_remain, right_remain, 0, "", res);
        return res;
    }
    
    void dfs(string::iterator pos, int left_remain, int right_remain, int half_bracket, string path, vector<string> &res) {
        if(*pos=='\0'){ // use find() or set<string> to avoid duplicate string, or use loop to skip duplicate letter during recursion
            if(left_remain==0 && right_remain==0 && half_bracket==0 && find(res.begin(), res.end(), path)==res.end())
                res.push_back(path);
            return;
        }
        if(*pos!='(' && *pos!=')')
            dfs(pos+1, left_remain, right_remain, half_bracket, path+*pos, res);
        else if(*pos=='('){
            if(left_remain>0)
                dfs(pos+1, left_remain-1, right_remain, half_bracket, path, res);   // delete current '('
            dfs(pos+1, left_remain, right_remain, half_bracket+1, path+*pos, res);    // keep current '(' and label there is a half bracket
        }
        else if(*pos==')'){
            if(right_remain>0)
                dfs(pos+1, left_remain, right_remain-1, half_bracket, path, res);   // delete current ')'
            if(half_bracket>0)
                dfs(pos+1, left_remain, right_remain, half_bracket-1, path+*pos, res);    // match current ')' with previous "("
        }
        
    }
    
    // not AC
    // vector<string> removeInvalidParentheses(string s) {
    //     vector<string> res;
    //     aux_func(res, s, 0, 0);
    //     return res;
    // }
    
    // void aux_func(vector<string> &res, string s, int pos, int count){
    //     if(pos>=s.size()){  // cannot write as if(pos>s.size()-1) since this will overflow when s is empty
    //         for(int i=pos-1;i>=0 && count>0;i--)
    //             if(s[i]=='('){
    //                 s.erase(s.begin()+i);
    //                 count--;
    //             }
    //         res.push_back(s);
    //         return;
    //     }
    //     if(s[pos]=='(')
    //         count++;
    //     if(s[pos]==')')
    //         count--;
    //     if(count<0){
    //         for(int i=0;i<pos;i++){
    //             if((s[i]==')' && s[i+1]!=')') || (s[i]==')' && i==pos-1)){
    //                 auto tmp=*(s.begin()+i);
    //                 s.erase(s.begin()+i);
    //                 aux_func(res, s, pos, count+1);
    //                 s.insert(s.begin()+i, tmp); 
    //             }
    //         }
    //     } 
    //     else
    //         aux_func(res, s, pos+1, count);
    // }
