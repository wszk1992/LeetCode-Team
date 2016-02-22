    string fractionToDecimal(int64_t n, int64_t d) {
        if(n==0)
        return "0";
        string result;
        if(n<0^d<0)
        {
            result+="-";//'-'
            n=abs(n),d=abs(d);
        }
        result+=to_string(n/d);
        if(n%d==0)
        return result;
        result+='.';
        unordered_map<int,int> m;
        for(long remainder=n%d;remainder;remainder%=d)
        {
            if(m.count(remainder))
            {
                result.insert(m[remainder],1,'(');
                result+=')';
                break;
            }
            m[remainder]=result.size();
            remainder*=10;
            result+=to_string(remainder/d);
        }
        return result;
}