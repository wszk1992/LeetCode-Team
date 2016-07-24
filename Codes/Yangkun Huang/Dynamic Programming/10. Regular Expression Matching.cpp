    // http://blog.csdn.net/doc_sgl/article/details/12719761
    // method 1 recursion version
    bool isMatch(string s, string p) {
        // be careful cannot write if(s.empty()) return p.empty()
        if(p.empty())
            return s.empty();
        return isMatch(&s[0], &p[0]);
    }
    
    bool isMatch(char *s, char *p){
        // edge case
        if(*p=='\0')
            return *s=='\0';
        // case 1 p+1!='*' current s and p must match    
        if(*(p+1)!='*'){
            if(*s==*p || *p=='.' && *s!='\0') // *s!='\0' prevent from runtime error, also a edge case
                return isMatch(s+1, p+1);
        }
        // case 2 p+1=='*'
        if(*(p+1)=='*'){
            // subcase 1 skip current p
            if(isMatch(s, p+2))
                return true;
            // subcase 2 repeat '*' as many times as possible
            while(*s==*p || *p=='.' && *s!='\0') //  backtracking
                if(isMatch(++s, p+2)) 
                    return true;
        }
        return false;
    }

    // method 2 iterative version
