    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> head({beginWord}), tail({endWord});
        int res = 2;
        while(head.size() && tail.size()){
            if(head.size() > tail.size())   
                swap(head, tail);             // always check the set with smaller size
            unordered_set<string> tmpSet;
            for(auto it = head.begin(); it != head.end(); ++it){
                string str=*it;
                for(int i = 0; i < str.size(); ++i){  // traverse all words
                    int tmp = str[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch){ // change letter from 'a' to 'z'
                        if(str[i]!=ch){ // skip some operations
                            str[i] = ch;
                            if(tail.find(str) != tail.end())
                                return res;
                            if(wordList.find(str) != wordList.end()){ // add to candidates set
                                tmpSet.insert(str);
                                wordList.erase(str);
                            }
                        }
                    }
                    str[i] = tmp; // reset
                }
            }
            swap(head, tmpSet);
            ++ res;
        }
        return 0;
    }
