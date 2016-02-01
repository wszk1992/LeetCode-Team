class Solution {
public:
    bool isValid(string s) {
        string buffer;
        for(int i=0;i<s.length();i++)
        {
            if(isLeft(s[i])==-1)                // if there are other chars  return false
                return false;
            else if (isLeft(s[i]))                // if the char is left bracket, insert the char into buffer
                buffer.push_back(s[i]);
            else {
                if(isPair(buffer[buffer.length()-1],s[i]))   //if the char is right bracket, check if it's a pair
                    buffer.pop_back();                          //with the end char of buffer
                else
                    return false;
            }
        }
        if(buffer.empty())
            return true;
        else
            return false;
        
    }
    
    //check one character if it belongs to ([{ or }]) or other char
    int isLeft(char c)
    {
        if(c=='('||c=='['||c=='{')
            return 1;
        else if(c==')'||c==']'||c=='}')
            return 0;
        else
            return -1;
    }
    
    //check two chars if they are a pair
    bool isPair(char a, char b)
    {
        if(a=='('&&b==')')
            return true;
        else if (a=='['&&b==']')
            return true;
        else if(a=='{'&&b=='}')
            return true;
        else
            return false;
    }
};