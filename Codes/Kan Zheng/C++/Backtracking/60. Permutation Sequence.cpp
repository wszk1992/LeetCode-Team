class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        string res;
        for(int i = 0; i < n; i++) {
            s += (char)(i + '1');
        }
        //cout << s << endl;
        k -= 1;
        n -= 1;
        while(n) {
            int m = factorial(n); 
            res += s[k / m];
            s.erase(k / m, 1);
            k %= m;
            n--;
            //cout << s << endl;
            //cout << res << endl;
        }
        res += s;
        return res;
    }
    
    int factorial(int n) {
        int res = 1;
        while(n) {
            res *= n--;
        }
        return res;
    }
};
