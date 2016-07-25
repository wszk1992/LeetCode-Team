    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.empty()){
            string s;
            letterCombinations(res, digits, s, 0);
        }
        return res;
    }
    void letterCombinations(vector<string> &res, string digits, string s, int pos){
        if(pos==digits.size()){
            res.push_back(s);
            return ;
        }
        if(digits[pos]>'9' || digits[pos]<'2')
            return;
        int for_nine= digits[pos]=='9' || digits[pos]=='7' ? 4 : 3;  // other method is using a map or vector to store corresponding letters
        for(int i=0;i<for_nine;i++){
            int m= digits[pos]>'7' ? 1 : 0; // '7' has four possible letters
            s+='a'+3*(digits[pos]-'2')+i+m;
            letterCombinations(res, digits, s, pos+1);
            s=s.substr(0, s.size()-1);
        }
    }
