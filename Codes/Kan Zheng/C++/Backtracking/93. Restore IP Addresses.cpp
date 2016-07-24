class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string addr;
        restoreIpAddressesHelper(res, addr, s, 1, 0);
        return res;
    }
    
    void restoreIpAddressesHelper(vector<string>& res, string& addr, string& s, int num, int index) {
        if(index == s.size()) {
            return;
        }
        if(num == 4) {
            if(isAddr(s.substr(index))) {
                addr += s.substr(index);
                res.push_back(addr);
                addr.erase(addr.size() - s.substr(index).size(), s.substr(index).size());
            }
            return;
        }
        for(int i = index; i < s.size(); i++) {
            string subaddr = s.substr(index, i - index + 1);
            if(isAddr(subaddr)) {
                addr += subaddr + ".";
                //cout << "addr is " << addr << "  num is " << num << endl;
                restoreIpAddressesHelper(res, addr, s, num + 1, i + 1);
                addr.pop_back();
                addr.erase(addr.size() - subaddr.size(), subaddr.size());
            }
        }
    }
    
    bool isAddr(string s) {
        if(s.size() > 3 || (s.size() > 1 && s[0] == '0')) {
            return false;
        }
        int ip = 0;
        for(int i = 0; i < s.size(); i++) {
            ip = ip * 10 + s[i] - '0';
        }
        return ip < 256;
    }
};
