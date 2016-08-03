    // DFS 
    // time complexity?
    // the number of recursion is the final size of inter_res[]
    // the number of push operation is the size of final result inter_res[0]
    int min_len=INT_MAX, max_len=0; // min_len means the minimum length of word in wordDict
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        for(auto w:wordDict){
            w.size()>max_len ? max_len=w.size() : max_len;
            w.size()<min_len ? min_len=w.size() : min_len;
        }
        unordered_map<int, vector<string>> inter_res;   // inter
        if(!wordDict.empty())
            wordBreak(s, wordDict, inter_res, 0);
        return inter_res[0];
    }
    
    void wordBreak(string s, unordered_set<string>& wordDict, unordered_map<int, vector<string>>& inter_res, int start){
        if(start==s.size()){
            inter_res[start]={""};
            return;
        }
        // if this set to be s.size(), then each time it will go through the whole recursion tree
        for(int end=start+min_len-1;end<min(start+max_len, (int)s.size());end++){
            string word=s.substr(start, end-start+1);
            if(wordDict.find(word)!=wordDict.end()){
            // compare with that part of TLE solution below------------------------------------------------
                if(inter_res.find(end+1)!=inter_res.end())
                    for(auto e:inter_res[end+1])
                    // if(find(inter_res[start].begin(), inter_res[start].end(), (word + " " + e))==inter_res[start].end())
                    // since it has already pruned the recursion tree, there is no need to remove duplicates
                        if(e=="")
                            inter_res[start].push_back(word);
                        else
                            inter_res[start].push_back(word+ " " + e);
                else{
                    wordBreak(s, wordDict, inter_res, end+1);   // returns the complete combination vector of s[end+1, s.size()]
                    for(auto e:inter_res[end+1])
                        if(e=="")
                            inter_res[start].push_back(word);
                        else
                            inter_res[start].push_back(word+ " " + e);
                }
            // ------------------------------------------------------------------------------------------
            }
        }
        return;
    }
    
    // TLE
    // the problem is inter_res failed to record the real intermediate result
    // inter_res[] should have stored all the possible strings at declaration, not be updated during recursion 
    unordered_map<int, vector<string>> inter_res;
    int min_len=INT_MAX, max_len=0;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        for(auto w:wordDict){
            w.size()>max_len ? max_len=w.size() : max_len;
            w.size()<min_len ? min_len=w.size() : min_len;
        }
        vector<string> res;
        if(!wordDict.empty())
            wordBreak(s, wordDict, res, 0);
        return inter_res[s.size()-1];
    }
    
    void wordBreak(string s, unordered_set<string>& wordDict, vector<string>& res, int start){
        // if this set to be s.size(), then each time it will go through the whole recursion tree
        for(int end=start+min_len-1;end<min(start+max_len, (int)s.size());end++){
            string word=s.substr(start, end-start+1);
            if(wordDict.find(word)!=wordDict.end()){
                if(inter_res.find(start-1)!=inter_res.end()){
                    for(auto e:inter_res[start-1])
                        if(find(inter_res[end].begin(), inter_res[end].end(), (e + " "+word))==inter_res[end].end())
                            inter_res[end].push_back(e + " "+word);
                    wordBreak(s, wordDict, res, end+1);
                }
                else{
                    inter_res[end].push_back(word);
                    wordBreak(s, wordDict, res, end+1);
                }
            }
        }
    }
