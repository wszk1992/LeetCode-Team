  // second version -- without right_paren
  
  // first version
  vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n){
            string s;
            int left_paren=0, right_paren=0;
            generateParenthesis(res, s, n, left_paren, right_paren);
        }
        return res;
    }
    
    void generateParenthesis(vector<string> &res, string s, int n, int left_paren, int right_paren){
        if(right_paren==n){
            res.push_back(s);
            return ;
        }
        if(!left_paren){
            s+='(';
            left_paren++;
            generateParenthesis(res, s, n, left_paren, right_paren);
            s.pop_back();
        }
        else{
            if(left_paren<n){
                s+='(';
                left_paren++;
                generateParenthesis(res, s, n, left_paren, right_paren);
                s.pop_back();
                left_paren--;
            }
            if(right_paren<left_paren){
                    s+=')';
                    right_paren++;
                    generateParenthesis(res, s, n, left_paren, right_paren);
                    s.pop_back();
                    right_paren--;
            }
        }
        
    }
