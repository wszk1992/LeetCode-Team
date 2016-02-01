// method 1

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
// method 2
// inline int map(const char c) {
// 	switch (c) {
// 	case 'I': return 1;
// 	case 'V': return 5;
// 	case 'X': return 10;
// 	case 'L': return 50;
// 	case 'C': return 100;
// 	case 'D': return 500;
// 	case 'M': return 1000;
// 	default: return 0;
// 	}
// }
// int romanToInt(const string& s) {
// 	int result = 0;
// 	for (size_t i = 0; i < s.size(); i++) {
// 		if (i > 0 && map(s[i]) > map(s[i - 1])) 
// 		{
// 			result += (map(s[i]) - 2 * map(s[i - 1]));
// 		}
// 		else 
// 		{
// 				result += map(s[i]);
// 		}
// 	}
// 	return result;
// }
