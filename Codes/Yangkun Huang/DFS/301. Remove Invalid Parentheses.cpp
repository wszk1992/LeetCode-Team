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
