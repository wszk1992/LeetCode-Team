class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int cur_len=0;
        for(int i=0;i<s.length();i++)
        {
            int found = find(s.substr(i-cur_len,cur_len),s[i]);
            if(found==-1)
                cur_len++;
            else
            {
                cur_len -= found;
            }
            max_len = cur_len > max_len ? cur_len : max_len;
        }
        return max_len;
    }
    //find c in s, if found, return position,otherwise return -1;
    int find(string s,char c)
    {
        for(int i=0;i<s.length();i++)
            if(s[i]==c)
                return i;
        return -1;
    }
    //we can also use hashmap
};