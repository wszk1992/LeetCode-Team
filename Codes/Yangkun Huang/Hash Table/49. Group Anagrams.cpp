// method 1
vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, multiset<string>> mp;  
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());     // 排序目的为找出所有字母相同的string
            mp[t].insert(s);              // 所含字母作为key 对应的anagrams存入multiset中
        }
        vector<vector<string>> anagrams;  // 每一个multiset存入一个vector
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }


// method 2
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> vecvec;
        vector<string> vec;
        int num_type=0;
        string sort_s;
        for(int i=0;i<strs.size();i++)
        { 
            sort_s=strs[i];
            sort(sort_s.begin(),sort_s.end());
            if(map.find(sort_s)==map.end())
            {
                map[sort_s]=num_type;              // 每碰到一个anagram的第一个string就存入最终结果
                vec.push_back(strs[i]);
                vecvec.push_back(vec);
                vec.clear();
                num_type++;                        // 在vecvec中的位置
            }
            else
                insert(vecvec[map[sort_s]],strs[i]);   // 再在最终结果中插入相同anagram的其他string
        }
        return vecvec;
    }
    
    void insert(vector<string>& str,string s)
    {
       
        for(int i=0;i<str.size();i++)
        {
            if(s.compare(str[i])<0)
            { 
                str.insert(str.begin()+i,s);
                return ;
            }
        }
            str.push_back(s);
    }