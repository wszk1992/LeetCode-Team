    int titleToNumber(string s) {
        int res=0, decimal=1;
        for(string::reverse_iterator riter=s.rbegin();riter!=s.rend();riter++, decimal*=26)
            res+=(decimal*(*riter-'A'+1));
        return res;
    }
