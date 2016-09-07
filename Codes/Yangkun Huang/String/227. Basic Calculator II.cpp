    // since there is no parenthesis, no need to use stack
    // if meets a lower op, add temp result to sum; if meets a upper op, calculate temp result
    int calculate(string s) {
        int sum = 0; 
        if(s.size() < 1) 
            return sum; 
        int i = 0; 
        int last = 0, last_result = 1;  
        char last_operator = '+'; //remember the last operator
        int sign = 1; 
        while(i <= s.size()){
            if(s[i] == ' '){++i; continue;}
            if(s[i] == '+' || s[i] == '-' || !s[i]){ //Check the end of the string
                sum += last_result * sign;
                sign = s[i++] == '+' ? 1 : -1; 
                last_result = 1;
                last_operator = '+'; 
            }
            else if(s[i] == '/' || s[i] == '*'){
                last_operator = s[i];
                ++i; 
            }
            if(isdigit(s[i])){
                last = 0; 
                while(i < s.size() && isdigit(s[i]))
                    last =  last * 10 + s[i++] - '0';
                if(last_operator == '*') 
                    last_result *= last;
                else if(last_operator == '/') 
                    last_result /= last;
                else  
                    last_result = last; 
            }
        }
        return sum; 
    }
