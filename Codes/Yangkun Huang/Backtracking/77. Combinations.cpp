    // solution 1 use push_back
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp;  // recursive solution is hardly initiating value
        combine(res,temp,0,0,n,k);
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){  // wrong thought: use ++ rather than push_back, since ++ is hard to reset
            temp.push_back(i+1);     // separate factors: loop controls one, and recurstion controls the other
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
        }
    }
    
    // solution 2 use '++'
    // must be clear with the recursive structure
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp(k,1);  // difference shows here
        combine(res,temp,0,n);
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int pos,int n){
        pos ? temp[pos]=temp[pos-1]+1 : pos;  // deal with position [0]
        if(pos==temp.size()-1){
            while(temp[pos]<=n){
                res.push_back(temp);
                temp[pos]++;
            }
            return;
        }
        while(temp[pos]<=n){
            combine(res, temp, pos+1, n);
            temp[pos]++;
        }
    }
