    // http://blog.csdn.net/yingxunren/article/details/3968800
    bool isMatch(string s, string p) {
        return isMatch(&s[0], &p[0]);
    }
    bool isMatch(const char *s, const char *p) {
        // const char * is a pointer to a const char
        const char *preP = NULL, *preS = NULL;    //previous starting comparison place after * in s and p.
        bool asteriskFound = false;
        while(*s != '\0'){
            if(*p == *s || *p == '?'){
                ++s; 
                ++p;
            }
            else if(*p == '*'){
                preP = ++p;             // change values of const? preP is a pointer to const char
                preS = s;
                asteriskFound = true;
            }
            else{
                // p stop moving, s go on until find 'ab' elements between two '*'
                // p=c*ab*c s=cdd ab bac
                if(asteriskFound){
                    p = preP;
                    s = (++preS);
                }
                else 
                    return false;
            }
        }
        // s have reached the end, p have not
        while(*p == '*') 
            ++p;
        return *p == '\0';
    }
