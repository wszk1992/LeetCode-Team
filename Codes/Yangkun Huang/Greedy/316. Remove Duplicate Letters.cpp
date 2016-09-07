    // the main idea is delete duplicates which on the front and use stack to store relative position
    // string csn also use pop_back and push_back
    // array > vector> unordered_map
    string removeDuplicateLetters(string s) {
        vector<int> cnts(26);
        string ret;
        stack<char> stk;
        vector<bool> isInStack(26, false);
        for (char each : s) // calculate the number of times each char appears
            cnts[each-'a'] ++;
        for (int i = 0; i < s.size(); cnts[s[i]-'a'] --, ++ i) {
            if (isInStack[s[i] - 'a']) 
                continue;
            while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()-'a'] > 0) {   
                isInStack[stk.top() - 'a'] = false;    // cnts[stk.top()] > 0 means there are same chars in latter
                stk.pop();
            }
            stk.push(s[i]);
            isInStack[s[i] - 'a'] = true;
        }
        while (!stk.empty()) {
            ret=stk.top()+ret;
            stk.pop();
        }
        return ret;
    }
