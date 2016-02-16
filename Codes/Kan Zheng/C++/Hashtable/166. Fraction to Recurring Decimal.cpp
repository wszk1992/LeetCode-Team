class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s;
        unordered_map<int,int> map;
        long n=numerator;
        long d=denominator;
        long fac,rem;
        int i=0;
        bool isneg=false;
        if(denominator==0)
            return s;
        if(n<0)
            {n=-n;isneg=!isneg;}
        if(d<0&&(n!=0))
            {d=-d;isneg=!isneg;}
        if(isneg){s="-";}
        while(++i)
        {
            fac=n/d;
            rem=n%d;
            if(fac==0)
                s.push_back('0');
            else
                //to_string can be improved
                s.append(to_string(fac));
            if(rem==0)
                return s;
            else
                n=rem*10;
            if(map.find(rem)!=map.end())
            {
                int j=0;
                while(s[++j]!='.');
                s.insert(s.begin()+j+map[rem],'(');
                s.push_back(')');
                break;
            }
            else
                map[rem]=i;
            if(i==1)
                s.push_back('.');
        }
        
            
    }
};