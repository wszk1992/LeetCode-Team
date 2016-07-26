    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()>3 && s.size()<13){
            string ss;
            restoreIpAddresses(res, s, ss, 0, 4);
        }
        return res;
    }
    
    void restoreIpAddresses(vector<string> &res, string s, string ss, int pos, int count){
            if(count==1){
                if(s.size()-pos>0 && s.size()-pos<4){
                for(int j=s.size()-1, k=1, to_int=0;j>=pos;j--, k*=10){
                    to_int+=(s[j]-'0')*k;
                    if(to_int>255)
                        return ;
                }
                if(s[pos]=='0' && s.size()-pos>1)
                    return ;
                ss+=s.substr(pos, s.size()-pos);
                res.push_back(ss);}
                return ;
            }
            for(int i=0;i<3 && pos+i<s.size();i++){ // each of four parts could be 1 to 3 digits
                string tmp=ss;
                if(i==2){
                    int to_int=0;
                    for(int j=i, k=1;j>=0;j--, k*=10)
                        to_int+=(s[pos+j]-'0')*k;
                    if(to_int>255)
                        continue;
                }
                ss+=(s.substr(pos, i+1)+'.');
                restoreIpAddresses(res, s, ss, pos+i+1, count-1);
                ss=tmp;
                if(s[pos]=='0')
                    break;
            }
    }
