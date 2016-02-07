class Solution {
public:
    int romanToInt(string s) {
        char level=s[0];
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            if(convert(level)<convert(s[i]))
                sum += convert(s[i])-2*convert(level);
            else{
                sum += convert(s[i]);
                level = s[i];
            }
        }
        return sum;
    }
    int convert(char r)
    {
        switch(r){
        case 'I': return 1;break;
        case 'V': return 5;break;
        case 'X': return 10;break;
        case 'L': return 50;break;
        case 'C': return 100;break;
        case 'D': return 500;break;
        case 'M': return 1000;break;
        default:return 0;break;
        }
    }
};