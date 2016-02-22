// method 1
vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, multiset<string>> mp;  
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());     // ����Ŀ��Ϊ�ҳ�������ĸ��ͬ��string
            mp[t].insert(s);              // ������ĸ��Ϊkey ��Ӧ��anagrams����multiset��
        }
        vector<vector<string>> anagrams;  // ÿһ��multiset����һ��vector
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
                map[sort_s]=num_type;              // ÿ����һ��anagram�ĵ�һ��string�ʹ������ս��
                vec.push_back(strs[i]);
                vecvec.push_back(vec);
                vec.clear();
                num_type++;                        // ��vecvec�е�λ��
            }
            else
                insert(vecvec[map[sort_s]],strs[i]);   // �������ս���в�����ͬanagram������string
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