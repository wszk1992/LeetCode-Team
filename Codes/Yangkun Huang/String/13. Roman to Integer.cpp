    int romanToInt(string s) {
        int left_result=0, right_result=0,temp_result=0;
        // for(auto c:s)
        for(string::reverse_iterator ri=s.rbegin();ri<s.rend();ri++)
        {
            if(*ri=='I')
            left_result= 1;
            if(*ri=='V')
            left_result= 5;
            if(*ri=='X')
            left_result= 10;
            if(*ri=='L')
            left_result= 50;
            if(*ri=='C')
            left_result=100;
            if(*ri=='D')
            left_result=500;
            if(*ri=='M')
            left_result=1000;
            if(left_result<temp_result)
            right_result=right_result-left_result;
            else
            right_result=right_result+left_result;
            temp_result=left_result;
        }
        return right_result;
    }
