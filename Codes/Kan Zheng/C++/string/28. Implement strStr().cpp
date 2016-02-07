class Solution {
public:
    int strStr(string haystack, string needle) {
        /* Wrong!  EX: "mississippi"     "issip"
        int index_hs,index_nd;
        if(needle.empty())
            return 0;
        for(index_hs=0,index_nd=0;index_hs<haystack.length();index_hs++)
        {
            if(haystack[index_hs]==needle[index_nd])
            {
                if(index_nd==needle.length()-1)
                    return index_hs-index_nd;
                index_nd++;
            }
            else
                index_nd=0;
        }
        return -1;
        */
        int index_hs,index_nd,index_hs_0;
        if(needle.empty())
            return 0;
        for(index_hs=0,index_nd=0,index_hs_0=0;index_hs<haystack.length();index_hs++)
        {
            if(haystack[index_hs]==needle[index_nd])
            {
                if(index_nd==0)
                    index_hs_0 = index_hs;
                if(index_nd==needle.length()-1)
                    return index_hs-index_nd;
                index_nd++;
            }
            else if(index_hs_0<index_hs)
            {
                index_hs = index_hs_0;
                index_hs_0 = index_hs+1;
                index_nd=0;
            }
            else
                index_nd=0;
        }
        return -1;
    }
};