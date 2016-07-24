class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        if(n == 0) {
            return res;
        }
        generateParenthesisHelper(res, n, s, 0, 0);
        return res;
    }
    
    void generateParenthesisHelper(vector<string>& res, int n, string s, int numL, int numR) {
        if(numL == n && numR == n) {
            res.push_back(s);
        }else if(numL == n) {
            s.push_back(')');
            generateParenthesisHelper(res, n, s, numL, numR + 1);
            s.pop_back();
        }else if(numL == numR) {
            s.push_back('(');
            generateParenthesisHelper(res, n, s, numL + 1, numR);
            s.pop_back();
        }else {
            s.push_back(')');
            generateParenthesisHelper(res, n, s, numL, numR + 1);
            s.pop_back();
            s.push_back('(');
            generateParenthesisHelper(res, n, s, numL + 1, numR);
            s.pop_back();
        }
    }
};
