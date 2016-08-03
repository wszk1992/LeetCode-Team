    // O(n^2) BFS
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int min_len=0, max_len=0;
        for(auto w:wordDict){   // find minimum and maximum length of word in wordDict
            w.size()>max_len ? max_len=w.size() : max_len;
            w.size()<min_len ? min_len=w.size() : min_len;
        }
        queue<int> Q;
        unordered_set<int> visited(s.size());
        Q.push(0);      // element of Q is the position of s
        while(!Q.empty()){  
            int startPoint=Q.front();
            Q.pop();
            if(visited.find(startPoint)==visited.end()){ // O(1) check if visited current vertex or not
                visited.insert(startPoint);
                for(int i=startPoint+min_len-1;i< min(startPoint+max_len, (int)s.size());i++){   // O(n) [start, i] forms new words
                    if(wordDict.find(s.substr(startPoint, i-startPoint+1))!=wordDict.end()){
                        Q.push(i+1);
                        if(i+1==s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
    
    // DFS
    // how to reduce the time complexity
    unordered_map<int, bool> record;  // so important to use dp!!! would TLE without this!
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int min_len=0, max_len=0;
        for(auto w:wordDict){   // find minimum and maximum length of word in wordDict
            w.size()>max_len ? max_len=w.size() : max_len;
            w.size()<min_len ? min_len=w.size() : min_len;
        }
        return wordBreak(s, wordDict, 0, min_len, max_len);
    }
    
    bool wordBreak(string s, unordered_set<string>& wordDict, int startPoint, int min_len, int max_len){
        if(startPoint==s.size())
            return true;
        bool res=false;
        for(int i=startPoint+min_len-1;i< min(startPoint+max_len, (int)s.size());i++){   // O(n) [start, i] forms new words
            if(wordDict.find(s.substr(startPoint, i-startPoint+1))!=wordDict.end())
                res= record.find(i+1)!=record.end() ? record[i+1] : (wordBreak(s, wordDict, i+1, min_len, max_len) || res);
        }
        record[startPoint]=res;
        return res;
    }
