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
