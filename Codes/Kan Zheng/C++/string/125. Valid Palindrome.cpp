class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.empty())
            return true;
        int index1=0;
        int index2=s.length()-1;
        
        for(;index1<index2;)
        {
            if(!isAlphanumeric(s[index1]))
                index1++;
            else if(!isAlphanumeric(s[index2]))
                index2--;
            else if(!isSameChar(s[index1],s[index2]))
                return false;
            else{
                index1++;
                index2--;
            }
        }
        return true;
    }
    bool isSameChar(char a, char b)
    {
        std::locale loc;
        if(a==b)
            return true;
        else if(((a>='A'&&a<='Z')||(a>='a'&&a<='z'))&&((b>='A'&&b<='Z')||(b>='a'&&b<='z'))&&abs(a-b)=='a'-'A')
            return true;
        else
            return false;
            
    }
    bool isAlphanumeric(char a)
    {
        if((a>='0'&&a<='9')||(a>='A'&&a<='Z')||(a>='a'&&a<='z'))
            return true;
        else
            return false;
    }
};