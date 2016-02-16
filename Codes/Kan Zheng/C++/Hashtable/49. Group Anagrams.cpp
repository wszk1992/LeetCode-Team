class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> vecvec;
        vector<string> vec;
        string sort_s;
        int num_type=0;
        //make a hashmap to store the group string and group number
        for(int i=0;i<strs.size();i++)
        {
            sort_s=strs[i];
            sort(sort_s.begin(),sort_s.end());
            if(map.find(sort_s)==map.end())
            {
                map[sort_s]=num_type;
                vec.push_back(strs[i]);
                vecvec.push_back(vec);
                vec.clear();
                num_type++;
            }
            else
            {
                insert(vecvec[map[sort_s]],strs[i]);
            }
        }
        return vecvec;
    }
    
    void insert(vector<string>& str,string s)
    {
        int i;
        for(i=0;i<str.size();i++)
        {
            if(s.compare(str[i])<0)
            {
                str.insert(str.begin()+i,s);
                break;
            }
        }
        if(i==str.size())
            str.push_back(s);
    }
};