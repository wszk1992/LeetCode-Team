    // BFS TLE
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int min_len=INT_MAX, max_len=0; // min_len means the minimum length of word in wordDict
        for(auto w:wordDict){
            w.size()>max_len ? max_len=w.size() : max_len;
            w.size()<min_len ? min_len=w.size() : min_len;
        }
        unordered_map<int, vector<string>> res;
        res[0].push_back("");
        queue<int> Q;
        Q.push(0);
        while(!Q.empty()){
            int pos=Q.front();
            Q.pop();
            for(int currPos=pos+min_len;currPos<=min(pos+max_len, (int)s.size());currPos++){
                string word=s.substr(pos, currPos-pos);
                if(wordDict.find(word)!=wordDict.end()){
                    for(auto w:res[pos]){
                        if(w==""){
                                res[currPos].push_back(word);
                                continue;
                        }
                        if(find(res[currPos].begin(), res[currPos].end(), (w+" "+word))==res[currPos].end())
                            res[currPos].push_back(w+" "+word);
                    }
                    Q.push(currPos);
                }
            }
        }
        return res[s.size()];
    }
