class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        partitionHelper(res, s, part, 0);
        return res;
    }
    
    void partitionHelper(vector<vector<string>>& res, string& s, vector<string>& part, int k) {
        if(k == s.size()) {
            res.push_back(part);
        }
        for(int i = k; i < s.size(); i++) {
            if(isPalindrome(s.substr(k, i + 1 - k))) {
                part.push_back(s.substr(k, i + 1 - k));
                partitionHelper(res, s, part, i + 1);
                part.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }else {
                l++;
                r--;
            }
        }
        return true;
    }
};
