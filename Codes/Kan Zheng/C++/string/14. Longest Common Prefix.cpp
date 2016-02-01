class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string prefix=strs[0];
        int prefix_length = prefix.length();
        for(int i=1;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].length()&&j<prefix_length;j++)
            {
                //compare every string with prefix, find common prefix
                if(strs[i][j]!=prefix[j])
                {
                    prefix.erase(prefix.begin()+j,prefix.end());
                    prefix_length = j;
                    break;
                }
            }
            if(prefix_length>strs[i].length())
                prefix.erase(prefix.begin()+strs[i].length(),prefix.end());
        }
        return prefix;
        
    }
};