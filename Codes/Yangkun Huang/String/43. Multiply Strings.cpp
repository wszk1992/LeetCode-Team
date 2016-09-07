    string multiply(string num1, string num2) {
        // init with 0 (number 0, not char '0')
        string sum(num1.size() + num2.size(), 0);
    
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1]) + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                sum[i + j + 1] = tmp - carry * 10;
            }
            sum[i] += carry;
        }
        
        // find number 0('\0'), not '0'
        if (sum.find_first_not_of('\0') != sum.npos) {
            // add '0' before output
            for(int i = sum.find_first_not_of('\0') ;i<sum.size();i++)
                sum[i]+='0';
            return sum.substr(sum.find_first_not_of('\0') );
        }
        return "0";
    }
