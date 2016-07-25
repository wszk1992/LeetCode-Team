    // use '++'
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        for(int i=1;i<=k;i++)
            combination.push_back(i);
        combinationSum3(res, combination, 0, n);
        return res;
    }
    
    void combinationSum3(vector<vector<int>> &res, vector<int> &combination, int pos, int n){
        pos ? combination[pos]=combination[pos-1]+1 : pos;
        if(pos==combination.size()-1){
            while(combination[pos]<=9){
                if(!(n-combination[pos])){
                    res.push_back(combination);
                    break;
                }
                else
                    combination[pos]++;
            }
            return ;
        }
        while(combination[pos]<=9-(combination.size()-pos-1)){
            combinationSum3(res, combination, pos+1, n-combination[pos]);
            combination[pos]++;
        }
    }
    
    // use 'push_back'
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum3(res, combination, 1, 1, k, n);
        return res;
    }
    
    void combinationSum3(vector<vector<int>> &res, vector<int> &combination, int pos, int last, int k, int n){
        if(pos==k){
            if(n>combination.back() && n<=9){
                combination.push_back(n);
                res.push_back(combination);
                combination.pop_back();
            }
            return ;
        }
        for(int i= last;i<=9-k+pos;i++){
            combination.push_back(i);
            combinationSum3(res, combination, pos+1, i+1, k, n-combination[pos-1]);
            combination.pop_back();
        }
    }
