   // Manacher’s Algorithm 
   // main idea: check each position as middle of palindromic substring, do not check from both ends
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size();) {
            if (s.size() - i <= res.size() / 2) 
                break;
            int start = i, end = i;
            while (end < s.size()-1 && s[end+1] == s[end]) // Skip duplicate characters
                ++end; 
            i = end+1;
            while (end < s.size()-1 && start > 0 && s[end + 1] == s[start - 1]) // Expand
                ++end, --start; 
            if (end - start + 1 > res.size()) 
                res=s.substr(start, end-start+1);
        }
        return res;
    }

    // check from both ends TLE
    string longestPalindrome(string s) {
        string res;
        for(int i=s.size();i>0;i--){
            for(int start=0, end=start+i-1;end<s.size();start++, end++)
                if(isPalindromic(s, start, end)){
                    res=s.substr(start, end-start+1);
                    break;
                }
            if(res!="")
                break;
        }
        return res;
    }
    
    bool isPalindromic(string s, int start, int end){
        for(int i=start, j=end;i<j;i++, j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }
