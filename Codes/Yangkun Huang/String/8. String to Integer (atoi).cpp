    int myAtoi(string str) {
        int num = 0, sign = 1;
    	const int n = str.length();
    	int i = 0;
    	while (str[i] == ' ' && i < n) // skip " "
    	    i++;
    	if (str[i] == '+')  // determine the sign
    		i++;
    	else if (str[i] == '-') {
    		sign = -1;
    		i++;
    	}
    	while(str[i] >= '0' && str[i] <= '9'){
    	    if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) 
    			return sign == -1 ? INT_MIN : INT_MAX;
    		num = num * 10 + str[i++] - '0';
    	}
    	return num * sign;
    }
